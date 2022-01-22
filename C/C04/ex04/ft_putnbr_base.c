#include <unistd.h>

void  ft_putnbr_base(int nbr, char *base)
{
    int a = 0;
    
    while(nbr > a)
    {
        write(1, base+a, 1);
        a++;
    }
}