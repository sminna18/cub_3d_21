/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:10:08 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 01:10:08 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_fon_floor_ceil(t_main *m)
{
	if (m->ray_c.floor < 0)
		m->ray_c.floor = m->win.y;
	m->ray_c.y = m->ray_c.floor;
	while (++m->ray_c.y < m->win.y)
	{
		my_put_pixel(m->area.drow.pixels, m->ray_c.x,
			m->ray_c.y, m->ray_c.fon_n);
		my_put_pixel(m->area.drow.pixels, m->ray_c.x,
			m->win.y - m->ray_c.y, m->ray_c.fon);
	}
}

void	draw_textures_floor_ceil_1(t_main *m)
{
	if (m->ray_c.floor < 0)
		m->ray_c.floor = m->win.y;
	m->ray_c.y = m->ray_c.floor;
	while (++m->ray_c.y < m->win.y)
	{
		m->ray_c.current_dist = m->win.y / (2.0 * m->ray_c.y - m->win.y);
		m->ray_c.weight = (m->ray_c.current_dist) / (m->ray_c.dist_wall);
		m->ray_c.current_floor_x = m->ray_c.weight * m->ray_c.floor_x_wall
			+ (1.0 - m->ray_c.weight) * m->pc.pos_x;
		m->ray_c.current_floor_y = m->ray_c.weight * m->ray_c.floor_y_wall
			+ (1.0 - m->ray_c.weight) * m->pc.pos_y;
		m->ray_c.floor_tex_x = (int)(m->ray_c.current_floor_x
				* m->area.floor.size.x) % m->area.floor.size.x;
		m->ray_c.floor_tex_y = (int)(m->ray_c.current_floor_y
				* m->area.floor.size.y) % m->area.floor.size.y;
		dark(&m->area.drow.pixels[(m->area.drow.size.x * m->ray_c.y
				+ m->ray_c.x) * 4], &m->area.floor.pixels[(m->area.floor.size.x
				* m->ray_c.floor_tex_y + m->ray_c.floor_tex_x)
			* 4], m->ray_c.current_dist);
		dark(&m->area.drow.pixels[(m->area.drow.size.x * (m->area.floor.size.y
					- m->ray_c.y) + m->ray_c.x) * 4],
			&m->area.floor.pixels[(m->area.floor.size.x
				* m->ray_c.floor_tex_y + m->ray_c.floor_tex_x)
			* 4], m->ray_c.current_dist);
	}
}

void	draw_textures_floor_ceil(t_main *m)
{
	if (m->ray_c.side == 0 && m->ray_c.ray_d_x > 0)
	{
		m->ray_c.floor_x_wall = m->ray_c.map_x;
		m->ray_c.floor_y_wall = m->ray_c.map_y + m->ray_c.wall_x;
	}
	else if (m->ray_c.side == 0 && m->ray_c.ray_d_x < 0)
	{
		m->ray_c.floor_x_wall = m->ray_c.map_x + 1.0;
		m->ray_c.floor_y_wall = m->ray_c.map_y + m->ray_c.wall_x;
	}
	else if (m->ray_c.side == 1 && m->ray_c.ray_d_y > 0)
	{
		m->ray_c.floor_x_wall = m->ray_c.map_x + m->ray_c.wall_x;
		m->ray_c.floor_y_wall = m->ray_c.map_y;
	}
	else
	{
		m->ray_c.floor_x_wall = m->ray_c.map_x + m->ray_c.wall_x;
		m->ray_c.floor_y_wall = m->ray_c.map_y + 1.0;
	}
	m->ray_c.dist_wall = m->ray_c.dist_w;
	m->ray_c.dist_player = 0.0;
	draw_textures_floor_ceil_1(m);
}

void	draw_x_line1(t_main *m)
{
	m->ray_c.find_wall = 0;
	m->ray_c.camera_x = 2 * m->ray_c.x / (double)(m->win.x) - 1;
	m->ray_c.ray_d_x = m->ray_c.dir_x - m->pc.plane_x * m->ray_c.camera_x;
	m->ray_c.ray_d_y = m->ray_c.dir_y - m->pc.plane_y * m->ray_c.camera_x;
	m->ray_c.map_x = (int)(m->pc.pos_x);
	m->ray_c.map_y = (int)(m->pc.pos_y);
	m->ray_c.delta_dist_x = fabs(1.0 / m->ray_c.ray_d_x);
	m->ray_c.delta_dist_y = fabs(1.0 / m->ray_c.ray_d_y);
	if (m->ray_c.ray_d_x < 0)
	{
		m->ray_c.step_x = -1;
		m->ray_c.side_dist_x = (m->pc.pos_x - (float)m->ray_c.map_x)
			* m->ray_c.delta_dist_x;
	}
	else
	{
		m->ray_c.step_x = 1;
		m->ray_c.side_dist_x = (m->ray_c.map_x + 1.0 - m->pc.pos_x)
			* m->ray_c.delta_dist_x;
	}
}

void	draw_x_line2(t_main *m)
{
	if (m->ray_c.ray_d_y < 0)
	{
		m->ray_c.step_y = -1;
		m->ray_c.side_dist_y = (m->pc.pos_y - (float) m->ray_c.map_y)
			* m->ray_c.delta_dist_y;
	}
	else
	{
		m->ray_c.step_y = 1;
		m->ray_c.side_dist_y = (m->ray_c.map_y + 1.0 - m->pc.pos_y)
			* m->ray_c.delta_dist_y;
	}
}
