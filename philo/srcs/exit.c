#include "../incs/philo.h"

void	clean_philo(t_philo *philo, pthread_t *threads, int j)
{
	int	i;

	i = -1;
	while (++i != philo->main->info.nb_philo)
		pthread_mutex_destroy(&philo[i].fork);
	free(philo);
	if (j == 1)
	{
		free(threads);
		pthread_mutex_destroy(&philo->main->write);
		pthread_mutex_destroy(&philo->main->die);
	}
}
