/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:18:50 by babkar            #+#    #+#             */
/*   Updated: 2022/05/14 18:21:09 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_right(t_mlx *mlx)
{
	int	x;
	int	y;

	player_position(mlx);
	x = mlx->pos.x;
	y = mlx->pos.y;
	if (mlx->map.str[x][y + 1] == '0')
	{
		mlx->map.str[x][y] = '0';
		mlx->map.str[x][y + 1] = 'P';
		draw_map(*mlx);
	}
	else if (mlx->map.str[x][y + 1] == 'C')
	{
		mlx->map.str[x][y] = '0';
		mlx->map.str[x][y + 1] = 'P';
		draw_map(*mlx);
	}
	else if (coins_count(mlx) == 0 && mlx->map.str[x][y + 1] == 'E')
		exit(0);
}

void	ft_move_left(t_mlx *mlx)
{
	int	x;
	int	y;

	player_position(mlx);
	x = mlx->pos.x;
	y = mlx->pos.y;
	if (mlx->map.str[x][y - 1] == '0')
	{
		mlx->map.str[x][y] = '0';
		mlx->map.str[x][y - 1] = 'P';
		draw_map(*mlx);
	}
	else if (mlx->map.str[x][y - 1] == 'C')
	{
		mlx->map.str[x][y] = '0';
		mlx->map.str[x][y - 1] = 'P';
		draw_map(*mlx);
	}
	else if (coins_count(mlx) == 0 && mlx->map.str[x][y - 1] == 'E')
		exit(0);
}

void	ft_move_up(t_mlx *mlx)
{
	int	x;
	int	y;

	player_position(mlx);
	x = mlx->pos.x;
	y = mlx->pos.y;
	if (mlx->map.str[x - 1][y] == '0')
	{
		mlx->map.str[x][y] = '0';
		mlx->map.str[x - 1][y] = 'P';
		draw_map(*mlx);
	}
	else if (mlx->map.str[x - 1][y] == 'C')
	{
		mlx->map.str[x][y] = '0';
		mlx->map.str[x - 1][y] = 'P';
		draw_map(*mlx);
	}
	if (coins_count(mlx) == 0 && mlx->map.str[x - 1][y] == 'E')
		exit(0);
}

void	ft_move_down(t_mlx *mlx)
{
	int	x;
	int	y;

	player_position(mlx);
	x = mlx->pos.x;
	y = mlx->pos.y;
	if (mlx->map.str[x + 1][y] == '0')
	{
		mlx->map.str[x][y] = '0';
		mlx->map.str[x + 1][y] = 'P';
		draw_map(*mlx);
	}
	else if (mlx->map.str[x + 1][y] == 'C')
	{
		mlx->map.str[x][y] = '0';
		mlx->map.str[x + 1][y] = 'P';
		draw_map(*mlx);
	}
	if (coins_count(mlx) == 0 && mlx->map.str[x + 1][y] == 'E')
		exit(0);
}

int	ft_move(int keycode, t_mlx *mlx)
{
	if (keycode == D_KEY)
		ft_move_right(mlx);
	if (keycode == A_KEY)
		ft_move_left(mlx);
	if (keycode == W_KEY)
		ft_move_up(mlx);
	if (keycode == S_KEY)
		ft_move_down(mlx);
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}
