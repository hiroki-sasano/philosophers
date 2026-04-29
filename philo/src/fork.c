/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 20:24:01 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/29 23:28:39 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *p)
{
	long	timestamp;

	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->right_fork);
		timestamp = (now_us() - p->rules->start_time) / 1000L;
		print_state(p, "has taken a fork", timestamp);
		pthread_mutex_lock(p->left_fork);
		timestamp = (now_us() - p->rules->start_time) / 1000L;
		print_state(p, "has taken a fork", timestamp);
	}
	else
	{
		pthread_mutex_lock(p->left_fork);
		timestamp = (now_us() - p->rules->start_time) / 1000L;
		print_state(p, "has taken a fork", timestamp);
		pthread_mutex_lock(p->right_fork);
		timestamp = (now_us() - p->rules->start_time) / 1000L;
		print_state(p, "has taken a fork", timestamp);
	}
	return ;
}

void	put_forks(t_philo *p)
{
	if (p->rules->n_philo == 1)
	{
		pthread_mutex_unlock(p->left_fork);
		return ;
	}
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	return ;
}
