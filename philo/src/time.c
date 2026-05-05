/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:42:11 by hisasano          #+#    #+#             */
/*   Updated: 2026/05/05 16:23:23 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	now_us(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	return ((tv.tv_sec * 1000000L) + (tv.tv_usec));
}

long	elapsed_ms(long start_us)
{
	long	now;

	now = now_us();
	return ((now - start_us) / 1000L);
}

void	smart_usleep(long ms, t_rules *rules)
{
	long	start;

	start = now_us();
	while (now_us() - start < ms * 1000L)
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

// return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
// time_to_death == 100
// 100.999ms -> 200.000ms = 99.001ms
// 100ms -> 200ms = 100ms
// Died 0.999 milliseconds ahead of schedule
