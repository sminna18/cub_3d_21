/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:10:05 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 01:10:05 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	minimap_color(t_minimap *mm)
{
	mm->i = 0.1f;
	mm->y = 4;
	mm->mmap_w.a = 200;
	mm->mmap_w.r = 2;
	mm->mmap_w.g = 0;
	mm->mmap_w.b = 113;
	mm->mmap_p.a = 100;
	mm->mmap_p.r = 135;
	mm->mmap_p.g = 246;
	mm->mmap_p.b = 255;
	mm->mmap_e.a = 200;
	mm->mmap_e.r = 0;
	mm->mmap_e.g = 5;
	mm->mmap_e.b = 0;
	mm->y = -1;
	mm->iden = 0;
}

void	minimap_1(t_minimap *mm, t_main *m)
{
	while (++mm->y < (m->area.map_h * 10) - 5)
	{
		mm->x = -1;
		while (++mm->x < m->area.map_w * 10)
		{
			mm->rev = mm->y / 10;
			mm->y_h = (mm->rev * 10 + 5);
			if (m->area.map[mm->y / 10][mm->x / 10] == '1')
			{
				mm->rev = 0;
				while (mm->rev < 10)
				{
					my_put_pixel(m->area.drow.pixels, mm->x + 5,
						mm->y_h + mm->rev, mm->mmap_w);
					mm->rev++;
					mm->iden = 1;
				}
			}
		}
		if (mm->iden == 1)
		{
			mm->y += 9;
			mm->iden = 0;
		}
	}
}

void	minimap_21(t_minimap *mm, t_main *m)
{
	mm->x_h = (int)m->pc.pos_x * 10 + mm->x + 5;
	mm->rev = (int)(m->pc.pos_y);
	mm->y_h = (mm->rev * 10 + 5 + mm->y);
	my_put_pixel(m->area.drow.pixels, mm->x_h, mm->y_h, mm->mmap_p);
	mm->luch = m->pc.pos_a - m->pc.view_a / 2;
	while (mm->luch <= (m->pc.pos_a + m->pc.view_a / 2) && mm->luch
		>= (m->pc.pos_a - m->pc.view_a / 2))
	{
		mm->i = 0;
		while (mm->i < 90.0f && mm->y == 2 && mm->x == 2)
		{
			mm->x_a = cosf(mm->luch) * mm->i;
			mm->y_a = sinf(mm->luch) * mm->i;
			if (!check_color(mm->x_h + (int)(mm->x_a), mm->y_h
				+ (int)(mm->y_a), &m->area.drow, mm->mmap_w))
				my_put_pixel(m->area.drow.pixels, mm->x_h + (int)(mm->x_a),
					mm->y_h + (int)(mm->y_a), mm->mmap_p);
			else
				break ;
			mm->i += 1.0f;
		}
		mm->luch += 0.005f;
	}
}

void	minimap_2(t_minimap *mm, t_main *m)
{
	mm->y = 0;
	while (mm->y < 5)
	{
		mm->x = 0;
		while (mm->x < 5)
		{
			minimap_21(mm, m);
			mm->x++;
		}
		mm->y++;
	}
}

int	draw_minimap(t_main *m)
{
	t_minimap	mm;

	minimap_color(&mm);
	minimap_1(&mm, m);
	minimap_2(&mm, m);
	return (1);
}
