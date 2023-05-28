#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error_handling(const char *msg, int return_code = 1)
{
	std::cout << msg << std::endl;
	std::strerror(errno);
	exit(return_code);
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		error_handling("Usage: ./client <IP> <port>", -1);

	int sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in serv_addr_fd;

	std::memset(&serv_addr_fd, 0, sizeof(serv_addr_fd));
	serv_addr_fd.sin_family = AF_INET;
	serv_addr_fd.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr_fd.sin_port = htons(std::atoi(argv[2]));


	if (connect(sock, reinterpret_cast<const sockaddr *>(&serv_addr_fd), sizeof(serv_addr_fd)))
		error_handling("connect() error");
	
	char message[30];
	int str_len;

	str_len = read(sock, message, sizeof(message) - 1);
	if (str_len == -1)
		error_handling("read() error");
	
	std::cout << "Message from server: " << message << std::endl;
	close(sock);
	return 0;
}