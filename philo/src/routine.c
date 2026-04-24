/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:46:26 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/24 17:58:38 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
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
