/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:17:30 by amblanch          #+#    #+#             */
/*   Updated: 2024/11/05 10:06:40 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	*so_long(void)
{
	size_t	count;
	size_t	size;
	char	*map;

	count = 0;
	map = ft_verif(count);
	if (map == NULL)
	{
		free(map);
		write(1, "error, invalid or missing map", 30);
		return (0);
	}
	if (ft_init_backtrack(map) == 0)
	{
		free(map);
		write(1, "error, missing path", 19);
		return (0);
	}
	
	return (map);
}

int	main(void)
{
	char	*map;

	map = so_long();
	printf("%s", map);
	free(map);
	return (1);
}
