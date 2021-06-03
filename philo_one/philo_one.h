#ifndef PHILO_ONE_H
# define PHILO_ONE_H

dfv
fd
vdf
v
dfv
fd
v
default

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_info
{
	int	nb_philo;
	// Si un philosophe ne commence pas a manger dans ’time_to_die’ millisecondes après avoir commencer son dernier repas ou le début de la simulation, il meurt.
	int	time_to_die;
	// C’est le temps que prend un philosophe à manger. Il garde les deux fourchette pendant ce temps.
	int	time_to_eat;
	// C’est le temps que prend un philosophe à dormir.
	int	time_to_sleep;
	// Si tous les philosophes mangent au moins ’number_of_time_each_philosophers_must_eat’ la simulation s’arrête. Si ce temps n’est pas spécifié, la simulation s’arrête dès qu’un philosophe meurt.
	int	time_stop_simulation;
}				t_info;

typedef struct s_verif
{
	// Nombre total de mort au total depuis le début de la simulation
	int	nb_death;
}				t_verif;


typedef struct s_struct
{
	t_info			info;
	t_verif 		verif;
	struct timeval	start_time;
	struct timeval	current_time;

}				t_struct;


/*
		UTILS
*/

int			ft_ischar(char *str, int c);
// Return 1 si av ne contient que des chiffres et si aucun des arguments ne dépassent l'int max
int			check_av(char **av);
void		ft_bzero(void *s, size_t n);
long long	ft_atoll(char *str);
int			error(t_struct *data);
// Recupères les informations des arguments
int	pars_argument(t_struct *data, int ac, char **av);
/* Return 1 si :
- time_to_stop est null et qu'il y a un mort
- time_to_stop est égale au nombre de mort*/
int     check_end_simulation(t_struct *data);
int ft_strlen(char *str);
int ft_putstr(char *str);
int ft_putnbr(int	nbr);

#endif
