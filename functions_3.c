/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:20:51 by sminna            #+#    #+#             */
/*   Updated: 2022/04/23 23:06:36 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_vars(int i, int j, t_cub *cub)
{	
	cub->pos_x = j;
	cub->pos_y = i;
	cub->pos_count++;
	cub->pos_angle = cub->file[i][j];
	cub->file[i][j] = 'o';
}

void	many_player_error(t_cub *cub)
{
	printf("Error: Player position\n");
	free_end_exit(cub);
}

void	checking_map_symbols(t_cub *cub)
{
	int	i;
	int	j;

	i = 8;
	while (i < cub->map_height)
	{
		j = 0;
		while (cub->file[i][j])
		{
			if (cub->file[i][j] == 'N' || cub->file[i][j] == 'S' || \
			cub->file[i][j] == 'E' || cub->file[i][j] == 'W')
				set_vars(i, j, cub);
			else if (cub->file[i][j] != '0' && cub->file[i][j] != '1' && \
			cub->file[i][j] != '\n' && cub->file[i][j] != ' ')
			{
				printf("%d %d %c\n", i, j, cub->file[i][j]);
				printf("Error: Map symbols\n");
				free_end_exit(cub);
			}
			j++;
		}
		i++;
	}
	if (cub->pos_count != 1)
		many_player_error(cub);
}

int	take_o(t_cub *cub, int i, int j, int cykle)
{
	if (cub->file[i][j + 1] && cub->file[i][j + 1] == '0')
	{
		cub->file[i][j + 1] = 'o';
		cykle = 1;
	}
	if (cub->file[i][j - 1] && cub->file[i][j - 1] == '0')
	{
		cub->file[i][j - 1] = 'o';
		cykle = 1;
	}
	if (i + 1 < cub->map_height && cub->file[i + 1][j] && cub->file[i + 1][j] \
	== '0')
	{
		cub->file[i + 1][j] = 'o';
		cykle = 1;
	}
	if (i - 1 >= cub->map_start && cub->file[i - 1][j] && cub->file[i - 1][j] \
	== '0')
	{
		cub->file[i - 1][j] = 'o';
		cykle = 1;
	}
	return (cykle);
}

void	search_accessible_zone(t_cub *cub)
{
	int	cykle;
	int	i;
	int	j;

	cykle = 1;
	while (cykle)
	{
		cykle = 0;
		i = cub->map_start;
		while (i < cub->map_height)
		{
			j = 0;
			while (cub->file[i][j])
			{
				if (cub->file[i][j] == 'o' || (i == cub->pos_y && j \
				== cub->pos_x))
				{
					cykle += take_o(cub, i, j, 0);
				}
				j++;
			}
			i++;
		}
	}
}
