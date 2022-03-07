#include <stdio.h>
#include <string.h>

unsigned long int	ft_strlen(const char	*s);

int main()
{
	printf("%lu", ft_strlen("aaa"));
	printf("%lu", strlen("aaa"));
	return 0;
}