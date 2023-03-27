#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

enum e_fdnum
{
    STDIN = 0,
    STDOUT = 1,
    READ = 0,
    WRITE = 1,
};

enum e_error_message
{
    FAILED_CD,
    TOO_MANY_ARGV_CD,
    FATAL_ERROR,
    EXECVE_ERROR,
};

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
    {
        i++;
    }
    return i;
}

void error_message(enum e_error_message error)
{
    char *str;

    if (error == FAILED_CD)
        str = "FAILED_CD";
    else if (error == TOO_MANY_ARGV_CD)
        str = "TOO_MANY_ARGV_CD";
    else if (error == FATAL_ERROR)
        str = "FATAL_ERROR";
    else
        str = "EXECVE_ERROR";
    write(2, str, strlen(str));
}

int ft_cnt_argc(char **v)
{
    if (v == NULL)
    {
        error_message(FATAL_ERROR);
        return (-1);
    }

    int i = 0;

    if (v[i])
    {
        i++;
    }
    return (i + 1);
}

void do_pipe(char **v, char **envp)
{
    int c = ft_cnt_argc(v);
    write(1, v[0], ft_strlen(v[0]));
}

void do_cmd(char **v, char **envp)
{
    int j=0;
    while (v[j])
    {
        write(2, v[j], ft_strlen(v[j]));
        j++;
    }
    int c = ft_cnt_argc(v); 

    for (int i = 0; i < c; i++)
    {
        if (!strncmp("|", v[i], 2))
        {
            v[i] = NULL;
        }
    }
    for (int i = 0; i < c; i++)
    {
        if (i == 0)
        {
            if (v[0])
                do_pipe(v + i, envp);
        }
        else if (i != 0 && v[i - 1] == NULL && v[i])
            do_pipe(v + i, envp);
    }
}

int main(int c, char **v, char **envp)
{
    if (c < 2)   
        return 0;
    v[0] = NULL;
    for (int i = 1; i < c; i++)
    {
        if (!strncmp(";", v[i], 2))
            v[i] = NULL;
    }
    for (int i = 1; i < c; i++)
    {
        if (v[i - 1] == NULL && v[i])
            do_cmd(v + i, envp);
    }
    return 0;
}
