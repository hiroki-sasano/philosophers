/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 20:25:07 by hisasano          #+#    #+#             */
/*   Updated: 2026/05/05 15:43:41 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death_before_eat(t_philo *p, long now, long *timestamp)
{
	pthread_mutex_lock(&p->meal_m);
	if (now - p->last_meal >= p->rules->t_die * 1000L)
	{
		*timestamp = (p->last_meal + p->rules->t_die * 1000L
				- p->rules->start_time) / 1000L;
		pthread_mutex_unlock(&p->meal_m);
		return (1);
	}
	p->last_meal = now;
	pthread_mutex_unlock(&p->meal_m);
	return (0);
}

void	eat(t_philo *p)
{
	long	now;
	long	timestamp;

	now = now_us();
	timestamp = (now - p->rules->start_time) / 1000L;
	if (check_death_before_eat(p, now, &timestamp))
	{
		print_death(p, timestamp);
		return ;
	}
	print_state(p, "is eating", timestamp);
	smart_usleep(p->rules->t_eat, p->rules);
	pthread_mutex_lock(&p->meal_m);
	p->eat_count += 1;
	pthread_mutex_unlock(&p->meal_m);
}

void	philo_sleep(t_philo *p)
{
	long	timestamp;

	timestamp = (now_us() - p->rules->start_time) / 1000L;
	print_state(p, "is sleeping", timestamp);
	smart_usleep(p->rules->t_sleep, p->rules);
}

void	think(t_philo *p)
{
	long	timestamp;

	timestamp = (now_us() - p->rules->start_time) / 1000L;
	print_state(p, "is thinking", timestamp);
	if (p->rules->n_philo % 2 == 1 && p->id % 2 == 1)
		smart_usleep(p->rules->t_eat / 2, p->rules);
}
