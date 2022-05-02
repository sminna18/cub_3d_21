/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:10:10 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 01:10:10 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_e(t_main *m)
{
	float	prev_plane_x;

	prev_plane_x = m->pc.plane_x;
	m->pc.pos_a += 0.1f;
	m->pc.plane_x = m->pc.plane_x * cosf(0.1f) - m->pc.plane_y * sinf(0.1f);
	m->pc.plane_y = prev_plane_x * sinf(0.1f) + m->pc.plane_y * cosf(0.1f);
	m->win.draw_w = 1;
	return (1);
}

int	check_key(int key, t_main *main)
{
	if (key == 53)
		ft_close();
	else if (key == 0)
		key_a(main);
	else if (key == 1)
		key_s(main);
	else if (key == 2)
		key_d(main);
	else if (key == 13)
		key_w(main);
	else if (key == 12)
		key_q(main);
	else if (key == 14)
		key_e(main);
	main->win.draw_w = 1;
	return (1);
}

int	mana(t_main *main)
{
	static int	mana;

	mana++;
	if (mana >= 10)
	{
		mana = 0;
		if (main->pc.mana >= 100)
			return (1);
		else
			main->pc.mana++;
	}
	return (0);
}

t_color	get_color_sprite(int y, int x, t_image *sprite, int *i)
{
	t_color	pix;

	if (!sprite || x < 0 || y < 0 || x > sprite->size.x || y > sprite->size.y)
	{
		*i = 0;
		pix.a = 0;
		return (pix);
	}
	pix.b = (int)sprite->pixels[(sprite->size.x * y + x) * 4];
	pix.g = (int)sprite->pixels[(sprite->size.x * y + x) * 4 + 1];
	pix.r = (int)sprite->pixels[(sprite->size.x * y + x) * 4 + 2];
	pix.a = (int)sprite->pixels[(sprite->size.x * y + x) * 4 + 3];
	if (pix.a < 0)
	{
		*i = 0;
		return (pix);
	}
	*i = 1;
	return (pix);
}

int	my_put_image(t_image *screen, t_image *sprite, int x, int y)
{
	t_color	pix;
	int		x_i;
	int		y_i;
	int		i;

	x_i = -1 + x;
	while (++x_i < sprite->size.x + x && x_i < screen->size.x)
	{
		y_i = -1 + y;
		while (++y_i < sprite->size.y + y && y_i < screen->size.y)
		{
			pix = get_color_sprite(y_i - y, x_i - x, sprite, &i);
			if (i == 1)
				my_put_pixel(screen->pixels, x_i, y_i, pix);
		}
	}
	return (1);
}
