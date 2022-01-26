int	ft_iterative_power(int nb, int power)
{
	if (0 <= nb)
	{
		if (power == 0)
			return (1);
		else if (nb > 0 && power > 0)
			return (nb * ft_iterative_power(nb, power - 1));
		else
			return (0);
	}
	else
		return (0);
}
