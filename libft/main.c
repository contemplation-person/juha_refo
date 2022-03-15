#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c);

int	main(){
	char * str = "abcd";
	char c = 'k';
	printf("%s\n",strchr(str,c));
	printf("%s\n",ft_strchr(str,c));
	return 0;
}