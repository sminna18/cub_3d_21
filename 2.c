/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:10:12 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 01:10:12 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_a(t_main *m)
{
	float	ch_x;
	float	ch_y;

	ch_x = sinf(m->pc.pos_a);
	ch_y = cosf(m->pc.pos_a);
	m->pc.pos_x += ch_x * 0.2f;
	m->pc.pos_y -= ch_y * 0.2f;
	if (check_int((int)(m->pc.pos_y - ch_y * 0.2f),
		(int)(m->pc.pos_x + ch_x * 0.2f), m))
	{
		m->pc.pos_x -= ch_x * 0.2f;
		m->pc.pos_y += ch_y * 0.2f;
	}
	return (1);
}

int	key_s(t_main *m)
{
	float	ch_x;
	float	ch_y;

	ch_x = cosf(m->pc.pos_a);
	ch_y = sinf(m->pc.pos_a);
	m->pc.pos_x -= ch_x * 0.2f;
	m->pc.pos_y -= ch_y * 0.2f;
	if (check_int((int)(m->pc.pos_y - ch_y * 0.2f),
		(int)(m->pc.pos_x - ch_x * 0.2f), m))
	{
		m->pc.pos_x += ch_x * 0.2f;
		m->pc.pos_y += ch_y * 0.2f;
	}
	return (1);
}

int	key_d(t_main *m)
{
	float	ch_x;
	float	ch_y;

	ch_x = sinf(m->pc.pos_a);
	ch_y = cosf(m->pc.pos_a);
	m->pc.pos_x -= ch_x * 0.2f;
	m->pc.pos_y += ch_y * 0.2f;
	if (check_int((int)(m->pc.pos_y + ch_y * 0.2f),
		(int)(m->pc.pos_x - ch_x * 0.2f), m))
	{
		m->pc.pos_x += ch_x * 0.2f;
		m->pc.pos_y -= ch_y * 0.2f;
	}
	return (1);
}

int	key_w(t_main *m)
{
	float	ch_x;
	float	ch_y;

	ch_x = cosf(m->pc.pos_a);
	ch_y = sinf(m->pc.pos_a);
	m->pc.pos_x += ch_x * 0.2f;
	m->pc.pos_y += ch_y * 0.2f;
	if (check_int((int)(m->pc.pos_y + ch_y * 0.2f),
		(int)(m->pc.pos_x + ch_x * 0.2f), m))
	{
		m->pc.pos_x -= ch_x * 0.2f;
		m->pc.pos_y -= ch_y * 0.2f;
	}
	return (1);
}

int	key_q(t_main *m)
{
	float	prev_plane_x;

	prev_plane_x = m->pc.plane_x;
	m->pc.pos_a -= 0.1f;
	m->pc.plane_x = m->pc.plane_x * cosf(-0.1f) - m->pc.plane_y * sinf(-0.1f);
	m->pc.plane_y = prev_plane_x * sinf(-0.1f) + m->pc.plane_y * cosf(-0.1f);
	m->win.draw_w = 1;
	return (1);
}
