#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char	*ft_strtrim(char const *s1, char const *set);

int	main(){
	char	*s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
	char	*s2 = "Hello \t  Please\n Trim me !";
	char	*ret = ft_strtrim(s1, " \n\t");

	printf("ft : %s\n",ret);
	return (0);
}
