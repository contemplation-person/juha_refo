#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

enum micro {
    READ,
    WRITE,
    IN = 0,
    OUT,
    ERROR,
};

int count_cmd(char **cmd) {
    int i = 0;
    int pipe_cmd = 0;
    while (cmd[i]) {
        if (!strncmp("|", cmd[i], 2)) pipe_cmd++;
        i++;
    }
    return (pipe_cmd + 1);
}

void use_cmd(char **cmd, char **envp) {
    pid_t   pid;
    int     counting_cmd = count_cmd(cmd);
    int     stop_child = 0;
    int     checking_error = 0;
    int     prev_fd = -1;
    int     pipe_fd[2];

    if (counting_cmd == 1) { execve(cmd[0], cmd, envp); }
    //parent
    for (int i = 0; i < counting_cmd; i++) {
        checking_error = pipe(pipe_fd);
        if (checking_error) exit(1);
        pid = fork();
        if (pid == 0) {
            stop_child = i;
            break;
        }
        if (prev_fd != -1) close(prev_fd);
        close(pipe_fd[WRITE]);
        prev_fd = pipe_fd[READ];
    }
    //child
    if (pid == 0) {
        if (stop_child != 0) {
            dup2(IN, pipe_fd[READ]); 
            close(IN);
        }
        if (stop_child != counting_cmd) {
            dup2(OUT, pipe_fd[WRITE]); 
            close(OUT);
        }
        if (prev_fd != -1) close(prev_fd);
        int x = 0;
        char **do_cmd = cmd;
        while (cmd[x]) {
            if (x != 0 && cmd[x - 1] == NULL) do_cmd = &(cmd[x]); 
            if (!strncmp("|", cmd[x], 2)) {
                cmd[x] = NULL;
                execve(do_cmd[0],do_cmd,envp);
            }
            x++;
        }
        
    }
    //waitpid
    close(prev_fd);
    for (int i = 0; i < counting_cmd; i++) {
        if (waitpid(-1, &stop_child, 0))
            exit(stop_child);
    }
}

int main(int c, char **v, char **envp){
    int i = 0;
    v[0] = NULL;

    while (v[i]) {
        if (!strncmp(";", v[i], 2)) v[i] = NULL;
        i++;
    }
    for (int i = 1; i < c; i++) {
        if (v[i - 1] == NULL && v[i]) use_cmd(&(v[i]), envp);
    }
    return 0;
}
