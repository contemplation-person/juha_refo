#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

int	main()
{
	int	a[20];

	for (int i = 0; i < 20; i++)
		a[i] = i;

/*
	ft_memset (a, 48, 2);
	memset(a, 48, 2);


	ft_bzero (a, 0);
	bzero(a, 1);
	for (int i = 0; i < 40; i++)
	{
		if (i < 20)
			printf("ft     : %d\n", a[i] );
		else
			printf("origin : %d\n", a[i%20]);
	}
*/
	return (0);
}
