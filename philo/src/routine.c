/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:46:26 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/22 00:28:47 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
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

// 哲学者は「食べる・考える・寝る」を繰り返す
// get fork → eat → put_fork → sleep → think