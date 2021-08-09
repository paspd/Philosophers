#include "../incs/philo.h"

int	check_death(t_main *main, t_philo *philo, pthread_t *threads)
{
	int			i;
	long int	check;

	while (philo->alive && !philo->main->stop)
	{
		i = 0;
		if (philo->main->info.time_stop_simulation
			&& philo->nb_eat == philo->main->info.time_stop_simulation)
			break ;
		while (i < philo->main->info.nb_philo)
		{
			pthread_mutex_lock(&main->die);
			check = (ft_get_time() - main->first_time) - philo[i].last_eat;
			if (check > main->info.time_to_die)
			{
				ft_death(&philo[i]);
				pthread_mutex_unlock(&main->die);
				clean_philo(philo, threads, 1);
				return (-1);
			}
			pthread_mutex_unlock(&main->die);
			i++;
		}
	}
	return (0);
}
