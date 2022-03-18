#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(){
	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		j = !j;
		printf("! : %d\n",j);
	}
	return (0);
}
