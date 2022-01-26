int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i++ <= nb / 2)
	{
		if (i * i == nb)
			return (i);
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	int	i;

	i = 0;
}
