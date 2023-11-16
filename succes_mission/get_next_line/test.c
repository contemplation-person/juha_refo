#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    char *line = (char*)1;
    int fd = open("text.txt", O_RDONLY);
    while (line)
    {
        line = get_next_line(fd);
        printf("line : %s", line);
        free(line);
    }
    return 0;
}
