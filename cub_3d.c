/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:12:30 by sminna            #+#    #+#             */
/*   Updated: 2022/04/24 01:42:55 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub_3d.h"
#include "cub.h"

void	file_processing(int fd, char *arg, t_cub *cub)
{
	initial_values(cub);
	count_file_height(fd, cub);
	fd = open_file(arg);
	copy_file(fd, cub);
	check_texture(cub);
	check_color_e(cub);
	checking_map_symbols(cub);
	search_accessible_zone(cub);
	search_for_holes(cub);
}

void	copy_map(t_cub *cub)
{
	int	i;
	int	j;
	int	x;

	j = 0;
	while (j < cub->map_height - cub->map_start)
	{
		i = 0;
		x = 0;
		cub->map[j] = malloc(sizeof (char *) * cub->map_width);
		while (i < cub->map_width)
		{
			if (cub->file[j + cub->map_start][i] && cub->file[j + \
			cub->map_start][i] != '\n' && x == 0)
				cub->map[j][i] = cub->file[j + cub->map_start][i];
			else
			{
				cub->map[j][i] = '1';
				x = 1;
			}
			i++;
		}
		j++;
	}
}

void	change_map(t_cub *cub)
{
	int	x;
	int	i;
	int	max_weight;

	x = 0;
	max_weight = 0;
	while (x + cub->map_start < cub->map_height)
	{
		i = 0;
		while (cub->file[x + cub->map_start][i])
		{
			if (cub->file[x + cub->map_start][i] == ' ' || \
			cub->file[x + cub->map_start][i] == '0')
				cub->file[x + cub->map_start][i] = '1';
			if (i > max_weight)
				max_weight = i;
			i++;
		}
		x++;
	}
	cub->map_width = max_weight;
	cub->map = malloc(sizeof (char **) * cub->map_height - cub->map_start);
	cub->map[cub->map_height - cub->map_start] = "\0";
	copy_map(cub);
}

t_cub	*emil(int argc, char **argv)
{
	int		fd;
	t_cub	*cub;

	fd = file_check(argc, argv);
	if (fd == -1)
		return (NULL);
	cub = malloc(sizeof(t_cub));
	file_processing(fd, argv[1], cub);
	change_map(cub);
	cub->map_height = cub->map_height - cub->map_start;
	return (cub);
}
