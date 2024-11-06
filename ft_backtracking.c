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

int	ft_backtracking(char *map, int pos, int len)
{
	//printf("[%d]", len);
	if (map[pos] == 'E')
	{
		printf("[%s]", map);
		return (1);
	}
	else if (map[pos] != '1' && map[pos] != '*')
	{
		map[pos] = '*';
		if (ft_verif_back(map, pos + 1)) // Droite
		{
			//write(1, "a", 1); 
			if (ft_backtracking(map, pos + 1, len))
				return (1);
		}
		if (ft_verif_back(map, pos - 1)) //Gauche
		{
			//write(1, "b", 1);
			if (ft_backtracking(map, pos - 1, len))
				return (1);
		}
		if (ft_verif_back(map, pos + len)) //Bas
		{
			//write(1, "c", 1);
			if (ft_backtracking(map, pos + len, len))
				return (1);
		}
		if (ft_verif_back(map, pos - len)) //Haut
		{
			//write(1, "d", 1);
			if (ft_backtracking(map, pos - len, len))
				return (1);
		}
		map[pos] = '0';
	}
	//write(1, "\n", 1);
	return (0);
}

int	ft_init_backtrack(char *map)
{
	int	i;
	int	a;
	
	if (!seekfor_cpoint(map, 'E'))
		return (0);		
	i = seekfor_cpoint(map, 'P');
	if (!i)
		return (0);
	if (ft_backtracking(map, i, 11))// probleme longueur
		return (1);
	return (0);
}
