#include <stdio.h>
#include "libft.h"

int BUFFER_SIZE = 16;

char	*free_all(void **backup)
{
	if (backup == NULL || *backup == NULL)
		return (NULL);
	free(*backup);
	*backup = NULL;
	printf("backup ptr: %p\n", *backup);
	printf("backup val: %s\n", *backup);
	return (NULL);
}

char	*get_new_ret(char *backup)
{
	int		idx;
	char	*ret;

	idx = ft_strchr(backup, '\n');
	if (idx == -1)
	{
		ret = ft_substr(backup, 0, ft_strlen(backup));
		if (!ret)
			return (free_all((void **)&backup));
		free_all((void **)&backup);
		printf("backup valㅃㅂ: %s\n", backup);
		return (ret);
	}
	ret = ft_substr(backup, 0, idx + 1);
	if (!ret)
		return (free_all((void **)&backup));
	return (ret);
}

char	*ch_init_backup(char *backup)
{
	int		i;
	char	*tmp;

	printf("backup: %s\n", backup); // main함수에서 마지막 gnl(fd)를 호출할 때 문제 발생!
	if (!backup)
		backup = (char *)ft_calloc(1, sizeof(char));
	else if (ft_strchr(backup, '\n') != -1)
	{
		i = ft_strchr(backup, '\n');
		tmp = backup;
		backup = ft_substr(backup, i + 1, ft_strlen(backup) - i);
		free_all((void **)&tmp);
	}
	if (!backup)
		return (NULL);
	return (backup);
}

char	*get_next_line(int fd)
{
	int			i;
	ssize_t		size;
	char		buf[BUFFER_SIZE + 1];
	static char	*backup;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	backup = ch_init_backup(backup);
	if (!backup)
		return (NULL);
	while (ft_strchr(backup, '\n') == -1 && ++i)
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = 0;
		if (size < 0 || (size == 0 && i == 1))
			return (free_all((void **)&backup));
		if (size < BUFFER_SIZE)
			break ;
		backup = ft_strjoin(backup, buf);
	}
	return (get_new_ret(backup));
}

int	main(void)
{
	int	fd;

	fd = open("test", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s(end)\n", get_next_line(fd));
	printf("%s", get_next_line(fd));
}