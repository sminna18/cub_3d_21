/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:20:51 by sminna            #+#    #+#             */
/*   Updated: 2022/04/24 02:19:07 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	search_for_holes(t_cub *cub)
{
	int	i;
	int	j;

	i = cub->map_start;
	while (i < cub->map_height)
	{
		j = 0;
		while (cub->file[i][j])
		{
			if ((cub->file[i][j] == 'o' || cub->file[i][j] == 'N' || \
			cub->file[i][j] == 'W' || cub->file[i][j] == 'S' || \
			cub->file[i][j] == 'E') && hole_check(cub, i, j))
			{
				printf("Error: Map has a hole(%d)(%d)\n", i, j);
				free_end_exit(cub);
			}
			j++;
		}
		i++;
	}
}

void	check_texture(t_cub *cub)
{
	int	t;

	t = 0;
	if (!ft_strncmp(cub->file[0], "NO ", 3))
		t++;
	if (!ft_strncmp(cub->file[1], "SO ", 3))
		t++;
	if (!ft_strncmp(cub->file[2], "WE ", 3))
		t++;
	if (!ft_strncmp(cub->file[3], "EA \n", 3))
		t++;
	if (!ft_strncmp(cub->file[4], "\n", 1))
		t++;
	if (t != 5)
	{
		printf("Error: Texture error\n");
		free_end_exit(cub);
		exit(0);
	}
	path_change(cub);
}

void	path_change(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 3;
		while (cub->file[j][i])
		{
			cub->file[j][i - 3] = cub->file[j][i];
			i++;
		}
		cub->file[j][i - 4] = '\0';
		i = open(cub->file[j], O_RDONLY);
		if (i == -1)
		{
			printf("Error : Not a texture\n");
			exit(1);
		}
		j++;
	}
}

int	hole_check(t_cub *cub, int i, int j)
{
	if (!cub->file[i][j + 1] || cub->file[i][j + 1] == ' ' || \
	cub->file[i][j + 1] == '\n')
		return (1);
	if (!cub->file[i][j - 1] || cub->file[i][j - 1] == ' ' || \
	cub->file[i][j - 1] == '\n')
		return (1);
	if (i + 1 >= cub->map_height || !cub->file[i + 1][j] || \
	cub->file[i + 1][j] == ' ' || cub->file[i + 1][j] == '\n')
		return (1);
	if (i - 1 < cub->map_start || !cub->file[i - 1][j] || \
	cub->file[i - 1][j] == ' ' || cub->file[i - 1][j] == '\n')
		return (1);
	return (0);
}

void	initial_values(t_cub *cub)
{
	cub->pos_count = 0;
	cub->map_start = 8;
}
