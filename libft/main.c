#include <stdio.h>
#include "libft.h"
#include <string.h>

int	main(){
	char *s1 = "  \t \t \n   \n\n\n\t";
	char *s2 = "";
	char *ret = ft_strtrim(s1, " \n\t");
	int i = 0;
	while(s1[i])
		i++;
	printf("i = %d\n",i);
	printf("ft : %s\n",ret);
	return (0);
}
