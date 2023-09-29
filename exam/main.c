#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
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

typedef enum
{
	NO,
	YES,
	BUFLEN = 100000,
	CLIENT_NUM = 1000,
	ALLIVER = 0,
	LEFT,
	ODINALY,
} t_enum;

typedef struct
{
	int status;
	int id;
	char *str;
} t_node;

void ft_stderr(char *str)
{
	write(2, str, strlen(str));
	write(2, "\n", 1);
}

void exit_all(t_node *client, int socketfd)
{
	for (int fd = 0; fd < CLIENT_NUM; fd++)
	{
		if (!client[fd].status)
			continue;
		free(client[fd].str);
		close(fd);
	}
	ft_stderr("fatal");
	close(socketfd);
}

void join_msg(t_node *clients, int fd_max, int exception_fd, char *send_msg, int flag, int sockfd)
{
	char add[64] = {
			0,
	};

	for (int fd = 0; fd < fd_max; fd++)
	{
		if (exception_fd == fd && !(clients[fd].status))
			continue;
		if (flag == ALLIVER)
		{
			sprintf(add, "alliver %d \n ", exception_fd);
			if (!str_join(clients[fd].str, add))
			{
				exit_all(clients, sockfd);
			}
		}
		else if (flag == ODINALY)
		{
			sprintf(add, "client %d : ", exception_fd);
			if (!str_join(clients[fd].str, add) || !str_join(clients[fd].str, send_msg))
			{
				exit_all(clients, sockfd);
			}
		}
		else
		{
			sprintf(add, "left %d \n ", exception_fd);
			if (!str_join(clients[fd].str, add))
			{
				exit_all(clients, sockfd);
			}
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_stderr("wrong argc");
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		ft_stderr("socket creation failed...\n");
		exit(0);
	}
	else
		ft_stderr("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1

	int port;

	if (argc == 1)
		port = 8081;
	else
		port = atoi(argv[1]);
	servaddr.sin_port = htons(port);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
	{
		ft_stderr("socket bind failed...\n");
		close(sockfd);
		exit(0);
	}
	else
		ft_stderr("Socket successfully binded..\n");
	if (listen(sockfd, 1000) != 0)
	{
		ft_stderr("cannot listen\n");
		close(sockfd);
		exit(0);
	}
	len = sizeof(cli);
	t_node clients[1000];
	bzero(clients, sizeof(t_node) * 1000);

	fd_set origin_write_set;
	fd_set origin_read_set;
	fd_set copy_write_set;
	fd_set copy_read_set;

	FD_ZERO(&origin_read_set);
	FD_ZERO(&origin_write_set);
	FD_SET(sockfd, &origin_read_set);

	int fd_max = sockfd;
	char add[BUFLEN] = {
			0,
	};
	int id = 0;

	while (42)
	{
		FD_COPY(&origin_read_set, &copy_read_set);
		// copy_read_set = origin_read_set;

		fprintf(stderr, "origin_read_set : %d\n", origin_read_set);
		copy_write_set = origin_write_set;
		if (select(fd_max + 1, &copy_read_set, &copy_write_set, NULL, NULL) == -1)
		{
			exit_all(clients, sockfd);
		}
		// fprintf(stderr, "fprintf : %d\n", fd_max);
		for (int fd = 0; fd <= fd_max; fd++)
		{
			fprintf(stderr, "fd_max: %d\n", fd_max);
			if (FD_ISSET(fd, &copy_read_set))
			{
				fprintf(stderr, "test: %d\n", fd);
				if (fd == sockfd)
				{
					connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t *)&len);
					fprintf(stderr, "connect fd : %d\n", connfd);

					if (connfd < 0)
						continue;

					FD_SET(connfd, &origin_read_set);
					FD_SET(connfd, &origin_write_set);

					if (fd_max < connfd)
						fd_max = connfd;

					clients[connfd].status = YES;
					clients[connfd].id = id;
					clients[connfd].str = NULL;
					join_msg(clients, fd_max, connfd, NULL, ALLIVER, sockfd);
					id++;
				}
				else
				{
					bzero(add, BUFLEN);
					if (1 > recv(fd, add, BUFLEN, 0))
					{
						join_msg(clients, fd_max, fd, NULL, LEFT, sockfd);
						clients[fd].status = NO;
						clients[fd].id = 0;
						free(clients[fd].str);
						clients[fd].str = NULL;
						FD_CLR(fd, &origin_read_set);
						FD_CLR(fd, &origin_write_set);
						close(fd);
						continue;
					}
					join_msg(clients, fd_max, fd, add, ODINALY, sockfd);
				}
			}
			if (FD_ISSET(fd, &copy_write_set))
			{
				if (!clients[fd].str)
					break;
				bzero(add, BUFLEN);
				char *write_msg;
				if (extract_message(&clients[fd].str, &write_msg) == -1)
				{
					exit_all(clients, sockfd);
				}
				write(fd, write_msg, strlen(write_msg));
			}
		}
	}
}
