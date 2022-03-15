#include <unistd.h>
#include <stdio.h>
#include <string.h>
int	ft_strncmp(const char *s1, const char *s2, size_t n);

int main (){
	char	*s1 = "omg1||||||||||||||||";
	char	*s2 = "omg3";
	size_t	size = 4;
	int	i1 = ((strncmp(s1, s2, size) > 0) ? 1 : ((strncmp(s1, s2, size) < 0) ? -1 : 0));
	int	i2 = ((ft_strncmp(s1, s2, size) > 0) ? 1 : ((ft_strncmp(s1, s2, size) < 0) ? -1 : 0));
	printf("s")
	return 0;
}