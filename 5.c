/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:10:07 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 01:10:27 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_x_line3(t_main *m)
{
	while (m->ray_c.find_wall == 0 && m->ray_c.map_x < m->area.map_w
		&& m->ray_c.map_y < m->area.map_h)
	{
		if (m->ray_c.side_dist_x < m->ray_c.side_dist_y)
		{
			m->ray_c.side_dist_x += m->ray_c.delta_dist_x;
			m->ray_c.map_x += m->ray_c.step_x;
			m->ray_c.side = 0;
		}
		else
		{
			m->ray_c.side_dist_y += m->ray_c.delta_dist_y;
			m->ray_c.map_y += m->ray_c.step_y;
			m->ray_c.side = 1;
		}
		if (m->ray_c.map_x < m->area.map_w && m->ray_c.map_y < m->area.map_h
			&& m->area.map[m->ray_c.map_y][m->ray_c.map_x] != 'o')
			m->ray_c.find_wall = 1;
	}
}

void	draw_x_line4(t_main *m)
{
	if (m->ray_c.side == 0)
		m->ray_c.dist_w = (float)(m->ray_c.side_dist_x - m->ray_c.delta_dist_x);
	else
		m->ray_c.dist_w = (float)(m->ray_c.side_dist_y - m->ray_c.delta_dist_y);
	m->ray_c.ceil = (int)((float)(m->win.y / 2.0) - (float)m->win.y
			/ ((float)m->ray_c.dist_w));
	m->ray_c.floor = m->win.y - m->ray_c.ceil;
	m->ray_c.line_height = (int)((float)m->win.y / m->ray_c.dist_w);
	m->ray_c.ceil = -m->ray_c.line_height / 2 + m->win.y / 2;
	if (m->ray_c.ceil < 0)
		m->ray_c.ceil = 0;
	m->ray_c.floor = m->ray_c.line_height / 2 + m->win.y / 2;
	if (m->ray_c.floor >= m->win.y)
		m->ray_c.floor = m->win.y - 1;
	m->ray_c.x_for_get = (float)m->pc.pos_x + (float)m->ray_c.ray_d_x
		* m->ray_c.dist_w;
	m->ray_c.y_for_get = (float)m->pc.pos_y + (float)m->ray_c.ray_d_y
		* m->ray_c.dist_w;
	if (m->ray_c.side == 0)
		m->ray_c.wall_x = m->pc.pos_y + m->ray_c.dist_w * m->ray_c.ray_d_y;
	else
		m->ray_c.wall_x = m->pc.pos_x + m->ray_c.dist_w * m->ray_c.ray_d_x;
	m->ray_c.wall_x = m->ray_c.wall_x - floor(m->ray_c.wall_x);
}

void	draw_left_side(t_main *m, int tex_x, int tex_y)
{
	if (m->ray_c.side == 0 && m->ray_c.ray_d_x > 0)
		tex_x = (int) m->ray_c.ray_d_x - tex_x - 1;
	if (m->ray_c.side == 1 && m->ray_c.ray_d_y < 0)
		tex_x = (int) m->ray_c.ray_d_y - tex_x - 1;
	m->ray_c.step = 1.0 * m->area.wall_l.size.y / m->ray_c.line_height;
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
			&m->area.wall_l.pixels[(m->area.wall_l.size.x * tex_y + tex_x)
			* 4], m->ray_c.dist_w);
	}
}

void	draw_forward_side(t_main *m, int tex_x, int tex_y)
{
	if (m->ray_c.side == 0 && m->ray_c.ray_d_x > 0)
		tex_x = (int) m->ray_c.ray_d_x - tex_x - 1;
	if (m->ray_c.side == 1 && m->ray_c.ray_d_y < 0)
		tex_x = (int) m->ray_c.ray_d_y - tex_x - 1;
	m->ray_c.step = 1.0 * m->area.wall_f.size.y / m->ray_c.line_height;
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
			&m->area.wall_f.pixels[(m->area.wall_f.size.x * tex_y + tex_x)
			* 4], m->ray_c.dist_w);
	}
}

void	draw_right_side(t_main *m, int tex_x, int tex_y)
{
	if (m->ray_c.side == 0 && m->ray_c.ray_d_x > 0)
		tex_x = (int) m->ray_c.ray_d_x - tex_x - 1;
	if (m->ray_c.side == 1 && m->ray_c.ray_d_y < 0)
		tex_x = (int) m->ray_c.ray_d_y - tex_x - 1;
	m->ray_c.step = 1.0 * m->area.wall_r.size.y / m->ray_c.line_height;
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
			&m->area.wall_r.pixels[(m->area.wall_r.size.x * tex_y + tex_x)
			* 4], m->ray_c.dist_w);
	}
}
