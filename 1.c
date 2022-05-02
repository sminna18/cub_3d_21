/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:10:14 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 01:10:14 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_put_pixel(char *pixels, int x, int y, t_color color)
{
	if (x < 0 || y < 0)
		return ;
	pixels[(1500 * y + x) * 4] = (char)color.b;
	pixels[(1500 * y + x) * 4 + 1] = (char)color.g;
	pixels[(1500 * y + x) * 4 + 2] = (char)color.r;
	pixels[(1500 * y + x) * 4 + 3] = (char)color.a;
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.r = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.r, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

int	ft_close(void)
{
	exit(17);
}

int	make_win(t_main *m)
{
	m->win.mlx = mlx_init();
	m->win.win = mlx_new_window(m->win.mlx, 1500, 1000, "CUB3D");
	m->win.x = 1500;
	m->win.y = 1000;
	m->win.draw_w = 1;
	mlx_hook(m->win.win, 17, 0, ft_close, NULL);
	return (1);
}

int	check_int(int i1, int i2, t_main *m)
{
	if (i1 < 0 || i2 < 0 || i1 > m->area.map_h - 1 || i2 > m->area.map_w - 1
		|| (m->area.map)[i1][i2] != '1')
		return (0);
	return (1);
}
