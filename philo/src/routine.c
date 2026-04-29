/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:46:26 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/29 23:40:53 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*p;
	long	timestamp;

	p = (t_philo *)arg;
	if (p->rules->n_philo == 1)
	{
		pthread_mutex_lock(p->left_fork);
		timestamp = (now_us() - p->rules->start_time) / 1000L;
		print_state(p, "has taken a fork", timestamp);
		pthread_mutex_unlock(p->left_fork);
		return (NULL);
	}
	while (!get_stop(p->rules))
	{
		take_forks(p);
		if (get_stop(p->rules))
		{
			put_forks(p);
			break ;
		}
		eat(p);
		put_forks(p);
		philo_sleep(p);
		think(p);
	}
	return (NULL);
}
