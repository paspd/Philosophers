#include "../../incs/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_check_str(const char *str, int i)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	while (str[i] == '+')
		i++;
	if (ft_check_str(str, i) == -1)
		return (-1);
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		res = res * 10;
		res = res + (str[i] - '0');
		i++;
	}
	return (res);
}

void	get_data(char **argv, t_main *main)
{
	main->info.nb_philo = ft_atoi(argv[1]);
	main->info.time_to_die = ft_atoi(argv[2]);
	main->info.time_to_eat = ft_atoi(argv[3]);
	main->info.time_to_sleep = ft_atoi(argv[4]);
}

int	parse_data(int argc, char **argv, t_main *main)
{
	get_data(argv, main);
	if (argc == 6)
	{
		main->info.time_stop_simulation = ft_atoi(argv[5]);
		if (main->info.time_stop_simulation <= 0)
		{
			printf("Number_of_times_each_philosopher_must_eat should be > 0\n");
			return (-1);
		}
	}
	if (main->info.nb_philo <= 0)
	{
		printf("Number of philosopher should be > 1\n");
		return (-1);
	}
	if (main->info.time_to_die < 60 || main->info.time_to_eat < 60
		|| main->info.time_to_sleep < 60)
	{
		printf("Error with time\n");
		return (-1);
	}
	return (0);
}
