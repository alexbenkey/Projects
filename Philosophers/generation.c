/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 15:36:35 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/07/07 18:52:54 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	detach(pthread_t *threads, int j)
{
	int	i;	

	i = 0;
	while (i < j)
	{
		pthread_detach(*(threads + i));
		i++;
	}
}

static void	set_start_times(t_super *super)
{
	int	i;

	i = 0;
	super->start_time = time_stmp();
	while (i < super->count)
	{
		super->philos[i]->last_meal = super->start_time;
		i++;
	}
	pthread_mutex_unlock(&(super->start));
}

static int	generate_threads(pthread_t *threads, t_super *super)
{
	int			i;

	i = 0;
	while (i < super->count)
	{		
		if (pthread_create(threads + i, NULL, &philo_life, \
		super->philos[i]) != 0)
		{
			printf("error creating threads\n");
			detach(threads, i);
			free(threads);
			return (0);
		}
		i++;
	}
	return (1);
}

void	*routines(void *superstruct)
{
	t_super		*super;
	pthread_t	*threads;
	int			i;

	i = 0;
	super = (t_super *)superstruct;
	threads = malloc(sizeof(pthread_t) * (super->count));
	if (!threads)
	{
		printf("failure in allocating memory for threads\n");
		return (NULL);
	}
	pthread_mutex_lock(&(super->start));
	if (!generate_threads(threads, super))
		return (NULL);
	set_start_times(super);
	end_routines(super);
	i = 0;
	while (i < super->count)
		pthread_join(threads[i++], NULL);
	free (threads);
	return (NULL);
}

int	create_philos(t_super *super)
{
	int			i;

	i = 0;
	while (i < (super->count))
	{	
		super->philos[i] = malloc(sizeof(t_philo));
		if (!super->philos[i])
			return (0);
		super->philos[i]->super = super;
		pthread_mutex_init(&super->philos[i]->l_fork, NULL);
		pthread_mutex_init(&super->philos[i]->pause, NULL);
		super->philos[i]->pos = i;
		super->philos[i]->meals_eaten = 0;
		super->philos[i]->last_meal = 0;
		super->philos[i]->is_dead = 0;
		i++;
	}
	return (1);
}
