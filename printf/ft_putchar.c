/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:07:12 by amblanch          #+#    #+#             */
/*   Updated: 2024/10/10 15:07:15 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (-1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == 0)
		return (0);
	write(1, s, i = ft_strlen(s));
	return (i);
}
