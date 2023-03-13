#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int ft_strlen(char *s)
{
    int i = 0;

    if (!s) return -1;
    while (s[i])
    {
        i++;
    }
    return i;
}

#include <stdio.h>
int check_cmd(char **v)
{
    if (!v) return -1;
    
    int i = 0;
    while (v[i])
    {
        printf("%d. %s\n", i, v[i]);
        i++;
    }
    printf("---------------------\n");
    return i;
}

int check_pipe(char **v)
{
    int i = 0;
    int pipe = 0;

    if (!v) return -1;
    while (v[i])
    {
        if (!strncmp("|", v[i], 2)) pipe++;
        i++;
    }
    return (pipe);
}

void do_cd(char **v)
{
    int c = check_cmd(v); 

    if (c == 2)
    {
        int check = chdir(v[1]);

        if (check)
        {
            write(2, "cd error\n", 9);
            exit(-1);
        }
    }
    else 
    {
        write(2, "too many arg\n", 13);
        exit(-1);
    }
}

void excute_sentence(char **v, char **envp) 
{
    int c = check_cmd(v);
    int cnt_pipe = check_pipe(v);

    int error = 0;

    if (cnt_pipe == -1) exit(-1);
    else if (cnt_pipe == 0 && !strncmp("cd", v[0], 3))
        do_cd(v);
    else
    {

    }
}

int main(int c, char **v, char **envp)
{
    if (c == 1) return 1;
    v[0] = NULL;

    int save_cmd = 0;

    for (int i = 1; i < c; i++)
    {
        if (v[i - 1] == NULL) save_cmd = i; 
        if (!strncmp(";", v[i], 2)) 
        {
            v[i] = NULL;
            excute_sentence(&(v[save_cmd]), envp);
        }
        if (i + 1 == c)
            excute_sentence(&(v[save_cmd]), envp);
    }
    //check_cmd(v);
    return (0);
}

