#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_client
{
	int fd;
	char *rb;
	char *wb;
} t_client;

typedef enum e_all
{
	LEFT,
	ARRIVE,
	MASSAGE,
	CLIENT_ENMPTY = -1,
	CLIENT_NUM = 10000,
	BUF_LEN = 300000,
} t_all;

void init_client(t_client *client)
{
	if (!client)
		return ;
	if (client->fd != -1)
		close(client->fd);
	client->fd = -1;
	free(client->rb);
	free(client->wb);
	client->rb = 0;
	client->wb = 0;
}

void init_all_client(t_client *clients)
{
	static bool is_first = true;

	if (is_first)
	{
		bzero(clients, sizeof(t_client) * CLIENT_NUM);
		for (int i = 0; i < CLIENT_NUM; i++)
			clients[i].fd = -1;
		is_first = false;
	}
	else
	{
		for (int i = 0; i < CLIENT_NUM; i++)
			init_client(&clients[i]);
	}
}

void exit_all(t_client *clients, int sockfd)
{
	init_all_client(clients);
	exit(0);
}

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

void exit_error(char *msg, int sockfd)
{
	if (sockfd != -1)
		close(sockfd);
	write(2, msg, strlen(msg));
	exit(1);
}

int main()
{
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		exit_error("socket creation failed...\n", 0);
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(8081);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		exit_error("socket bind failed...\n", sockfd);

	if (listen(sockfd, 10) != 0)
		exit_error("cannot listen\n", sockfd);
	len = sizeof(cli);

	t_client clients[CLIENT_NUM];
	init_all_client(clients);

	fd_set w_fd_set;
	fd_set r_fd_set;
	fd_set w_fd_copy_set;
	fd_set r_fd_copy_set;

	int fd_max = sockfd;
	int id = 0;

	char *tmp[BUF_LEN];

	FD_ZERO(&w_fd_set);
	FD_ZERO(&r_fd_set);
	FD_SET(&r_fd_set);
	
	while (42)
	{
		w_fd_copy_set = w_fd_set;
		r_fd_copy_set = r_fd_set;
		if (select(fd_max+1, &r_fd_copy_set, &w_fd_copy_set, NULL, NULL))
			exit_all(clients, sockfd);

		for (int fd = 0; fd <= fd_max; fd++)
		{
			if (clients[fd].wb)
				FD_SET(&w_fd_set);

			if(FD_ISSET(fd, &r_fd_copy_set))
			{
				if(fd == sockfd)
				{
					connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
					if (connfd >= 0)
					{
						sprintf(tmp, "arrive : %d\n", connfd);
						save_rb_join(clients, connfd, sockfd, tmp);
						clients[connfd].fd = id;
						if (fd_max < connfd)
							fd_max = connfd;
						FD_SET(&r_fd_set);
						id++;
					}
				}
				else
				{
					if (0 < recv(fd, tmp, BUF_LEN - 1, 0))
						save_rb_join(clients, fd, sockfd, tmp);
					else
					{
						sprintf(tmp, "left : %d\n", connfd);
						save_rb_join(clients, fd, sockfd, tmp);//
						init_client(fd);
						FD_CLR(fd, &r_fd_set);
						FD_CLR(fd, &w_fd_set);
						close(fd);
					}
				}
			}

			if (clients[fd].id != -1 && clients[fd].rb)
			{
				save_wb_join(clinents, fd, sockfd);//
				FD_SET(fd, &w_fd_set);
			}

			if(FD_ISSET(fd, &w_fd_copy_set))
			{
				send_all(fd, clients);//
				FD_CLR(fd, &w_fd_copy_set);
			}
		}
	}
}