/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:17:04 by babkar            #+#    #+#             */
/*   Updated: 2022/05/14 18:18:43 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mlx->map.nbr_line)
	{
		j = 0;
		while (mlx->map.str[i][j] != '\0')
		{
			if (mlx->map.str[i][j] == 'P')
			{
				mlx->pos.x = i;
				mlx->pos.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	coins_count(t_mlx *mlx)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (i < mlx->map.nbr_line)
	{
		j = 0;
		while (mlx->map.str[i][j] != '\0')
		{
			if (mlx->map.str[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
