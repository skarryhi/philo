/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:48:39 by skarry            #+#    #+#             */
/*   Updated: 2020/11/17 14:05:27 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <semaphore.h>
# include <signal.h>

# define WHITE	"\x1B[0m"
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define BOLD	"\033[1m"

typedef	struct		s_table
{
	int				philo;
	int				t2die;
	int				t2eat;
	int				t2sleep;
	int				count_eat;
	int				die;
	sem_t			*waiter;
	sem_t			*sem_die;
	sem_t			*sem_print;
	sem_t			*sem_time;
	sem_t			*sem_fork;
	sem_t			*end_of_eat;
	sem_t			*exit;
}					t_table;

typedef	struct		s_philo
{
	int				id;
	int				birth;
	int				last_meal;
	int				count_eat;
	t_table			*table;
}					t_philo;

int					put_table(t_table *table, int ac, char **av);
void				ft_putstr(char *s);
void				*simulation(void *philo);
void				init_philo(t_table *table);
int					get_time(void);
void				ft_putstr(char *s);
void				ft_print(t_philo *philo, char *str, int flag);
void				ft_wait(int time);

#endif
