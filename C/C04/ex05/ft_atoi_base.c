#include <unistd.h>

int    check_minus(char *num)
{
    int i;

    i = 0;
    while (*num)
    {
        if (*num == '-')
            i++;
        num++;
    }
    return (i % 2);
}

void    number_range(char *str, char *base, long int *range)
{
    int j;

    range[0] = -1;
    while (str[++range[0]])
    {
        j = 0;
        while (base[++j])
        {
            if (str[range[0]] == base[j])
                break ;
        }
    }
    range[1] = range[0];
    while (str[++range[1]])
    {
        j = 0;
        while (base[++j])
        {
            if (str[range[1]] != base[j])
                break ;
        }
    }
}

int nonavailable_base(char *base)
{
    int i;
    int j;

    i = -1;
    while (base[++i])
    {
        if ((9 <= base[i] && base[i] <= 13) || 32 == base[i])
            return (1);
        if ((base[i] == '+') || (base[i] == '-'))
            return (1);
        j = i;
        while (base[++j])
        {
            if (base[i] == base[j])
                return (1);
        }
    }
    return (0);
}

long int    make_num(char *str, char *base, unsigned int base_len, long int range[2])
{
    long int num;
    int i;

    num = 0;
    while (range[0] < range[1] - 1)
    {
        if (base[0] <= str[range[0]] && str[range[0]] <= base[base_len - 1])
        {
            num *= base_len;
            i = 0;
            while (base[i])
            {
                if(base[i] == str[range[0]])
                    num += str[range[0]] - str[0];
                i++;
            }
        }
        range[0]++;
    }
    if(check_minus(str))
        return (-num);
    else
        return (num);
}

int ft_atoi_base(char *str, char *base)
{
    long int    base_len;
    long int    range[2];

    base_len = 0;
    while (base[++base_len])
    number_range(str, base, range);
    if (nonavailable_base(base) || base_len <= 1)
        return (0);
    return (make_num(str, base, base_len, range));
}