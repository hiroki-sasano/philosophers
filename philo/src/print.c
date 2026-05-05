/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:05:54 by hisasano          #+#    #+#             */
/*   Updated: 2026/05/05 16:29:35 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_death(t_philo *p, long timestamp)
{
	pthread_mutex_lock(&p->rules->stop_m);
	if (p->rules->stop)
	{
		pthread_mutex_unlock(&p->rules->stop_m);
		return ;
	}
	p->rules->stop = 1;
	pthread_mutex_lock(&p->rules->print_m);
	printf("%ld %d died\n", timestamp, p->id);
	pthread_mutex_unlock(&p->rules->print_m);
	pthread_mutex_unlock(&p->rules->stop_m);
}

void	print_state(t_philo *p, char *msg, long timestamp)
{
	pthread_mutex_lock(&p->rules->stop_m);
	pthread_mutex_lock(&p->rules->print_m);
	if (p->rules->stop)
	{
		pthread_mutex_unlock(&p->rules->print_m);
		pthread_mutex_unlock(&p->rules->stop_m);
		return ;
	}
	printf("%ld %d %s\n", timestamp, p->id, msg);
	pthread_mutex_unlock(&p->rules->print_m);
	pthread_mutex_unlock(&p->rules->stop_m);
}
