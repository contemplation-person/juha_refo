#include <stdio.h>
#include "libft.h"
#include <string.h>

static char	*make_p(char const *s, char c, size_t cnt_tok)
{
	char	*p;
	size_t	tail;
	ssize_t	front;
	int		cnt;

	if (!s)
		return (0);
	front = 0;
	cnt = 0;
	
}


int	main()
{
	char	s1[] = " h1ow 2are y3u ";
	char	c = 'o';
	char	**ret = ft_split(s1, c);

	int i = 0;

	printf("make p : %s\n",make_p(s1, c, 0));	
	while (ret[i])
		printf("ft : %s\n", ret[i++]);
	return (0);
}
