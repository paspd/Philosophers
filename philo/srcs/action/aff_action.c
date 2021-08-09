#include "../../incs/philo.h"

void	aff_action(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->main->write);
	printf("%ld ms :%d",
		(ft_get_time() - philo->main->first_time), philo->id);
	if (action == EAT)
		printf(" is eating\n");
	else if (action == SLEEP)
		printf(" is sleeping\n");
	else if (action == THINK)
		printf(" is thinking\n");
	else if (action == TAKE)
		printf(" has taken fork\n");
	else if (action == DIED)
		printf(" died\n");
	pthread_mutex_unlock(&philo->main->write);
}
