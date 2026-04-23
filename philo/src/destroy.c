/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:41:52 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/22 00:27:50 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_all(t_rules *r, t_philo *p)
{
	int	i;

	if (r->forks)
	{
		i = 0;
		while (i < r->n_philo)
		{
			pthread_mutex_destroy(&r->forks[i]);
			i++;
		}
		free(r->forks);
		r->forks = NULL;
	}
	pthread_mutex_destroy(&r->print_m);
	pthread_mutex_destroy(&r->stop_m);
	i = 0;
	while (i < r->n_philo)
	{
		pthread_mutex_destroy(&p[i].meal_m);
		i++;
	}
	free(p);
}
