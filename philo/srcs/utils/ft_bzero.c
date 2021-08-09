#include "../../incs/philo.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*str;

	str = s;
	i = 0;
	while (n > 0)
	{
		str[i] = 0;
		n--;
		i++;
	}
}
