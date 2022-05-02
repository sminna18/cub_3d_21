/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:20:51 by sminna            #+#    #+#             */
/*   Updated: 2022/04/23 23:46:10 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_end_exit(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->map_height)
	{
		free(cub->file[i]);
		i++;
	}
	free(cub->file);
	free(cub);
	exit(1);
}

int	check_extension(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '.')
		i++;
	if (arg[i] && arg[i] == '.' && arg[i + 1] && arg[i + 1] == 'c' && \
	arg[i + 2] && arg[i + 2] == 'u' && arg[i + 3] && arg[i + 3] == 'b' \
	&& !arg[i + 4])
		return (0);
	printf("Error: Wrong file extension\n");
	return (1);
}

int	open_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		printf("Error: File open error\n");
	return (fd);
}

int	file_check(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		printf("Error: Incorrect number of entered arguments\n");
		return (-1);
	}
	if (check_extension(argv[1]))
		return (-1);
	fd = open_file(argv[1]);
	if (fd == -1)
		return (-1);
	return (fd);
}

void	count_file_height(int fd, t_cub *cub)
{
	char	*str;
	int		i;

	i = 1;
	cub->map_height = 0;
	while (i)
	{
		str = get_next_line(fd);
		if (str == NULL && cub->map_height == 0)
		{
			printf("Error: Empty file\n");
			free (cub);
			exit(0);
		}
		if (str)
		{
			cub->map_height++;
			free (str);
		}
		else
			i = 0;
	}
	close(fd);
}
