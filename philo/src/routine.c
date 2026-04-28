/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:46:26 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/28 14:54:18 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->rules->n_philo == 1)
	{
		pthread_mutex_lock(p->left_fork);
		print_state(p, "has taken a fork");
		pthread_mutex_unlock(p->left_fork);
		return (NULL);
	}
	if (p->id % 2 == 0)
		smart_usleep(p->rules->t_eat / 2, p->rules);
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
