#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

int	main(){
	char *str = "01234";
	size_t size = 10;
	char *ret = ft_substr(str, 10, size);
	printf("ft_substr: %s\n", ret);
	return (0);
}
