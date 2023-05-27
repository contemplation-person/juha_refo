#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
/*
  int socket(int domain, int type, int protocol);
  int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
*/
int main()
{
/*
  * return : file descriptor if OK, -1 on error
  * domain : AF_INET = IPv4
  * type : SOCK_STREAM = TCP
  * protocol : 0 = default protocol for domain and type
*/
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        // error
    }

/*
 *
*/
// sockaddr_in                <- #include <arpa/inet.h>
    struct sockaddr_in server_addr;
    std::memset(&server_addr, 0, sizeof(server_addr));

    bool isSuccess = bind(fd, server_addr, sizeof(server_addr));
}
