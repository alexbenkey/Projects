/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 13:15:19 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/07/07 18:53:44 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	cleaner(t_super *super)
{
	int	i;

	i = 0;
	while (i < super->count)
	{
		pthread_mutex_destroy(&super->philos[i]->pause);
		pthread_mutex_destroy(&super->philos[i]->l_fork);
		free(super->philos[i]);
		i++;
	}
	free (super->philos);
	pthread_mutex_destroy(&super->pause_all);
	pthread_mutex_destroy(&super->start);
	pthread_mutex_destroy(&super->print);
	free (super);
	return (0);
}

static int	not_all_ints(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static void	single_routine(t_super *super)
{
	printf("ms: 0 philo 1 is thinking\n");
	printf("ms: 0 philo 1 has taken a fork\n");
	ft_usleep(super->tt_die, super);
	printf("ms: %d philo 1 has died\n", super->tt_die);
}

void	clean_single(t_super *super)
{
	free (super->philos);
	pthread_mutex_destroy(&super->pause_all);
	pthread_mutex_destroy(&super->start);
	pthread_mutex_destroy(&super->print);
	free (super);
}

int	main(int argc, char **argv)
{
	t_super	*super;

	super = NULL;
	if (!(argc < 5 || argc > 6 || not_all_ints(argv)))
	{
		super = parse_input(argc, argv);
		if (!super)
			return (0);
		if (super->count == 1)
		{
			single_routine(super);
			clean_single(super);
			return (0);
		}
		if (create_philos(super))
			routines(super);
		cleaner(super);
	}
	else
		printf("bad input\nplease use: ./philo [number_of_philos] \
[time_to_die] [time_to_eat] [time_to_sleep] [number of meals(optional)] ");
	return (0);
}
