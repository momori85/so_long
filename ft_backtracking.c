/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:25:39 by amblanch          #+#    #+#             */
/*   Updated: 2024/11/05 11:25:41 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	seekfor_cpoint(char *map, char seekfor)
{
	int	i;
	
	i = 0;
	while (map[i] && map[i] != seekfor)
		i++;
	if (i == ft_strlen(map))
		return (0);
	return (i);
}
int	ft_verif_back(char *map, int pos)
{
	if (pos > ft_strlen(map) || pos < 0)
		return (0);
	if (map[pos] == '0' || map[pos] == 'E')
		return (1);
	return (0);
}

int	ft_backtracking(char *map, int pos, size_t len)
{
	if (map[pos] == 'E')
	{
		return (1);
	}
	else if (map[pos] != '1' && map[pos] != '*')
	{
		map[pos] = '*';
		if (ft_verif_back(map, pos + 1)) // Droite
		{
			if (ft_backtracking(map, pos + 1, len))
				return (1);
		}
		if (ft_verif_back(map, pos - 1)) //Gauche
		{
			if (ft_backtracking(map, pos - 1, len))
				return (1);
		}
		if (ft_verif_back(map, pos + len)) //Bas
		{
			if (ft_backtracking(map, pos + len, len))
				return (1);
		}
		if (ft_verif_back(map, pos - len)) //Haut
		{
			if (ft_backtracking(map, pos - len, len))
				return (1);
		}
		map[pos] = '0';
	}
	return (0);
}

int	ft_init_backtrack(t_vars *vars)
{
	int	i;
	char	*tmp;
	
	if (!seekfor_cpoint(vars->map, 'E'))
		return (0);		
	i = seekfor_cpoint(vars->map, 'P');
	if (!i)
		return (0);
	tmp = ft_strdup(vars->map);
	if (ft_backtracking(tmp, i, vars->len) == 0)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}
