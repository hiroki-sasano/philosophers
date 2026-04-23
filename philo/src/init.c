/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:41:32 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/19 23:31:09 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutexes(t_rules *r)
{
	if (pthread_mutex_init(&r->print_m, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&r->stop_m, NULL) != 0)
	{
		pthread_mutex_destroy(&r->print_m);
		return (1);
	}
	return (0);
}

static int	init_forks(t_rules *r)
{
	int	i;

	r->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * r->n_philo);
	if (!r->forks)
		return (1);
	i = 0;
	while (i < r->n_philo)
	{
		if (pthread_mutex_init(&r->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

static void	assign_forks(t_rules *r, t_philo *p, int i)
{
	p[i].left_fork = &r->forks[i];
	p[i].right_fork = &r->forks[(i + 1) % r->n_philo];
}

static void	init_philos_fields(t_rules *r, t_philo *p)
{
	int	i;

	i = 0;
	while (i < r->n_philo)
	{
		p[i].id = i + 1;
		p[i].eat_count = 0;
		p[i].rules = r;
		p[i].last_meal = r->start_time;
		assign_forks(r, p, i);
		pthread_mutex_init(&p[i].meal_m, NULL);
		i++;
	}
}

int	init_all(t_rules *r, t_philo **philos)
{
	*philos = NULL;
	if (init_mutexes(r) != 0)
		return (put_err("Error: mutex init\n"), 1);
	r->start_time = now_ms();
	if (init_forks(r) != 0)
		return (put_err("Error: forks init\n"), 1);
	*philos = (t_philo *)malloc(sizeof(t_philo) * r->n_philo);
	if (!*philos)
		return (put_err("Error: philos malloc\n"), 1);
	init_philos_fields(r, *philos);
	return (0);
}
