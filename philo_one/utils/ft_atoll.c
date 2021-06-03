#include "../philo_one.h"

long long		ft_atoll(char *str)
{
	int			i;
	int			f;
	long long	out;

	i = 0;
	f = 1;
	out = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			f = -1;
		++i;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + (str[i] - '0');
		++i;
	}
	return (f * out);
}