#include <unistd.h>
#include <stdio.h>
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int main (){
	char	*src = "123456";
	char	dest[20];

	size_t	ret	= ft_strlcpy(dest, src, 13);
	printf("%dest = %s\nreturn = %zu\n", dest, ret);

	return 0;
}