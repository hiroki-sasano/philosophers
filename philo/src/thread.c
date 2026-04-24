/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 20:26:00 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/24 17:31:52 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_created_threads(int created, t_philo *p)
{
	int	i;

	i = 0;
	while (i < created)
	{
		pthread_join(p[i].thread, NULL);
		i++;
	}
}

void	join_threads(int n, t_philo *p)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_join(p[i].thread, NULL);
		i++;
	}
}

int	create_threads(int n, t_philo *p)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pthread_create(&p[i].thread, NULL, philo_routine, &p[i]) != 0)
		{
			set_stop(p[0].rules, 1);
			join_created_threads(i, p);
			return (1);
		}
		i++;
	}
	return (0);
}
