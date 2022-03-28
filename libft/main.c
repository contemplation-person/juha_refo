#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

static size_t	cnt_word(char *s, char c);
static char		*make_p(char *s, char c);
static char		**free_all(char **pp, size_t i);

char	**ft_split(char const *str, char c)
{
	char	**pp;
	char	*s;
	size_t	i;

	s = (char *)str;
	pp = (char **)malloc(sizeof(char *) * (cnt_word(s, c) + 1));
	if (!pp)
		return (0);
	i = 0;
	while (i < cnt_word((char *)str, c))
	{
		while (*s && *s == c)
			s++;
		if (*s != c)
		{
			pp[i] = make_p(s, c);
			if (!pp[i])
				return (free_all(pp, i));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	printf("cnt_word : %zu\n",cnt_word(s, c));
	if (cnt_word(s, c))
		pp[0] = ft_strdup("");
	pp[i] = 0;
	return (pp);
}

static size_t	cnt_word(char *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	if (s[i - 1] && s[i - 1] == c)
		return (cnt - 1);
	return (cnt);
}

static char	*make_p(char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

static char	**free_all(char **pp, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(pp[j]);
		pp[j++] = 0;
	}
	free (pp);
	pp = 0;
	return (0);
}


int	main()
{
	char	s1 = 'a';
	char	s2[] = "";
	char	**pp = ft_split(s2, s1);

	printf("\n");
	for(int i = 0; i < (int)cnt_word(s2, s1);i++)
		printf("ft   : %s\n", pp[i]);

	char s3[] = "sdfsadfasdf";
	pp = ft_split(s3, s1);
	for(int i = 0; i < (int)cnt_word(s3, s1);i++)
		printf("ft   : %s\n", pp[i]);
	return (0);
}
