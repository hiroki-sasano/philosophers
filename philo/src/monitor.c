/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 00:02:13 by hisasano          #+#    #+#             */
/*   Updated: 2026/05/05 15:46:42 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	all_ate_enough(t_philo *philos)
{
	int	i;

	if (philos[0].rules->must_eat == -1)
		return (0);
	i = 0;
	while (i < philos[0].rules->n_philo)
	{
		pthread_mutex_lock(&philos[i].meal_m);
		if (philos[i].eat_count < philos[0].rules->must_eat)
		{
			pthread_mutex_unlock(&philos[i].meal_m);
			return (0);
		}
		pthread_mutex_unlock(&philos[i].meal_m);
		i++;
	}
	return (1);
}

static int	is_dead(t_philo *p, long *timestamp)
{
	long	last_meal;
	long	now;

	pthread_mutex_lock(&p->meal_m);
	last_meal = p->last_meal;
	pthread_mutex_unlock(&p->meal_m);
	now = now_us();
	if (now - last_meal >= p->rules->t_die * 1000L)
	{
		*timestamp = (last_meal + p->rules->t_die * 1000L
				- p->rules->start_time) / 1000L;
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	int		i;
	long	timestamp;

	philos = (t_philo *)arg;
	while (!get_stop(philos[0].rules))
	{
		i = 0;
		while (i < philos[0].rules->n_philo)
		{
			if (is_dead(&philos[i], &timestamp))
			{
				print_death(&philos[i], timestamp);
				return (NULL);
			}
			i++;
		}
		if (all_ate_enough(philos))
		{
			set_stop(philos[0].rules, 1);
			return (NULL);
		}
		usleep(50);
	}
	return (NULL);
}
