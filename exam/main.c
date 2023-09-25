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

int ft_strlen(char *str)
{
	if (str == NULL) return 0;
	int i = 0;
	while (str[i])
		i++;
	return i;
}

void ft_printf(char *str)
{
	if (str == NULL) return ;
	write(1, str, ft_strlen(str));
}


void make_fd_zero(fd_set *target)
{
	memset(target, 0, sizeof(fd_set));
}

	
int main(int argc, char **argv) {
	if (argc > 2)
		ft_printf("wrong argc");
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		ft_printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		ft_printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	int port;

	if (argc == 1)
		port = 8081;
	else
		port = atoi(argv[1]);
	servaddr.sin_port = htons(port); 

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		ft_printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
		ft_printf("Socket successfully binded..\n");
	if (listen(sockfd, 1000) != 0) {
		ft_printf("cannot listen\n"); 
		exit(0); 
	}
	len = sizeof(cli);

	// init select
	fd_set origin_write;
	fd_set origin_read;
	fd_set copy_write;
	fd_set copy_read;

	make_fd_zero(&origin_write);
	make_fd_zero(&origin_read);

	FD_SET(sockfd, &origin_read);

	int fd_max = sockfd;
	struct timeval _timeout;
	_timeout.tv_sec = 0;
	_timeout.tv_usec = 0;

	char *buf = malloc(300000);
	char *add = malloc(300000);
	char *msg = malloc(300000);

	int add_str_len = 0;

	memset(buf,0,300000);
	memset(msg,0,300000);
	
	printf("fd_max: %d\n", fd_max);
	while(42)
	{
		//init write, read
		//FD_COPY(&origin_write, &copy_write);
		//FD_COPY(&origin_read, &copy_read);

		copy_write = origin_write;
		copy_read = origin_read;
		if (select(fd_max+1, &copy_read, &copy_write, NULL, &_timeout) == -1)
		{
			ft_printf("fatal_error");
			exit(0);
		}

		for(int clientfd = 0; clientfd < fd_max; clientfd++)
		{
			if(FD_ISSET(clientfd, &copy_write))
			{
				ft_printf("write");
				send(clientfd, msg, ft_strlen(msg), 0); 
				if (fd_max -1 == clientfd)
					memset(msg,0, 300000);
			}
			if(FD_ISSET(clientfd, &copy_read))
			{
				ft_printf("fd_isset_read\n");
				memset(add, 0, 300000);
				if (clientfd == sockfd)
				{
					connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t*)&len);
					if (connfd < 0) { 
						ft_printf("server acccept failed...\n"); 
						exit(0); 
					} 
					else
						ft_printf("server acccept the client...\n");
					if (connfd > fd_max)
						fd_max = connfd;
					FD_SET(connfd, &origin_read);
					FD_SET(connfd, &origin_write);
					ft_printf("test");
				}
				add_str_len = recv(clientfd, add, 300000, 0);
				if (!add_str_len)
				{
					FD_CLR(clientfd, &origin_read);
					FD_CLR(clientfd, &origin_write);
					close(clientfd);
				} else if (add_str_len > 0) {
					str_join(buf, add);
					if (!(*msg))
						extract_message(&buf, &msg);
				}
			}

		}

	}
}
