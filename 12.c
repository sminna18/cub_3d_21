/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:10:02 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 02:36:57 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	make_area(t_area *area, t_main *main, t_cub *cub)
{
	area->map = cub->map;
	area->map_h = cub->map_height;
	area->map_w = cub->map_width;
	area->drow = ft_new_sprite(main->win.mlx, "all.xpm");
	area->wall_l = ft_new_sprite(main->win.mlx, cub->file[2]);
	area->wall_r = ft_new_sprite(main->win.mlx, cub->file[3]);
	area->wall_b = ft_new_sprite(main->win.mlx, cub->file[1]);
	area->wall_f = ft_new_sprite(main->win.mlx, cub->file[0]);
	area->floor = ft_new_sprite(main->win.mlx, "wall.xpm");
	main->ray_c.fon.r = cub->color_f[0];
	main->ray_c.fon.g = cub->color_f[1];
	main->ray_c.fon.b = cub->color_f[2];
	main->ray_c.fon.a = 0;
	main->ray_c.fon_n.r = cub->color_c[0];
	main->ray_c.fon_n.g = cub->color_c[1];
	main->ray_c.fon_n.b = cub->color_c[2];
	main->ray_c.fon.a = 0;
	return (1);
}

int	move_mouse(int x, int y, t_main *m)
{
	static int	change;

	if (x >= 0 && x <= m->win.x && y >= 0 && y <= m->win.y && change != x)
	{
		if (x > change)
			key_e(m);
		else if (x < change)
			key_q(m);
	}
	change = x;
	return (1);
}

int	mouse_button_pr(int key, int x, int y, t_main *m)
{
	if (key == 1)
		m->keys.key_left = 1;
	else if (key == 2)
		m->keys.key_right = 1;
	else if (key == 3)
		m->keys.key_mid = 1;
	else if (key == 5)
		m->keys.key_top = 1;
	else if (key == 4)
		m->keys.key_bot = 1;
	m->keys.x = x;
	m->keys.y = y;
	return (1);
}

int	mouse_button_re(int key, int x, int y, t_main *m)
{
	x = 0;
	y = 0;
	if (key == 1)
		m->keys.key_left = 0;
	return (1);
}

int	make_key(t_key *key)
{
	key->key_bot = 0;
	key->key_top = 0;
	key->key_mid = 0;
	key->key_right = 0;
	key->key_left = 0;
	return (1);
}
