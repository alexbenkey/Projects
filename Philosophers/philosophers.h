/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avon-ben <avon-ben@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/22 18:00:18 by avon-ben      #+#    #+#                 */
/*   Updated: 2023/07/04 16:35:33 by avon-ben      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

//Regular text
# define R "\e[0;31m"
# define G "\e[0;32m"
# define M "\e[0;35m"
# define W "\e[0;37m"

//reset
# define RESET "\033[0m"

enum e_cols
{
	RD = 0,
	WT,
	GR,
	MG,
};

typedef struct s_philo
{
	int				pos;
	pthread_mutex_t	l_fork;
	int				meals_eaten;
	struct s_super	*super;
	long long		last_meal;
	int				is_dead;
	pthread_mutex_t	pause;
}	t_philo;

typedef struct s_super
{
	int				count;
	int				tt_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	int				active_count;
	int				halt;
	long long		start_time;
	pthread_mutex_t	start;
	pthread_mutex_t	print;
	pthread_mutex_t	pause_all;
	struct s_philo	**philos;
}	t_super;

// ACTIONS.C
//----------------------------------------------------------------------------*
//runs individual routine for each philosopher.
void		*philo_life(void *philosopher);

// set super->halt to 1 and set all philos[i]->is_dead to 1;
void		kill_all_philos(t_super *super);
// LIBFT.C
//----------------------------------------------------------------------------*
// comperes n characters of string s1 vs s2 and returns 0 if there are no
// deveations, if there is a discrepancy strncmp will return a value other than 
// 0
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// converts a string into an integer value if it contains only numeric values. 
// will return 0 or -1 if the value falls out of bounds of an int
int			ft_atoi(const char *str);

// GENERATION.C
//----------------------------------------------------------------------------*
//the main function that is executed in each thread. 
//generates a philosopher and runs the simulation untill end conditions are met.
void		*routines(void *i);

//generates an array of philosophers (pointers to structs).
//the array is stored in super->philos.
//returns 0 if generation failed.
int			create_philos(t_super *super);

//MONITORING.C
//----------------------------------------------------------------------------*
// return 1 if the halt value is set to 1;
int			check_halt(t_philo *philo);

// end routines if one of the philosophers has died or had enough meals
int			end_routines(t_super *super);

// returns 1 if the super->halt was set to 1, meaning that the simulations 
// should stop.
int			sim_halted(t_super *super, int force);

// returns 1 and sets super->halt to 1 when all of the philosophers have eaten 
// their meals
int			meals_finished(t_super *super);

//PARSER.C
//----------------------------------------------------------------------------*
//parses the input data and returns a super struct containing the relevant vals
//returns NULL if parsing failed.
t_super		*parse_input(int argc, char **argv);

// UTILS.C
//----------------------------------------------------------------------------*
// print a string according to the specified format
void		print(t_philo *philo, char *str);

// sleeps for 'ms' milliseconds
void		ft_usleep(int ms, t_super *super);

// returns current time
long long	time_stmp(void);

#endif
