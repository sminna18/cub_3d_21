/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:20:51 by sminna            #+#    #+#             */
/*   Updated: 2022/04/23 23:28:19 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	copy_file(int fd, t_cub *cub)
{
	int	i;

	i = 0;
	cub->file = malloc(sizeof (char **) * cub->map_height);
	if (!cub->file)
	{
		printf("Error: malloc");
		exit(0);
	}
	while (i < cub->map_height)
	{
		cub->file[i] = get_next_line(fd);
		i++;
	}
}

void	print_free_exit(t_cub *cub)
{
	printf("Error: Color error(3)\n");
	free_end_exit(cub);
}

void	color_write(char *str, int *nums, t_cub *cub, int i)
{
	int	c;
	int	n;
	int	x;

	c = 0;
	n = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			c++;
		else if (str[i] == ',' || str[i] == '\n')
		{
			str[i] = '\0';
			nums[n] = ft_atoi(str + x);
			x = i + 1;
			n++;
			c = 0;
		}
		else
			c = 4;
		if (n == 4 || c > 3)
			print_free_exit(cub);
		i++;
	}
}

void	checking_borders_of_colors(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (cub->color_f[i] > 255)
		{
			printf("Error: Color error(4)\n");
			free_end_exit(cub);
		}
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (cub->color_c[i] > 255)
		{
			printf("Error: Color error(4)\n");
			free_end_exit(cub);
		}
		i++;
	}
}

void	check_color_e(t_cub *cub)
{
	int	t;

	t = 0;
	if (!ft_strncmp(cub->file[5], "F ", 2))
		t++;
	if (!ft_strncmp(cub->file[6], "C ", 2))
		t++;
	if (!ft_strncmp(cub->file[7], "\n", 1))
		t++;
	if (t != 3)
	{
		printf("Error: Color error(1)\n");
		free_end_exit(cub);
	}
	color_write(cub->file[5] + 2, cub->color_f, cub, 0);
	color_write(cub->file[6] + 2, cub->color_c, cub, 0);
	checking_borders_of_colors(cub);
}
