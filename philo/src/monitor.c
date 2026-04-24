/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 00:02:13 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/24 20:34:08 by hisasano         ###   ########.fr       */
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

static int	is_dead(t_philo *p)
{
	long	last_meal;
	long	now;

	pthread_mutex_lock(&p->meal_m);
	last_meal = p->last_meal;
	pthread_mutex_unlock(&p->meal_m);
	now = now_ms();
	if (now - last_meal >= p->rules->t_die)
		return (1);
	return (0);
}

static void	print_death(t_philo *p)
{
	long	timestamp;

	pthread_mutex_lock(&p->rules->stop_m);
	if (p->rules->stop)
	{
		pthread_mutex_unlock(&p->rules->stop_m);
		return ;
	}
	p->rules->stop = 1;
	pthread_mutex_lock(&p->rules->print_m);
	timestamp = elapsed_ms(p->rules->start_time);
	printf("%ld %d died\n", timestamp, p->id);
	pthread_mutex_unlock(&p->rules->print_m);
	pthread_mutex_unlock(&p->rules->stop_m);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	while (!get_stop(philos[0].rules))
	{
		i = 0;
		while (i < philos[0].rules->n_philo)
		{
			if (is_dead(&philos[i]))
			{
				print_death(&philos[i]);
				return (NULL);
			}
			i++;
		}
		if (all_ate_enough(philos))
		{
			set_stop(philos[0].rules, 1);
			return (NULL);
		}
	}
	return (NULL);
}
