#include "../incs/philo.h"

void	*philofunction(void *data)
{
	t_philo	*philo;

	philo = data;
	if (philo->id % 2)
		usleep(1500);
	while (philo->alive && !philo->main->stop)
	{
		if (!philo->main->stop && philo->alive && !philo->eat)
			ft_eat(philo);
		if (!philo->main->stop && philo->alive && !philo->sleep)
			ft_sleep(philo);
		if (philo->alive && philo->main->info.time_stop_simulation \
			&& philo->nb_eat == philo->main->info.time_stop_simulation)
			break ;
		if (!philo->main->stop && philo->alive && !philo->think)
			ft_think(philo);
	}
	return (data);
}

t_philo	init_philosopher_structure(t_main *main, int id)
{
	t_philo	philo;

	philo.main = main;
	philo.id = id;
	philo.alive = 1;
	philo.sleep = 1;
	philo.think = 1;
	philo.eat = 0;
	philo.nb_eat = 0;
	philo.stop = 0;
	pthread_mutex_init(&philo.fork, NULL);
	return (philo);
}
