/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:31:14 by amblanch          #+#    #+#             */
/*   Updated: 2024/10/17 12:31:15 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parameter2(int total, const char *s, int i, va_list parameter)
{
	if (s[i + 1] == 'p')
		total += -2 + ft_putnbr_base_p(va_arg(parameter, uintptr_t),
				"0123456789abcdef", 0);
	if (s[i + 1] == 'x')
		total += -2 + ft_putnbr_base(va_arg(parameter, unsigned int),
				"0123456789abcdef", 0);
	if (s[i + 1] == 'X')
		total += -2 + ft_putnbr_base(va_arg(parameter, unsigned int),
				"0123456789ABCDEF", 0);
	if (s[i] == '%' && s[i + 1] == '%')
	{
		write(1, "%", 1);
		--total;
	}
	return (total);
}

static int	ft_parameter(int total, const char *s, int i, va_list parameter)
{
	char	*str;

	if (s[i + 1] == 'c')
		total += ft_putchar(va_arg(parameter, int));
	if (s[i + 1] == 's')
	{
		str = va_arg(parameter, char *);
		if (str == 0)
			total += -2 + ft_putstr("(null)");
		else
			total += -2 + ft_putstr(str);
	}
	if (s[i + 1] == 'd' || s[i + 1] == 'i')
		total += -2 + ft_itoa(va_arg(parameter, int));
	if (s[i + 1] == 'u')
		total += -2 + ft_itoa_long(va_arg(parameter, unsigned int));
	return (total);
}

static int	isvaluable(const char *s, int i)
{
	char	*set;
	int		j;

	set = "csdipxXu%";
	j = 0;
	while (set[j])
	{
		if (set[j] == s[i + 1])
			return (1);
		j++;
	}
	return (0);
}

int	ft_printf(const	char *s, ...)
{
	int		i;
	int		total;
	char	*str;
	va_list	parameter;

	va_start(parameter, s);
	i = 0;
	str = (char *)s;
	total = ft_strlen(str);
	while (s[i])
	{
		if (s[i] == '%')
		{
			total = ft_parameter(total, s, i, parameter);
			total = ft_parameter2(total, s, i, parameter);
			if (isvaluable(s, i))
				i += 2;
		}
		else
		{
			write(1, &s[i], 1);
			if (s[i])
				i++;
		}
	}
	va_end(parameter);
	return (total);
}
