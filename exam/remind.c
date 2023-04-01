#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

int ft_cnt_argv(char **argv)
{
    if (argv == NULL)
        return -1;
    
    int i = 0;
    
    while (argv[i])
        i++;
    return i;
}

void ft_strendl(char *str)
{
    write(2, str, ft_strlen(str));
    write(2, "\n", 1);
}

void ft_str(char *str)
{
    write(2, str, ft_strlen(str));
}

void ft_all_cmd(char **argv)
{
    if (argv == NULL)
        return ;
    int i = 0;
    ft_strendl("====");
    while (argv[i])
    {
        ft_strendl(argv[i]);
        i++;
    }
}

int ft_cd(char **cmd_token)
{
    int argc = ft_cnt_argv(cmd_token);
    if (argc != 2)
    {
        ft_strendl("too many cd argc");
        return 1;
    }
    if (chdir(cmd_token[1] ) == -1)
    {
        ft_str("failed cmd ");
        ft_strendl(cmd_token[1]);
        return 1;
    }
    return 0;
}

void do_cmd(char **cmd_token, char **envp)
{
    int argc = ft_cnt_argv(cmd_token);
    pid_t pid;

    {
        int pipe_fd[2];
        int prev_fd = -1;
        char *cmd;

        for (int i = 0; i < argc; i++)
        {
            if (i == 0 || (i > 0 && cmd_token[i - 1] == NULL && cmd_token[i])) 
            { 
                cmd = cmd_token[i];
            }
            if (cmd_token[i] == NULL)
            {
                i = 0;
                pid = make_pipe();
            }
        }
    }
}

int main(int argc, char **argv, char **envp)
{
    if (argc == 1) return 0;
    argv[0] = NULL;
    for(int i = 1; i < argc; i++)
    {
        if (!strncmp(";", argv[i], 2))
            argv[i] = NULL;
    }
    for(int i = 1; i < argc; i++)
    {
        if (argv[i - 1] == NULL && argv[i])
            do_cmd(argv + i, envp);
    }

}
