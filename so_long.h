/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:40:30 by babkar            #+#    #+#             */
/*   Updated: 2022/05/14 18:45:00 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./get_next_line/get_next_line.h"
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define ESC_KEY 53

typedef struct s_map
{
	int		nbr_line;
	int		nbr_column;
	char	**str;
}	t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_img
{
	char	*path;
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	t_pos	pos;
}	t_mlx;

void	putstr(char *str);
void	puterr(void);
void	check_map(t_map *ptr);
void	check_imposter(t_map *ptr);
t_map	read_map(char **str);
void	draw_map(t_mlx mlx);
int		ft_move(int keycode, t_mlx *mlx);
int		coins_count(t_mlx *mlx);
void	player_position(t_mlx *mlx);
t_mlx	ft_window(t_mlx mlx);
#endif
