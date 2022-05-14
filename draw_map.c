/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:03:13 by babkar            #+#    #+#             */
/*   Updated: 2022/05/14 17:03:17 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_mlx mlx, char *path, int j, int i)
{
	t_img	img;

	img.width = 64;
	img.height = 64;
	img.img = mlx_xpm_file_to_image(mlx.mlx, path, &img.width, &img.height);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, j * 64, i * 64);
}

void	draw_map(t_mlx mlx)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx_clear_window(mlx.mlx, mlx.win);
	while (i < mlx.map.nbr_line)
	{
		j = 0;
		while (mlx.map.str[i][j] != '\0')
		{
			if (mlx.map.str[i][j] == '1')
				put_image(mlx, "./xpm/wall.xpm", j, i);
			if (mlx.map.str[i][j] == 'C')
				put_image(mlx, "./xpm/coin.xpm", j, i);
			if (mlx.map.str[i][j] == 'E')
				put_image(mlx, "./xpm/door.xpm", j, i);
			if (mlx.map.str[i][j] == 'P')
				put_image(mlx, "./xpm/player.xpm", j, i);
			j++;
		}
		i++;
	}
}
