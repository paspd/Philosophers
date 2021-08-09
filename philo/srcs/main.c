#include "../incs/philo.h"

void	start_simulation(t_main *main, t_philo *philo, pthread_t *threads)
{
	int	i;

	i = -1;
	main->first_time = ft_get_time();
	while (++i != main->info.nb_philo)
	{
		if (pthread_create(&threads[i], NULL, philofunction, &philo[i]))
			philo->main->stop = 1;
	}
	if (check_death(main, philo, threads) == -1)
		return ;
	if (philo->alive && !philo->main->stop)
	{
		i = -1;
		while (++i != main->info.nb_philo)
			pthread_join(threads[i], NULL);
	}
	clean_philo(philo, threads, 1);
}

int	init_simulation(t_main *main)
{
	pthread_t	*threads;
	t_philo		*philo;
	int			i;

	philo = malloc(sizeof(t_philo) * main->info.nb_philo);
	if (philo == NULL)
		return (-1);
	i = -1;
	while (++i < main->info.nb_philo)
	{
		philo[i] = init_philosopher_structure(main, i + 1);
		if (i != 0)
			philo[i].prev_fork = &philo[i - 1].fork;
	}
	philo[0].prev_fork = &philo[i - 1].fork;
	threads = malloc(sizeof(pthread_t) * main->info.nb_philo);
	if (threads == NULL)
	{
		clean_philo(philo, threads, 0);
		return (-1);
	}
	pthread_mutex_init(&main->write, NULL);
	pthread_mutex_init(&main->die, NULL);
	start_simulation(main, philo, threads);
	return (1);
}

int	main(int argc, char **argv)
{
	t_main	main;

	ft_bzero(&main, sizeof(t_main));
	if (argc != 5 && argc != 6)
	{
		printf("Use this format [./philo] [Number_of_philo] [Time_to_die]");
		printf("[Time_to_eat] [Time_to_sleep] [Option]\n");
		printf("\n	Example = ./philo 5 800 200 200\n");
		printf("\nOption = Number_of_times_each_philosopher_must_eat\n");
		printf("\n	Example = ./philo 5 800 200 200 5\n");
		return (-1);
	}
	if (parse_data(argc, argv, &main) == -1)
		return (-1);
	init_simulation(&main);
	return (0);
}
