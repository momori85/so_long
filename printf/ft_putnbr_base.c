/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:49:14 by amblanch          #+#    #+#             */
/*   Updated: 2024/07/22 11:49:17 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nbr, char *base, int count)
{
	if (nbr >= 16)
		count = ft_putnbr_base(nbr / 16, base, count);
	write(1, &base[nbr % 16], 1);
	count++;
	return (count);
}

int	ft_putnbr_base_p(uintptr_t nbr, char *base, int is_rec)
{
	int	count;

	count = 0;
	if (!nbr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (!is_rec)
	{
		write(1, "0x", 2);
		count += 2;
	}
	if (nbr > 15)
		count += ft_putnbr_base_p(nbr / 16, base, 1);
	count += 1;
	write(1, &base[nbr % 16], 1);
	return (count);
}
