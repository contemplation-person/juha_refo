#include <io.h>
#include <stdio.h>

void	ft_swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
// 1,2,3,4,5
void	ft_sort_int_tab(int* tab, int size)
{
	int idx = size-1;
	int i;
	int j;

	j = 1;
	i = 0;
	while (i =! idx)
	{
		while (j = !idx)
		{
			if (*(tab + i) > *(tab + j))
			{
				ft_swap(tab + i, tab + j);
			}
			i++;
			j++;
		}
	}
}

void main() {
	int a[5] = { -1,2,0,-4,5 };
	ft_sort_int_tab(a, 5);
	for (int i = 0; i < 5; i++) printf_s("%d ", *(a+i));
}