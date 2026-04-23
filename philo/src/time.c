/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:42:11 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/22 00:29:12 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	now_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

long	elapsed_ms(long start_ms)
{
	long	now;

	now = now_ms();
	return (now - start_ms);
}

void	smart_usleep(long ms, t_rules *rules)
{
	long	start;

	start = now_ms();
	while (now_ms() - start < ms)
	{
		pthread_mutex_lock(&rules->stop_m);
		if (rules->stop)
		{
			pthread_mutex_unlock(&rules->stop_m);
			break ;
		}
		pthread_mutex_unlock(&rules->stop_m);
		usleep(500);
	}
}

/*1000L ＝　treat as a type long*/