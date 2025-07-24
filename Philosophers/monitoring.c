/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitoring.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 16:05:49 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/07/07 18:41:49 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	sim_halted(t_super *super, int force)
{
	pthread_mutex_lock(&(super->pause_all));
	if (force)
	{
		super->halt = 1;
		return (1);
	}
	if (super->halt)
	{
		pthread_mutex_unlock(&(super->pause_all));
		return (1);
	}
	pthread_mutex_unlock(&(super->pause_all));
	return (0);
}

int	meals_finished(t_super *super)
{
	int	i;
	int	full;

	full = 0;
	i = 0;
	while (i < super->count)
	{
		pthread_mutex_lock(&(super->philos[i]->pause));
		if (super->philos[i]->meals_eaten >= super->number_of_meals)
			full++;
		pthread_mutex_unlock(&(super->philos[i]->pause));
		i++;
	}
	if (full == super->count)
	{
		printf(G "all philos have eaten all of their meals\n" RESET);
		pthread_mutex_lock(&(super->pause_all));
		super->halt = 1;
		pthread_mutex_unlock(&(super->pause_all));
		return (1);
	}
	else
		return (0);
}

int	end_death(t_super *super, int i)
{
	pthread_mutex_unlock(&(super->pause_all));
	pthread_mutex_unlock(&(super->philos[i]->pause));
	print(super->philos[i], "has died");
	sim_halted(super, 1);
	i = 0;
	return (1);
}

int	end_routines(t_super *super)
{
	int	i;
	int	finished;

	finished = 0;
	while (!finished)
	{
		i = 0;
		ft_usleep(1, super);
		while (i < super->count)
		{
			pthread_mutex_lock(&(super->pause_all));
			pthread_mutex_lock(&(super->philos[i]->pause));
			if (((time_stmp() - super->philos[i]->last_meal) >= super->tt_die))
				finished = end_death(super, i);
			pthread_mutex_unlock(&(super->pause_all));
			pthread_mutex_unlock(&(super->philos[i]->pause));
			i++;
		}
		if (!sim_halted(super, 0) && super->number_of_meals)
			finished = meals_finished(super);
	}
	return (0);
}	
