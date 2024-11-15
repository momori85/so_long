/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:09:26 by amblanch          #+#    #+#             */
/*   Updated: 2024/11/05 11:09:34 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "struct_so_long.h"
# include "printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

int	ft_verif(int count, t_vars *vars);
int	ft_init_backtrack(t_vars *vars);
char	*ft_strdup(char *s);
int	ft_graph_init(t_vars *vars);

#endif
