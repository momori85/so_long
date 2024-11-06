/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:18:34 by amblanch          #+#    #+#             */
/*   Updated: 2024/11/05 11:18:35 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_verif_condition(int fd, char *str, size_t max, size_t count)
{
	if (str[0] != '1' || str[max - 2] != '1')
	{
		close(fd);
		free(str);
		return (0);
	}
	if (max != ft_strlen(str))
	{
		close(fd);
		free(str);
		return (0);
	}
	if (count == max - 2)
	{
		close(fd);
		free(str);
		return (0);
	}
	return (1);
}

static char	*ft_verif_first_last(char *str, size_t max)
{
	size_t	i;

	i = 0;
	while (str[i] && i < max)
	{
		if (str[i] != '1')
			return (NULL);
		i++;
	}
	i = ft_strlen(str);
	while ((i) >= (i - max - 1) && str[i])
	{
		if (str[i] != '1')
		{
			printf("[%zu]", i);
			return (NULL);
		}
		i--;
	}
	return (str);
}

char	*ft_verif(size_t count)
{
	int		fd;
	char	*str;
	char	*map;
	size_t	max;

	fd = open("so_long.ber", O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		return (NULL);
	max = ft_strlen(str);
	map = ft_calloc(1, sizeof(char));
	while (str != NULL)
	{
		if (ft_verif_condition(fd, str, max, count) == 0)
			return (NULL);
		count++;
		map = ft_strjoin(map, str, max - 1);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	map = ft_verif_first_last(map, max - 2);
	return (map);
}
