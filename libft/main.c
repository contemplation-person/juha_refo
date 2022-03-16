#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

int	main(){
	printf("ft_atoi : %d\n", ft_atoi("9223372036854775807"));
	printf("atoi    : %d\n", atoi("9223372036854775807"));
	return 0;
}
