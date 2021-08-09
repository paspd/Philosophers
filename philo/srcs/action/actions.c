#include "../../incs/philo.h"

void	ft_eat(t_philo *philo)
{
	ft_take_fork(philo);
	if (!philo->main->stop)
	{
		aff_action(philo, EAT);
		pthread_mutex_lock(&philo->main->die);
		philo->last_eat = ft_get_time() - philo->main->first_time;
		pthread_mutex_unlock(&philo->main->die);
		philo->eat = 1;
		philo->sleep = 0;
		philo->nb_eat++;
		better_usleep(philo->main->info.time_to_eat, philo);
	}
	ft_drop_fork(philo);
}

void	ft_sleep(t_philo *philo)
{
	aff_action(philo, SLEEP);
	better_usleep(philo->main->info.time_to_sleep, philo);
	philo->think = 0;
	philo->sleep = 1;
}

void	ft_think(t_philo *philo)
{
	aff_action(philo, THINK);
	philo->think = 1;
	philo->eat = 0;
}

void	ft_death(t_philo *philo)
{
	if (!philo->main->stop)
	{
		aff_action(philo, DIED);
		philo->alive = 0;
		if (!philo->main->info.time_stop_simulation)
			philo->main->stop = 1;
	}
}
