#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

int extract_message(char **buf, char **msg)
{
  char *newbuf;
  int i;

  *msg = 0;
  if (*buf == 0)
    return (0);
  i = 0;
  while ((*buf)[i])
  {
    if ((*buf)[i] == '\n')
    {
      newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
      if (newbuf == 0)
        return (-1);
      strcpy(newbuf, *buf + i + 1);
      *msg = *buf;
      (*msg)[i + 1] = 0;
      *buf = newbuf;
      return (1);
    }
    i++;
  }
  return (0);
}

char *str_join(char *buf, char *add)
{
  char *newbuf;
  int len;

  if (buf == 0)
    len = 0;
  else
    len = strlen(buf);
  newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
  if (newbuf == 0)
    return (0);
  newbuf[0] = 0;
  if (buf != 0)
    strcat(newbuf, buf);
  free(buf);
  strcat(newbuf, add);
  return (newbuf);
}

typedef struct
{
  int id;
  char *rb;
  char *wb;
} t_client;

typedef enum
{
  CLIENT_NUM = 3000,
  BUF_LEN = 100000,
} t_all;

void init(t_client *client)
{
  for (int fd = 0; fd < CLIENT_NUM; fd++)
  {
    client[fd].id = -1;
    client[fd].rb = NULL;
    client[fd].wb = NULL;
  }
}

int ft_putstr_fd(int fd, char *str)
{
  return (write(fd, str, strlen(str)));
}

void add_(int connfd, t_client *client, fd_set *r_fd_set, fd_set *w_fd_set, int *id, int fd_max)
{
  char buf[30];
  sprintf(buf, "serv: client %d arrived\n", *id);
  for (int fd = 0; fd <= fd_max; fd++)
  {
    if (fd != connfd && client[fd].id != -1)
    {
      client[fd].wb = str_join(client[fd].wb, buf);
    }
    FD_SET(fd, w_fd_set);
  }
  client[connfd].id = *id;
  FD_SET(connfd, r_fd_set);
  (*id)++;
}

int recv_from_(int target_fd, t_client *client, fd_set *w_fd_set, fd_set *r_fd_set, int fd_max, char *prifix_msg)
{
  char r_tmp_buf[BUF_LEN] = {0};
  char *w_tmp_buf = NULL;

  // success recv
  if (0 < recv(target_fd, r_tmp_buf, BUF_LEN, 0))
  {
    sprintf(prifix_msg, "client %d: ", client[target_fd].id);
    client[target_fd].rb = str_join(client[target_fd].rb, prifix_msg);
    client[target_fd].rb = str_join(client[target_fd].rb, r_tmp_buf);
    if (-1 == extract_message(&client[target_fd].rb, &w_tmp_buf))
      return 0;
    for (int fd = 0; fd <= fd_max; fd++)
    {
      if (fd != target_fd && client[fd].id != -1)
      {
        client[fd].wb = str_join(client[fd].wb, w_tmp_buf);
        FD_SET(fd, w_fd_set);
      }
    }
  }
  else
  {
    for (int fd = 0; fd <= fd_max; fd++)
    {
      sprintf(prifix_msg, "server: client %d just left\n", client[fd].id);
      if (fd != target_fd && client[fd].id != -1)
      {
        client[fd].wb = str_join(client[fd].wb, prifix_msg);
        FD_SET(fd, w_fd_set);
      }
    }
    client[target_fd].id = -1;
    free(client[target_fd].wb);
    free(client[target_fd].rb);
    client[target_fd].wb = NULL;
    client[target_fd].rb = NULL;
    FD_CLR(target_fd, w_fd_set);
    FD_CLR(target_fd, r_fd_set);
    close(target_fd);
  }
  free(w_tmp_buf);
  return 1;
}

void close_(t_client *client, int fd_max)
{
  for (int fd = 3; fd <= fd_max; fd++)
  {
    if (client[fd].id != -1)
    {
      free(client[fd].wb);
      free(client[fd].rb);
      close(fd);
    }
  }
  close(3);
}

void send_to(t_client *client, int fd_max, fd_set *w_fd_set)
{
  char *str = NULL;
  size_t len;

  for (int fd = 0; fd <= fd_max; fd++)
  {
    if (!client[fd].wb)
    {
      FD_CLR(fd, w_fd_set);
      continue;
    }
    if (client[fd].id != -1)
    {
      len = send(fd, client[fd].wb, strlen(client[fd].wb), 0);
      if (strlen(client[fd].wb) != len)
      {
        str = str_join(str, client[fd].wb + len);
      }
      free(client[fd].wb);
      client[fd].wb = str;
    }
  }
}

int main(int argc, char **argv)
{
  int sockfd, connfd, len, port;
  struct sockaddr_in servaddr, cli;

  if (argc != 2)
  {
    ft_putstr_fd(2, "Wrong number of arguments\n");
    exit(1);
  }
  port = atoi(argv[1]);
  if (0 > port)
  {
    ft_putstr_fd(2, "Wrong number of arguments\n");
    exit(1);
  }
  // socket create and verification
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)
  {
    ft_putstr_fd(2, "Fatal error\n");
    exit(1);
  }
  bzero(&servaddr, sizeof(servaddr));

  // assign IP, PORT
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
  servaddr.sin_port = htons(port);
  int test = 0;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &test, 1);

  // Binding newly created socket to given IP and verification
  if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
  {
    close(sockfd);
    ft_putstr_fd(2, "Fatal error\n");
    exit(1);
  }
  if (listen(sockfd, 10) != 0)
  {
    close(sockfd);
    ft_putstr_fd(2, "Fatal error\n");
    exit(1);
  }
  len = sizeof(cli);

  int id = 0;
  int fd_max = sockfd;
  char prifix_msg[30] = {0};

  t_client client[CLIENT_NUM];
  init(client);

  fd_set w_fd_set;
  fd_set r_fd_set;
  fd_set w_copy_fd_set;
  fd_set r_copy_fd_set;

  FD_ZERO(&w_fd_set);
  FD_ZERO(&r_fd_set);
  FD_SET(sockfd, &r_fd_set);


  while (42)
  {
    w_copy_fd_set = w_fd_set;
    r_copy_fd_set = r_fd_set;
    select(fd_max + 1, &r_copy_fd_set, &w_copy_fd_set, NULL, NULL);

    for (int fd = 3; fd <= fd_max; fd++)
    {
      if (FD_ISSET(fd, &r_copy_fd_set))
      {
        if (fd == sockfd)
        {
          connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t *)&len);
          add_(connfd, client, &r_fd_set, &w_fd_set, &id, fd_max);
          if (connfd > fd_max)
          {
            fd_max = connfd;
          }
        }
        else
        {
          if (!recv_from_(fd, client, &w_fd_set, &r_fd_set, fd_max, prifix_msg))
          {
            ft_putstr_fd(2, "Fatal error\n");
            close_(client, fd_max);
            exit(1);
          }
        }
      }
      if (FD_ISSET(fd, &w_copy_fd_set))
      {
        send_to(client, fd_max, &w_fd_set);
      }
    }
  }
}