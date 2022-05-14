/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:50:51 by babkar            #+#    #+#             */
/*   Updated: 2022/05/14 16:50:55 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_map *ptr)
{
	int	i;

	i = 0;
	while (ptr->str[0][i] != '\0')
		if (ptr->str[0][i++] != '1')
			puterr();
	i = 0;
	while (ptr->str[ptr->nbr_line - 1][i] != '\0')
		if (ptr->str[ptr->nbr_line - 1][i++] != '1')
			puterr();
	i = 0;
	while (i < ptr->nbr_line)
		if (ptr->str[i++][0] != '1')
			puterr();
	i = 0;
	while (i < ptr->nbr_line)
		if (ptr->str[i++][ptr->nbr_column - 1] != '1')
			puterr();
	if (ptr->nbr_column == ptr->nbr_line)
		puterr();
}

void	check_collectible(t_map *ptr)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < ptr->nbr_line)
	{
		j = 0;
		while (ptr->str[i][j])
		{
			if (ptr->str[i][j] == 'C')
				k++;
			j++;
		}
		i++;
	}
	if (k == 0)
		puterr();
}

void	check_map_exit(t_map *ptr)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < ptr->nbr_line)
	{
		j = 0;
		while (ptr->str[i][j])
		{
			if (ptr->str[i][j] == 'E')
				k++;
			j++;
		}
		i++;
	}
	if (k == 0)
		puterr();
}

void	check_map_player(t_map *ptr)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < ptr->nbr_line)
	{
		j = 0;
		while (ptr->str[i][j])
		{
			if (ptr->str[i][j] == 'P')
				k++;
			j++;
		}
		i++;
	}
	if (k != 1)
		puterr();
}

void	check_map(t_map *ptr)
{
	check_walls(ptr);
	check_collectible(ptr);
	check_map_exit(ptr);
	check_map_player(ptr);
	check_imposter(ptr);
}
