#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char str[2024];
	int fd = open("test.txt", O_RDWR | O_TRUNC | O_CREAT);
	system("chmod 755 test.txt");
	int len;
	for(int i = 0; i < 100000; i++)
	{
		len = sprintf(str, "[%d]\n", i);
		write(fd, str, len);
	}
	close(fd);
	system("cc -Wall -Werror -Wextra get_next_line.c test.c && ./a.out > test");
	return 0;
}
