#include <stdio.h>
#include "libft.h"
#include <string.h>

static size_t	ft_cnt_word(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;

	while (s[i])
	{
		if (!ft_strchr(s + i, c))
			cnt++;
		i++;
	}
	return (cnt);
}

int	main(){
	char *s1 = " how are you ";
	int ret = ft_cnt_word(s1, 'o');

	printf("ft : %d\n",ret);
	return (0);
}
