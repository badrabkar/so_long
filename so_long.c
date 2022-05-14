/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:27:55 by babkar            #+#    #+#             */
/*   Updated: 2022/05/14 18:31:41 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	map;

	if (ac <= 1)
		exit(0);
	map = read_map(av);
	mlx.map = read_map(av);
	check_map(&map);
	mlx = ft_window(mlx);
	draw_map(mlx);
	mlx_hook(mlx.win, 2, 0, ft_move, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
