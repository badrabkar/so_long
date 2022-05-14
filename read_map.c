/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:24:17 by babkar            #+#    #+#             */
/*   Updated: 2022/05/14 18:26:42 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_column(char **str)
{
	const char	*line;
	int			fd;
	int			nbr_line;

	fd = open(str[1], O_RDONLY);
	line = get_next_line(fd);
	nbr_line = ft_strlen(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (nbr_line);
		if (ft_strlen(line) != nbr_line)
			puterr();
	}
	return (nbr_line);
}

int	count_line(char **str)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(str[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

t_map	read_map(char **str)
{
	int		fd;
	char	*string;
	t_mlx	mlx;
	int		i;

	i = 0;
	mlx.map.nbr_line = count_line(str);
	if (mlx.map.nbr_line == 0)
		puterr();
	mlx.map.nbr_column = count_column(str);
	mlx.map.str = malloc(mlx.map.nbr_line * sizeof(char *));
	fd = open(str[1], O_RDONLY);
	while (1)
	{
		string = get_next_line(fd);
		if (string == NULL)
			break ;
		mlx.map.str[i] = string;
		i++;
	}
	close(fd);
	return (mlx.map);
}
