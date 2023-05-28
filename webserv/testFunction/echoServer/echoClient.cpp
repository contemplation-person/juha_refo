#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void handle_error(const char *msg, int return_code = 1)
{
	std::cout << msg << std::endl;
	std::strerror(errno);
	exit(return_code);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		handle_error("Usage: ./client <IP> <port>", -1);

	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in serv_addr_fd;
	std::memset(&serv_addr_fd, 0, sizeof(serv_addr_fd));
	serv_addr_fd.sin_family = AF_INET;
	serv_addr_fd.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr_fd.sin_port = htons(std::atoi(argv[2]));
	if (connect(sock_fd, reinterpret_cast<const sockaddr *>(&serv_addr_fd), sizeof(serv_addr_fd)) == -1)
		handle_error("connect() error");
	else
		std::cout << "Connected to server" << std::endl;
	char message[30];
	// make buffer;
	int str_len;
	while (str_len = read(sock_fd, message, sizeof(message) - 1))
	{
		if (str_len == -1)
			handle_error("read() error");
		else if (str_len == 0)
			break;
		else
		{
			message[str_len] = '\0';
			std::cout << "Message from server: " << message << std::endl;
		}
	}
	close(sock_fd);
	return 0;
}