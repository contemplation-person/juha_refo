#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

enum  ft_fd_name{
	FAILED_CD,
	TOO_MANY_ARGC,
	FATAL_ERROR,
	EXECVE,
};

enum fd__{
	STDIN,
	STDOUT,
	READ = 0,
	WRITE,
};

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return i;
}

int error_message(enum ft_fd_name fd_name)
{
	char *str;
	if (fd_name == FAILED_CD)
		str = "FAILED_CD";
	else if (fd_name == FATAL_ERROR)
		str = "FATAL_ERROR";
	else if (fd_name == TOO_MANY_ARGC)
		str = "TOO_MANY_ARGC";
	else
		str = "EXECVE";
	write(2, str, ft_strlen(str));
	if (fd_name == FATAL_ERROR)
		exit(1);
	return 1;
}

int cnt_argc(char **v)
{
	if (v == NULL)
		return -1;
	
	int i = 0;

	while (v[i])
		i++;
	return i;
}

void do_cd(char **v)
{
	int c = cnt_argc(v);
	
	if (c != 2)
	{
		error_message(TOO_MANY_ARGC);
		return ;
	}
	
	int error_check = chdir(v[1]);

	if (error_check == -1) error_message(FAILED_CD);
	return ;
}

void do_cmd(char **v, char **envp)
{
	int c = cnt_argc(v);
	int cnt_pipe = 0;
	
	for (int i = 0; i < c; i++)
	{
		if (!strncmp("|", v[i], 2))
		{
			cnt_pipe++;
			v[i] = NULL;
		}
	}	

	pid_t pid;

	if (!cnt_pipe)
	{
		//하나 일때
		if (v[0] == NULL) return ;
		if (!strncmp("cd", v[0], 3))
		{
			do_cd(v);
		}
		else
		{
			pid = fork();
			if (pid == -1) error_message(FATAL_ERROR);
			else if (pid == 0)
			{
				int check_err = execve(v[0], v, envp);

				if (check_err)
				{
					error_message(EXECVE);
				}
			}
		}
	}
	else
	{
		int		pipe_fd[2];
		int		prev_fd = -1;
		pid_t	pid;
		int		excute_child = 0;
		int		child_end = 0;

		for (int i = 0; i < c; i++)
		{
			if ((v[i] && i == 0) && (i != 0 && v[i - 1] == NULL && v[i]) )
				child_end++;
		}

		//make pipe in main proccess
		int do_child;
		for(int i = 0; i < c; i++)
		{
			do_child = i;
			if ((v[i] && i == 0) && (i != 0 && v[i - 1] == NULL && v[i]) )
			{
				excute_child++;
				pipe(pipe_fd);
				pid = fork();
				if (pid == 0) break;
				if (prev_fd != -1)
					close(prev_fd);
				prev_fd = pipe_fd[READ];
				close(pipe_fd[WRITE]);
			}
		}
		if (pid == 0)
		{
			if (prev_fd != -1)
				dup2(pipe_fd[READ], STDIN);
			if (excute_child != child_end)
				dup2(pipe_fd[WRITE], STDOUT);
			execve(v[do_child], v + do_child, envp);	
		}
		// parent_end//
		if (pid > 0)
		{
			int status;
			for (int i = 0; i < do_child; i++)
			{
				waitpid(-1, &status, 0);
			}
		}
	}
}

		
		


int main(int c, char **v, char **envp)
{
	if (c == 1) return 0;
	v[0] = NULL;
	for (int i = 1; i < c; i++)
	{
		if (!strncmp(";", v[i], 2))
			v[i] = NULL;
	}	
	for (int  i = 1; i < c; i++)
	{
		if (v[i - 1] == NULL && v[i])
			do_cmd(v + i, envp);
	}
	return 0;
}
