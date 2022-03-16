#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

int	main(){
	printf("ft_atoi : %d\n", ft_atoi("\t\v\f\r\n \f-06050"));
	printf("atoi    : %d\n", atoi("\t\v\f\r\n \f-06050"));
	return 0;
}