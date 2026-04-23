/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:38:58 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/23 19:14:32 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_simulation(t_rules *r, t_philo *p, pthread_t *monitor)
{
	if (create_threads(r->n_philo, p) != 0)
		return (1);
	if (pthread_create(monitor, NULL, monitor_routine, p) != 0)
	{
		set_stop(r, 1);
		join_threads(r->n_philo, p);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_rules		rules;
	t_philo		*philos;
	pthread_t	monitor;

	philos = NULL;
	if (parse_args(&rules, ac, av) != 0)
		return (1);
	if (init_all(&rules, &philos) != 0)
	{
		destroy_all(&rules, philos);
		return (1);
	}
	if (start_simulation(&rules, philos, &monitor) != 0)
	{
		destroy_all(&rules, philos);
		return (1);
	}
	pthread_join(monitor, NULL);
	join_threads(rules.n_philo, philos);
	destroy_all(&rules, philos);
	return (0);
}
