/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:39:28 by babkar            #+#    #+#             */
/*   Updated: 2022/05/14 18:40:25 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	ft_window(t_mlx mlx)
{
	int	width;
	int	heigth;

	width = mlx.map.nbr_column * 64;
	heigth = mlx.map.nbr_line * 64;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, width, heigth, "so_long");
	return (mlx);
}
