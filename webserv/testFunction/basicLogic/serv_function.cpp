#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
/*
    int socket(int domain, int type, int protocol);
    int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
*/
void error_handling(const char *msg, int return_code = 1)
{
    std::cout << msg << std::endl;
	printf("%s\n",std::strerror(errno));
    exit(return_code);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        error_handling("Usage: ./function <port>", -1);
/*
     * return   : file descriptor if OK, -1 on error
     * domain   : AF_INET = IPv4
     * type     : SOCK_STREAM = TCP
     * protocol : 0 = default protocol for domain and type
*/

    int serv_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_sock_fd == -1)
        error_handling("socket() error");

    // sockaddr_in                <- #include <arpa/inet.h>
    struct sockaddr_in server_addr;
    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(std::atoi(argv[1]));

/*
    * return   : 0 if OK, -1 on error
    * sockfd   : socket descriptor
    * addr     : pointer to a sockaddr structure
    * addrlen  : length of addr
*/
    if (bind(serv_sock_fd, reinterpret_cast<const sockaddr *>(& server_addr), sizeof(server_addr)))
        error_handling("bind() error");

/*
    * return   : 0 if OK, -1 on error
    * sockfd   : socket descriptor
    * backlog  : maximum length of the pending connection queue
*/
    if (listen(serv_sock_fd, 5))
        error_handling("listen() error");

    int clnt_sock_fd;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    clnt_addr_size = sizeof(clnt_addr);
/*
    * return   : file descriptor if OK, -1 on error
    * sockfd   : socket descriptor
    * addr     : pointer to a sockaddr structure
    * addrlen  : length of addr 
*/
    clnt_sock_fd = accept(serv_sock_fd, reinterpret_cast<sockaddr *>(&clnt_addr), &clnt_addr_size);
    if (clnt_sock_fd == -1)
        error_handling("accept() error");

    char message[] = "Hello World!";
    write(clnt_sock_fd, message, sizeof(message));
    
    close(clnt_sock_fd);
    close(serv_sock_fd);
    return 0;

}
