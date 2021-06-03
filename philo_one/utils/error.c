#include "../philo_one.h"

int	error(t_struct *data)
{
	ft_bzero(data, sizeof(t_struct));
	return (0);
}