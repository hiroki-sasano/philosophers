/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 20:24:01 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/22 00:28:01 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *p)
{
	if (p->rules->n_philo == 1)
	{
		pthread_mutex_lock(p->left_fork);
		print_state(p, "has taken a fork");
		smart_usleep(p->rules->t_die, p->rules);
		return ;
	}
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->right_fork);
		print_state(p, "has taken a fork");
		pthread_mutex_lock(p->left_fork);
		print_state(p, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(p->left_fork);
		print_state(p, "has taken a fork");
		pthread_mutex_lock(p->right_fork);
		print_state(p, "has taken a fork");
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
