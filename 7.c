/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:10:06 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 01:10:06 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	draw_mana(t_main *m)
{
	int		x;
	int		y;
	t_color	c_mana;

	y = 930;
	c_mana.a = 0;
	c_mana.r = 0;
	c_mana.g = 0;
	c_mana.b = 255;
	while (y < 970)
	{
		x = 105;
		while (x < 2 * m->pc.mana + 95)
		{
			my_put_pixel(m->area.drow.pixels, x, y, c_mana);
			x++;
		}
		y++;
	}
	return (1);
}

int	dark_blue(int r)
{
	if (r < 0)
		r += 255;
	r = r - 20;
	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;
	return (r);
}

int	dark_green(int r)
{
	if (r < 0)
		r += 255;
	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;
	return (r);
}

int	dark_red(int r)
{
	if (r < 0)
		r += 255;
	r = r + 20;
	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;
	return (r);
}

int	dark(char *i, char *rez, double index)
{
	int	r;

	if (index < 1.0)
		index = 1.0;
	r = (int)*rez;
	r = dark_blue(r);
	*i = (char)(r / index);
	i++;
	rez++;
	r = (int)*rez;
	r = dark_green(r);
	*i = (char)(r / index);
	i++;
	rez++;
	r = (int)*rez;
	r = dark_red(r);
	*i = (char)(r / index);
	i++;
	rez++;
	r = (int)*rez;
	if (r < 0)
		r += 255;
	*i = (char)(r / index);
	return (1);
}
