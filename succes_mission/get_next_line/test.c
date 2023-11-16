#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

int main()
{
    char *line = (char*)1;
    int fd = open("test.txt", O_RDONLY);
    while (42)
    {
        line = get_next_line(fd);
        if (!line)
            return 0;
        write(STDOUT_FILENO, line, strlen(line));
        free(line);
    }
    return 0;
}
