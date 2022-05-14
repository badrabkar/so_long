/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:57:11 by babkar            #+#    #+#             */
/*   Updated: 2022/05/14 16:57:14 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_imposter(t_map *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < ptr->nbr_line)
	{
		j = 0;
		while (ptr->str[i][j] != '\0')
		{
			if (ptr->str[i][j] != 'P' && ptr->str[i][j] != '1'
				&& ptr->str[i][j] != '0' && ptr->str[i][j] != 'E'
				&& ptr->str[i][j] != 'C')
				puterr();
			j++;
		}
		i++;
	}
}
