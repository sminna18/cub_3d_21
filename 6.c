/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:10:06 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 01:10:06 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_back_side(t_main *m, int tex_x, int tex_y)
{
	if (m->ray_c.side == 0 && m->ray_c.ray_d_x > 0)
		tex_x = (int) m->ray_c.ray_d_x - tex_x - 1;
	if (m->ray_c.side == 1 && m->ray_c.ray_d_y < 0)
		tex_x = (int) m->ray_c.ray_d_y - tex_x - 1;
	m->ray_c.step = 1.0 * m->area.wall_b.size.y / m->ray_c.line_height;
	m->ray_c.tex_pos = (m->ray_c.ceil - m->win.y / 2 + m->ray_c.line_height / 2)
		* m->ray_c.step;
	m->ray_c.y = m->ray_c.ceil - 1;
	while (++m->ray_c.y <= m->ray_c.floor)
	{
		tex_y = (int) m->ray_c.tex_pos;
		m->ray_c.tex_pos += m->ray_c.step;
		if (tex_y < 0)
			tex_y += 1000;
		if (tex_x < 0)
			tex_x += 1001;
		if (tex_y >= 1000)
			tex_y -= 1000;
		if (tex_x >= 1000)
			tex_x -= 1000;
		dark(&m->area.drow.pixels[(m->area.drow.size.x * m->ray_c.y
				+ m->ray_c.x) * 4],
			&m->area.wall_b.pixels[(m->area.wall_b.size.x * tex_y + tex_x)
			* 4], m->ray_c.dist_w);
	}
}

void	draw_x_line5(t_main *m)
{
	int	tex_x;
	int	tex_y;

	tex_x = (int)(m->ray_c.wall_x * (double)(m->area.wall_l.size.x));
	tex_y = 0;
	if (m->ray_c.side == 0 && m->ray_c.ray_d_x > 0)
	{
		draw_left_side(m, tex_x, tex_y);
	}
	else if (m->ray_c.side == 0)
	{
		draw_right_side(m, tex_x, tex_y);
	}
	else if (m->ray_c.side == 1 && m->ray_c.ray_d_y > 0)
	{
		draw_forward_side(m, tex_x, tex_y);
	}
	else if (m->ray_c.side == 1)
	{
		draw_back_side(m, tex_x, tex_y);
	}
}

void	draw_x_line(t_main *m)
{
	draw_x_line1(m);
	draw_x_line2(m);
	draw_x_line3(m);
	draw_x_line4(m);
	draw_x_line5(m);
	if (m->bonus == 1)
		draw_fon_floor_ceil(m);
	else if (m->bonus == 2)
		draw_textures_floor_ceil(m);
}

int	draw_wall(t_main *m)
{
	m->ray_c.x = -1;
	m->ray_c.dir_y = sinf(m->pc.pos_a);
	m->ray_c.dir_x = cosf(m->pc.pos_a);
	while (++m->ray_c.x < m->win.x)
	{
		draw_x_line(m);
	}
	return (1);
}

int	check_color(int x, int y, t_image *all, t_color m_wall)
{
	char	*pixels;

	pixels = all->pixels;
	if (pixels[(1500 * y + x) * 4] != m_wall.b)
		return (0);
	else if (pixels[(1500 * y + x) * 4 + 1] != m_wall.g)
		return (0);
	else if (pixels[(1500 * y + x) * 4 + 2] != m_wall.r)
		return (0);
	return (1);
}
