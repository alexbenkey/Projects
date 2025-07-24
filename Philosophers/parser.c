/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/13 18:17:03 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/07/05 17:56:38 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_mutexes(t_super *super)
{
	pthread_mutex_init(&(super->start), NULL);
	pthread_mutex_init(&(super->pause_all), NULL);
	pthread_mutex_init(&(super->print), NULL);
	super->philos = malloc(sizeof(t_philo *) * (super->count));
	if (!super->philos)
	{
		free (super);
		return (0);
	}
	return (1);
}

void	exit_super(t_super *super)
{
	free (super);
	printf("please make sure that there is at least one philosopher\n");
}

t_super	*parse_input(int argc, char **argv)
{
	t_super	*super;
	int		i;

	i = 0;
	super = malloc(sizeof(t_super));
	super->count = ft_atoi(argv[1]);
	if (!super->count)
	{
		exit_super(super);
		return (NULL);
	}
	super->tt_die = ft_atoi(argv[2]);
	super->time_to_eat = ft_atoi(argv[3]);
	super->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		super->number_of_meals = ft_atoi(argv[5]);
	else
		super->number_of_meals = 0;
	if (init_mutexes(super) == 0)
		return (NULL);
	super->active_count = 0;
	super->halt = 0;
	super->start_time = 0;
	return (super);
}
