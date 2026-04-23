/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:05:54 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/22 00:28:40 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *p, char *msg)
{
	long	timestamp;

	pthread_mutex_lock(&p->rules->stop_m);
	pthread_mutex_lock(&p->rules->print_m);
	if (p->rules->stop)
	{
		pthread_mutex_unlock(&p->rules->stop_m);
		pthread_mutex_unlock(&p->rules->print_m);
		return ;
	}
	timestamp = elapsed_ms(p->rules->start_time);
	printf("%ld %d %s\n", timestamp, p->id, msg);
	pthread_mutex_unlock(&p->rules->print_m);
	pthread_mutex_unlock(&p->rules->stop_m);
}
