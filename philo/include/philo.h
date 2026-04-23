/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:02:20 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/23 19:02:57 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_rules
{
	int				n_philo;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				must_eat;
	long			start_time;
	int				stop;
	pthread_mutex_t	print_m;
	pthread_mutex_t	stop_m;
	pthread_mutex_t	*forks;
}					t_rules;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_m;
	t_rules			*rules;
}					t_philo;

int					parse_args(t_rules *r, int ac, char **av);
int					init_all(t_rules *r, t_philo **philos);
void				destroy_all(t_rules *r, t_philo *philos);
long				now_ms(void);
long				elapsed_ms(long start_ms);
void				smart_usleep(long ms, t_rules *rules);
void				print_state(t_philo *p, char *msg);
int					create_threads(int n, t_philo *p);
void				join_threads(int n_philo, t_philo *philos);
void				*philo_routine(void *arg);
void				take_forks(t_philo *p);
void				put_forks(t_philo *p);
void				eat(t_philo *p);
void				philo_sleep(t_philo *p);
void				think(t_philo *p);
int					get_stop(t_rules *r);
void				set_stop(t_rules *r, int value);
int					ft_atoi_pos(const char *s, int *out);
void				put_err(const char *s);
void				*monitor_routine(void *arg);

#endif

// lock order: stop_m → print_m → meal_m
