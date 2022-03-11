#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t count);

int main()
{
	char	dst[10] = "abcdaaaaa";
	char	src[10] = "123456789";


	printf("origin : %s\n",    memmove(dst, src, 8));
	printf("ft     : %s\n", ft_memmove(dst, src, 8));

	printf("origin : %s\n",    memmove(src + 2, src, 8));
	printf("ft     : %s\n", ft_memmove(src + 2, src, 8));
	return (0);
}
