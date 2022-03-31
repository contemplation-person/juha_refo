#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

void	*del(void	*a)
{
	int *x;
	x = (int *)a;
	return (void *)x;
}

int	main(void)
{
	t_list **a;
	ft_lstclear(a, del);
	
	return (0);
}
