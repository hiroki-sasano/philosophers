/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:41:07 by hisasano          #+#    #+#             */
/*   Updated: 2026/03/19 18:16:41 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_int(const char *s, int *dst)
{
	if (ft_atoi_pos(s, dst) != 0)
		return (1);
	return (0);
}

static int	set_long_from_int(const char *s, long *dst)
{
	int	tmp;

	if (ft_atoi_pos(s, &tmp) != 0)
		return (1);
	*dst = (long)tmp;
	return (0);
}

// if (parse_args(&rules, ac, av) != 0)
int	parse_args(t_rules *r, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (put_err("Error: bad args\n"), 1);
	if (set_int(av[1], &r->n_philo) || r->n_philo <= 0)
		return (put_err("Error: n_philo\n"), 1);
	if (set_long_from_int(av[2], &r->t_die) || r->t_die <= 0)
		return (put_err("Error: time_to_die\n"), 1);
	if (set_long_from_int(av[3], &r->t_eat) || r->t_eat <= 0)
		return (put_err("Error: time_to_eat\n"), 1);
	if (set_long_from_int(av[4], &r->t_sleep) || r->t_sleep <= 0)
		return (put_err("Error: time_to_sleep\n"), 1);
	r->must_eat = -1;
	if (ac == 6)
	{
		if (set_int(av[5], &r->must_eat) || r->must_eat <= 0)
			return (put_err("Error: must_eat\n"), 1);
	}
	r->forks = NULL;
	r->stop = 0;
	r->start_time = 0;
	return (0);
}
