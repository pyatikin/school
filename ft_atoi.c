/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:33:38 by tgwin             #+#    #+#             */
/*   Updated: 2022/02/08 18:32:37 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *s)
{
	int			z;
	size_t		n;

	z = 1;
	n = 0;
	while (*s == ' ' || (*s) == '\t' || (*s) == '\n'
		|| (*s) == '\v' || (*s) == '\f' || (*s) == '\r' )
		s++;
	if ((*s == '-') || (*s == '+'))
	{
		if (*s == '-')
			z = -1;
		s++;
	}
	while (*s >= '0' && (*s) <= '9')
	{
		if (n > 2147483648)
			break ;
		n = 10 * n + *(s++) - '0';
	}
	if (z == 1 && (n > (2147483647)))
		return (0);
	if (z == -1 && (n > (2147483648)))
		return (0);
	return (z * n);
}
