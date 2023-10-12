#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

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
	char	*newbuf;
	int		len;

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

int ft_putstr_fd(char *str, int fd)
{
	return write(fd, str, strlen(str));
}

typedef struct 
{
	int id;
	char *rb;
	char *wb;
}t_client;

typedef enum
{
	CLIENT_NUM = 3000,
	BUFFER_LEN = 100000,
}t_all;

void init(t_client *clients)
{
	for (int fd = 0; fd <= CLIENT_NUM; fd++)
	{
		clients[fd].id = -1;
		clients[fd].rb = NULL;
		clients[fd].wb = NULL;
	}
}

void close_and_exit_all(t_client *client, int sockfd)
{
	for(int fd = 0;fd < CLIENT_NUM; fd++)
	{
		if (client[fd].id != -1)
			close(fd);
	}
	close(sockfd);
	ft_putstr_fd("fatal error\n", 2);
	exit(1);
}

void add_all_rb(t_client *client, int fd_max, char *msg)
{
	for (int fd = 0; fd <= fd_max; fd++)
	{
		if (client[fd].id != -1)
		{
			str_join(client[fd].rb, msg);
		}
		
	}
	
}

void add_wb(t_client *client, int fd, fd_set *w_fd_set, int sockfd)
{
	int err;

	err = extract_message(&client[fd].rb, &client[fd].wb);
	if (0 < err)
	{
		FD_SET(fd, w_fd_set);
	}
	else if (err == -1)
	{
		close_and_exit_all(client, sockfd);
	}
}

void patal_write(int send_len, char **wb)
{
	char *tmp = NULL;
	
	str_join(tmp, (*wb) + send_len);
	free(*wb);
	*wb = tmp;
}

int main(int argc, char **argv) {
	if (argc != 2)
	{
		ft_putstr_fd("wrong number of arguments\n", 2);
		return 1;
	}

	int sockfd, connfd, len, port;
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		ft_putstr_fd("fatal error\n", 2);
		exit(0); 
	} 
	bzero(&servaddr, sizeof(servaddr)); 
	port = atoi(argv[1]);
	if (port == -1)
	{
		close(sockfd);
		ft_putstr_fd("fatal error\n", 2);
		return 1;
	}
	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		ft_putstr_fd("fatal error\n", 2);
		close(sockfd);
		exit(0); 
	} 
	if (listen(sockfd, 10) != 0) {
		ft_putstr_fd("fatal error\n", 2);
		close(sockfd);
		exit(0); 
	}
	len = sizeof(cli);
	
	int fd_max = sockfd;
	int id = 0;
	int error = 0;

	t_client clients[CLIENT_NUM];
	init(clients);

	fd_set w_fd_set;
	fd_set w_fd_copy_set;
	fd_set r_fd_set;
	fd_set r_fd_copy_set;

	FD_ZERO(&w_fd_set);
	FD_ZERO(&r_fd_set);
	FD_SET(sockfd, &r_fd_set);

	char msg[BUFFER_LEN];
	int send_len;


	while (42)
	{
		r_fd_copy_set = r_fd_set;
		w_fd_copy_set = w_fd_set;

		select(fd_max + 1, &r_fd_copy_set, &w_fd_copy_set, NULL, NULL);
		
		for(int fd = 0; fd <= fd_max; fd++)
		{
			if (FD_ISSET(fd, &r_fd_copy_set))
			{
				// accept
				if (fd == sockfd)
				{
					connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t *)&len);
					if (connfd != -1)
					{
						sprintf(msg, "serv: client %d just arrived\n", id);
						add_all_rb(clients, fd_max, msg);
						clients[fd].id = id;
						printf("come in id: %d\n", id);
						id++;
						FD_SET(connfd, &r_fd_set);
						if (fd_max < connfd)
							fd_max = connfd;
						printf("come in clients[%d].id : %d\n", fd, clients[fd].id);
					}

				}
				else
				{
					//r_buf
					error = recv(fd, msg, BUFFER_LEN, 0);
					if (!error)
					{
						printf("left clients[%d].id : %d\n", fd, clients[fd].id);
						sprintf(msg, "serv: client %d just left\n", clients[fd].id);
						add_all_rb(clients, fd_max, msg);
						clients[fd].id = -1;
						free(clients[fd].rb);
						free(clients[fd].wb);
						clients[fd].rb = NULL;
						clients[fd].wb = NULL;
						FD_CLR(fd, &r_fd_set);
						FD_CLR(fd, &w_fd_set);
					}	
					else if (0 < error)
					{
						printf("recv clients[%d].id : %d\n", fd, clients[fd].id);
						add_all_rb(clients, fd_max, msg);

					}
					else
						close_and_exit_all(clients, sockfd);
				}
			}
			// check wb
			if (FD_ISSET(fd, &w_fd_copy_set))
			{
				*msg = 0;
				send_len = strlen(clients[fd].wb);
				printf("send clients : %d\n", clients[fd].id);
				error = send(fd, clients[fd].wb, send_len, 0);
				if (error != send_len)
				{
					patal_write(error, &clients[fd].wb); 
				}
				else
				{
					FD_CLR(fd, &w_fd_set);
				}

			}
			// is send buf
			add_wb(clients, fd, &w_fd_set, sockfd);
		}
	}

}
