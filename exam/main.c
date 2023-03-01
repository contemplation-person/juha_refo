#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int ft_strlen(char *str) {
    int i = 0;

    while (str[i]) i++;
    return (i);
}

void errorMessage(int i) {
    //wrong num 
    if (i == 1) write(2, "error: cd: bad arguments", ft_strlen("error: cd: bad arguments"));
    //cd fail
    if (i == 2) write(2, "error: cd: cannot change directory to path_to_change", ft_strlen("error: cd: cannot change directory to path_to_change"));
    if (i == 3) write(2, "error: fatal", ft_strlen("error: fatal"));
    if (i == 4) write(2, "error: cannot execute executable_that_faile", ft_strlen("error: cannot execute executable_that_faile"));
    write(2,"\n",1);
}

int ft_cd(char *path) {
    int i = chdir(path);

    if (i == -1) errorMessage(2); 
    return (i);
}

void do_cd(int start, int end, char **v) {
    if (end - start == 2) ft_cd(v[start + 1]);
    else errorMessage(1);
}

// ls -a | cd .. ;
//"error: fatal" -> failed system call, chdir and exact
//"error: cannot execute executable_that_failed" execute print system call

int cmd_str(int c, char **v, char *target) {
    int cnt = 0;

    for (int i = 0; i < c; i++) {
        if (!strncmp(";", v[i], 2)) cnt++;
    }
    return (cnt);
}

int findEndLine(int start, char **v) {
    int i = start;

    while (v[i]) {
        if (v[i] == NULL || strncmp(v[i], ";", 2)) break;
        i++;
    }
    return (i);
}

int findPipe(int start, int end, char **v) {
    int i = start;

    while (i < end) {
        if (v[i] == NULL || strncmp(v[i], "|", 2)) break;
        i++;
    }
    return (i);
}

void do_len(int start, int end, char **v) {
    int pid;
    int prev_fd = -1;
    int pipe[2];
    int find_pipe = 

    while () {

    }


}

int main(int c, char **v, char **envp) {
    int     iter = cmd_str(c, v);
    int     start;
    int     end = 0;

    while (iter--) {
        start = end;
        end = findEndLine(start, v);
        if (end == 0) continue;
        do_len(start, end, v);
    }
    return 0;
}

