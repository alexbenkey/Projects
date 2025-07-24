/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/13 19:04:31 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/07/04 16:35:49 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->super->print));
	if (!sim_halted(philo->super, 0))
	{
		if (!ft_strncmp(str, "has died", 8))
			printf(M "ms:%lld, philo %d, %s\n" RESET, (time_stmp() - \
			philo->super->start_time), philo->pos + 1, str);
		else if (philo->pos % 2 == 0)
			printf(R "ms:%lld, philo %d, %s\n" RESET, (time_stmp() - \
			philo->super->start_time), philo->pos + 1, str);
		else
			printf(W "ms:%lld, philo %d, %s\n" RESET, (time_stmp() - \
			philo->super->start_time), philo->pos + 1, str);
	}
	pthread_mutex_unlock(&(philo->super->print));
}

void	ft_usleep(int ms, t_super *super)
{
	long long	start_time;

	start_time = time_stmp();
	while ((time_stmp() - start_time) < ms)
	{
		if (sim_halted(super, 0))
			break ;
		usleep(250);
	}
}

long long	time_stmp(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}
