/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:23:56 by amblanch          #+#    #+#             */
/*   Updated: 2024/10/14 08:23:58 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int count, int i)
{
	while (count > 0)
	{
		count = count / 10;
		i++;
	}
	return (i);
}

static char	*ft_fill(char *str, size_t i, int n, int j)
{
	while (i--)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
	}
	if (j == 1)
		str[0] = '-';
	return (str);
}

static int	ft_param_atoi(int count, size_t i, size_t j)
{
	int		n;
	char	*str;

	n = count;
	i = ft_count(count, i);
	str = ft_calloc(i, sizeof(char));
	if (str == 0)
		return (0);
	str = ft_fill(str, i - 1, n, j);
	count = ft_putstr(str);
	free(str);
	return (count);
}

int	ft_itoa(int n)
{
	int		count;
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	count = n;
	if (count == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (count == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (count < 0)
	{
		++i;
		count = count * -1;
		j = 1;
	}
	count = ft_param_atoi(count, i, j);
	return (count);
}
