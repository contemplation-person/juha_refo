int	ft_recursive_factorial(int nb)
{
	int	num;

	num = 0;
	if (nb > 1)
	{
		num = nb;
		return (num *= ft_recursive_factorial(nb - 1));
	}
	else if ((nb == 1) || (nb == 0))
		return (1);
	else
		return (0);
}