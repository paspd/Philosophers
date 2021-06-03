#include "../philo_one.h"

int check_av(char **av)
{
	int i;
	int j;
	long long	temp;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_ischar("0123456789", av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	i = 1;
	while (av[i])
	{
		temp = ft_atoll(av[i]);
		if (temp > 2147483647 || temp < -2147483648)
			return (0);
		i++;
	}
	return (1);
}