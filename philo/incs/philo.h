#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>

# define EAT 1
# define SLEEP 2
# define THINK 3
# define TAKE 4
# define DROP 5
# define DIED 6

typedef struct s_info
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_stop_simulation;
}				t_info;

typedef struct s_main
{
	t_info				info;
	pthread_mutex_t		write;
	pthread_mutex_t		die;
	long int			first_time;
	int					stop;
	struct s_philo		*philo;
}				t_main;

typedef struct s_philo
{
	pthread_mutex_t		fork;
	pthread_mutex_t		*prev_fork;
	t_main				*main;
	long int			last_eat;
	int					id;
	int					alive;
	int					sleep;
	int					eat;
	int					think;
	int					nb_eat;
	int					stop;
}				t_philo;

//		parsing		//
int			parse_data(int argc, char **argv, t_main *main);
void		get_data(char **argv, t_main *main);
int			ft_isdigit(int c);
int			ft_check_str(const char *str, int i);
int			ft_atoi(const char *str);
long long	ft_atoll(char *str);
void		ft_bzero(void *s, size_t n);

//		action		//
void		ft_take_fork(t_philo *philo);
void		ft_drop_fork(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_think(t_philo *philo);
void		ft_death(t_philo *philo);

//		time		//
long int	ft_get_time(void);
void		better_usleep(long int time, t_philo *philo);

//		print		//
void		aff_action(t_philo *philo, int action);

//		philo		//
void		*philofunction(void *data);
t_philo		init_philosopher_structure(t_main *main, int id);

//		exit		//
void		clean_philo(t_philo *philo, pthread_t *threads, int j);

//		death		//
int			check_death(t_main *main, t_philo *philo, pthread_t *threads);

//		simulation/main		//
void		start_simulation(t_main *main, t_philo *philo, pthread_t *threads);
int			init_simulation(t_main *main);

#endif
