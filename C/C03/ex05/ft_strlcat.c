

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	cnt;
	unsigned int	i;

	i = 0;
	cnt = 0;

    while (dest[i])
        i++;
    if (i > size)
    {
        while(src[cnt])
        {
           cnt++;
        }
           return (cnt + size);
    }
    else
    {
        while (src[i++])
            cnt++;
    }
    return (cnt);
}