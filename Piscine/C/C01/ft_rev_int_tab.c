#include <unistd.h>

void	ft_swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void    ft_rev_int_tab(int* tab, int size)
{
    int index = size-1;
    int index_r = 0;

    while (index != size/2)
    {
        ft_swap(tab+index_r, tab+index);
        index--;
        index_r++;
    }
}
