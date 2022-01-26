int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i <= (nb / 2))
	{
		if ((i * i) == nb)
			return (i);
		if ((i * i) > nb)
			return (i);
		i++;
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	long int	i;

	if (1 < nb)
	{
		i = 1;
		while (i < ft_sqrt(nb))
		{
			i++;
			if (nb % i == 0)
				return (0);
		}
		return (1);
	}
	return (0);
}
