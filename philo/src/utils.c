/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:42:30 by hisasano          #+#    #+#             */
/*   Updated: 2026/04/23 19:33:16 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_err(const char *s)
{
	while (*s)
		write(2, s++, 1);
}

int	ft_atoi_pos(const char *s, int *out)
{
	long	n;

	if (!s || *s == '\0')
		return (1);
	n = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (1);
		n = n * 10 + (*s - '0');
		if (n > 2147483647L)
			return (1);
		s++;
	}
	*out = (int)n;
	return (0);
}
