#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
    // 1+1 이 아니라  return i;
    return (i);
}

void do_pipe(char **v, char **envp)
{
    int c = ft_cnt_argc(v);
}

void do_cmd(char **v, char **envp)
{
    int j=0;
    while (v[j])
    {
        write(2, v[j], ft_strlen(v[j]));
        j++;
    }
    int c = ft_cnt_argc(v); // 1

    int check_cd = 0;
    for (int i = 0; i < c; i++)
    {
        if (!strncmp("|", v[i], 2))
        {
            v[i] = NULL;
        }
    }
 

    for (int i = 0; i < c; i++)
    {
    /* juha's way

    for (int i = 0; i < c; i++)
    {
        //부모 동작
        if (v[i] == NULL)
        {
            파이프
            포크
            if (자식) 
                break;
            if (prev_fd != -1)
                close(prev_fd);
            prev_fd = READ;
            close(write);
        }
    }


    // 자식영역
    {
        if (prev_fd != -1)
        {
            dup2()
            close();
        }
        if (자식 마지막이 아니면)
        {
            dup2(write)연결
            close();
        }
        execve
        return;
    }

    close(channel.prev_fd);
    while (i--)
    {
        if (p->pid_num == waitpid(-1, &status, 0))
            p->status = status;
    }
    */
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
    // asdf ";" test "|" done
    // asdf NULL test "|" done
    for (int i = 1; i < c; i++)
    {
        if (v[i - 1] == NULL && v[i])
            do_cmd(v + i, envp);
    }
    return 0;
}
