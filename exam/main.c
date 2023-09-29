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

void ft_printf(char *str)
{
	write(1, str, strlen(str));
	exit(1);
}

typedef struct
{
	int id;
	char *rb;
	char *wb;
} t_node;

typedef enum
{
	CLIENT_lEN = 1000,
	BUFFLEN = 100000,
	LEFT = 0,
	ALLIVER = 0,
	ODINALY,
} t_enum_all;

void exit_error()
{

}

int init_client(t_node *client, int fd)
{
	client[fd].id = -1;
	if (client[fd].rb != 0)
		free(client[fd].rb);
	if (client[fd].wb != 0)
		free(client[fd].wb);
	client[fd].rb = 0;
	client[fd].wb = 0;
	return (0);
}

void init_clients(t_node *client)
{

	for (int fd = 0; fd < CLIENT_lEN; fd++)
	{
		init_client(client, fd)
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) 
		ft_printf("no ARGUMENTS\n");
	int sockfd, connfd, len, port;
	struct sockaddr_in servaddr, cli;

	port = atoi(argv[1]);
	if (port < 0 || port > 65535)
		ft_printf("wrong port\n");

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		ft_printf("socket creation failed...\n");
		exit(1);
	}
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(port);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
	{
		ft_printf("socket bind failed...\n");
		close(sockfd);
		exit(1);
	}
	if (listen(sockfd, 10) != 0)
	{
		ft_printf("cannot listen\n");
		close(sockfd);
		exit(1);
	}
	len = sizeof(cli);

	t_node client[1000];
	init_clients(client);

	fd_set fd_read_set;
	fd_set fd_write_set;
	fd_set fd_copy_read_set;
	fd_set fd_copy_write_set;

	FD_ZERO(&fd_read_set);
	FD_ZERO(&fd_write_set);
	FD_SET(sockfd, &fd_read_set);

	int max_fd = sockfd;
	int id = 0;

	while (42)
	{
		fd_copy_read_set = fd_read_set;
		fd_copy_write_set = fd_write_set;

		if (select(max_fd + 1, &fd_copy_read_set, &fd_copy_write_set, NULL, NULL) == -1)
		{
			ft_printf("select error\n");
			close(sockfd);
			exit(1);
		}

		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (FD_ISSET(fd, &fd_copy_read_set))
			{
				if (fd != sockfd)
				{
					//add buf
					add_rb(client, max_fd, fd, &fd_write_set, sockfd);
				}
				else
				{
					connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
					if (connfd >= 0)
					{
						register_client(client, connfd, &id, &fd_read_set, &max_fd);
					}
				}
			}
			if (FD_ISSET(fd, &fd_copy_write_set))
			{
				if (send_message(client, fd))
					init_client(client, fd);
				// send buf
			}
		}
	}
}