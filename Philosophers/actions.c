/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:08:59 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 01:25:10 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	start_eating(t_philo *philo)
{	
	if (philo->pos == (philo->super->count - 1))
		pthread_mutex_lock(&(philo->super->philos[0]->l_fork));
	else
		pthread_mutex_lock(&(philo->super->philos[philo->pos + 1]->l_fork));

	print(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->l_fork));

	print(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->pause));

	philo->last_meal = time_stmp();
	philo->meals_eaten++;
	
	pthread_mutex_unlock(&(philo->pause));
	print(philo, "is eating");
	ft_usleep(philo->super->time_to_eat, philo->super);
	pthread_mutex_unlock(&(philo->l_fork));
	if (philo->pos == (philo->super->count - 1))
		pthread_mutex_unlock(&(philo->super->philos[0]->l_fork));
	else
		pthread_mutex_unlock(&(philo->super->philos[philo->pos + 1]->l_fork));
}

static void	start_sleeping(t_philo *philo)
{
	print(philo, "is sleeping");
	ft_usleep(philo->super->time_to_sleep, philo->super);
}

void	*philo_life(void *philosopher)
{
	t_philo		*philo;

	philo = (t_philo *)philosopher;
	pthread_mutex_lock(&(philo->super->start));
	pthread_mutex_unlock(&(philo->super->start));
	print(philo, "is thinking");
	if (!(philo->pos % 2 == 0))
		ft_usleep(philo->super->time_to_eat / 10, philo->super);
	while (!sim_halted(philo->super, 0))
	{
		start_eating(philo);
		start_sleeping(philo);
		print(philo, "is thinking");
	}
	return (NULL);
}
