/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 21:12:15 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/23 19:05:17 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_stop(t_rules *r)
{
	int	stop;

	pthread_mutex_lock(&r->stop_m);
	stop = r->stop;
	pthread_mutex_unlock(&r->stop_m);
	return (stop);
}

void	set_stop(t_rules *r, int value)
{
	pthread_mutex_lock(&r->stop_m);
	r->stop = value;
	pthread_mutex_unlock(&r->stop_m);
}
