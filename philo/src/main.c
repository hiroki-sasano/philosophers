/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:38:58 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/22 00:28:17 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (create_threads(rules.n_philo, philos) != 0)
	{
		destroy_all(&rules, philos);
		return (1);
	}
	if (pthread_create(&monitor, NULL, monitor_routine, philos) != 0)
	{
		set_stop(&rules, 1);
		join_threads(rules.n_philo, philos);
		destroy_all(&rules, philos);
		return (1);
	}
	pthread_join(monitor, NULL);
	join_threads(rules.n_philo, philos);
	destroy_all(&rules, philos);
	return (0);
}
