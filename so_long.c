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

char	*ft_strdup(char *s)
{
	int		i;
	int	j;
	char		*str;

	i = ft_strlen(s);
	j = 0;
	str = malloc(sizeof (char) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

int	so_long(void)
{
	int	count;
	t_vars	vars;

	count = 0;
	if (ft_verif(count, &vars) == 0)
	{
		free(vars.map);
		write(1, "error, invalid or missing map", 30);
		return (0);
	}
	/*if (ft_init_backtrack(&vars) == 0)
	{
		free(vars.map);
		write(1, "error, missing path", 19);
		return (0);
	}*/
	if (ft_graph_init(&vars) == 0)
	{
		free(vars.map);
		return (0);
	}
	printf("%s\n", vars.map);
	free(vars.map);
	return (1);
}

int	main(void)
{
	so_long();
}
