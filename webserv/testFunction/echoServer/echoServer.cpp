#include <sys/socket.h>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#define BUF_SIZE 1024

void error_handling(const char *msg, int return_code = 1)
{
	std::cerr << msg << std::endl;
	std::strerror(errno);
	exit(return_code);
}

int main(int argc, char **argv)
{
	struct sockaddr_in serv_addr_fd;
	struct sockaddr_in clnt_addr_fd;
	socklen_t clnt_addr_size;
	int serv_sock_fd;
	int clnt_sock_fd;
	
	std::memset(&serv_addr_fd, 0, sizeof(serv_addr_fd));
	serv_addr_fd.sin_family = AF_INET;
	serv_addr_fd.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr_fd.sin_port = htons(atoi(argv[1]));

	if (connect(serv_sock_fd, reinterpret_cast<const sockaddr *>(&serv_addr_fd), sizeof(serv_addr_fd)) == -1)
		error_handling("connect() error");
	else
		std::cout << "Connected..." << std::endl;
	
	char message[BUF_SIZE];
	int str_len;
	while (1)
	{
		std::cout << "Input message(Q to quit): ";
		std::cin >> message;
		if (!strcmp(message, "q") || !strcmp(message, "Q"))
			break;
		write(serv_sock_fd, message, strlen(message));
		str_len = read(serv_sock_fd, message, BUF_SIZE - 1);
		if (str_len == -1)
		{
			std::cout << "read() error and retry" << std::endl;
			continue ;
		}
		message[str_len] = 0;
		std::cout << "Message from server: " << message << std::endl;
	}
	close(serv_sock_fd);
	return 0;
}