#include "../incs/philo.h"

long int	ft_get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	better_usleep(long int time, t_philo *philo)
{
	long int	i;

	i = ft_get_time();
	while (philo->alive)
	{
		if ((ft_get_time() - i) >= time)
			break ;
		usleep(50);
	}
}
