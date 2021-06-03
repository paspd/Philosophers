#include "philo_one.h"


int	pars_argument(t_struct *data, int ac, char **av)
{
	if (!check_av(av))
		return (error(data));
	data->info.nb_philo = (int)ft_atoll(av[1]);
	data->info.time_to_die = (int)ft_atoll(av[2]);
	data->info.time_to_eat = (int)ft_atoll(av[3]);
	data->info.time_to_sleep = (int)ft_atoll(av[4]);
	if (ac == 6)
		data->info.time_stop_simulation = (int)ft_atoll(av[5]);
	return (1);
}

int main(int ac, char **av)
{
	t_struct data;

	ft_bzero(&data, sizeof(data));
	gettimeofday(&data.start_time, NULL);
	if (ac < 5 || ac > 6)
		return (0);
	if (!pars_argument(&data, ac, av))
		return (0);
	printf("nb_philo =%d\n", data.info.nb_philo);
	printf("time_to_die =%d\n", data.info.time_to_die);
	printf("time_to_eat =%d\n", data.info.time_to_eat);
	printf("time_to_sleep =%d\n", data.info.time_to_sleep);
	printf("time_stop_simulation =%d\n", data.info.time_stop_simulation);
	while (!check_end_simulation(&data))
	{
		for (size_t i = 0; i < 10; i++)
		{
			if (i == 5)
				data.verif.nb_death++;
			usleep(3);
		}
	}
	printf("nb_death =%d\n", data.verif.nb_death);
	gettimeofday(&data.current_time, NULL);
	printf("Durée de la simulation = %dms\n", data.current_time.tv_usec - data.start_time.tv_usec);
	return (0);
}
