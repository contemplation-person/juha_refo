#include <unistd.h>

int nonavailable_base(char *base)
{
    int i;
    int j;

    i = -1;
    while(base[++i])
    {
        j = i;
        while(base[++j])
        {
            if ((base[j] == ' ') || (base[j] == '\n') || (base[j] == '\t') || (base[j] == '\v') || (base[j] == '\f') || (base[j] == '\r') ||)
        }
    }
    //기수가 비어있는지, 동일한 문자가 포함됐는지, 기수에 + -
    return (0);
}

int mk_numsys(char *base)
{
    int i;
    
    i = 0;
    while (base[i])
    {
        i++;
    }
    return (i);
}

void  ft_putnbr_base(int nbr, char *base)
{
    int             numsys;
    unsigned int    unsign;

    if(nonavailable_base(base))
        return ;
    if(nbr < 0 )
        write(1, "-", 1);
        unsign = -nbr;
    else
        unsign = nbr;
    numsys = mk_numsys(base);
    if(unsign == 0)
    {
        return ;
    }
    ft_putnbr_base(unsign/numsys, base);
    write(1, (base+(unsign%numsys)), 1);
}