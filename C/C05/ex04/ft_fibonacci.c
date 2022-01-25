int ft_fibonacci(int index)
{
    if (index > 1)
        return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
    else if (index < 0)
        return (0);
    else
        return (1);    
}