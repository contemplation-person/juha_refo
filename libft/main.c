#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			size;
	char			*temp;

	if (!s1 || !s2)
		return (0);
	size = 0;
	while (s1[size++])
		;
	while (s2[size++])
		;
	temp = (char *)malloc(size);
	if (!temp)
		return (0);
	size = 0;
	while (s1[size])
	{
		temp[size] = s1[size];
		size++;
	}
	i = 0;
	while (s2[i])
		temp[size++] = s2[i++];
	temp[size] = '\0';
	return (temp);
}


int	main()
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	printf("ft   : %s?\n", ft_strjoin(s1, s2));

	return (0);
}
