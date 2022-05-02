/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:10:03 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 03:15:03 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_button(t_main *m)
{
	if (m->keys.key_left == 1)
		mouse_left(m);
	if (m->keys.key_top == 1)
		mouse_circle_top(m);
	if (m->keys.key_bot == 1)
		mouse_circle_bot(m);
	return (1);
}

int	draw_spell(t_main *m)
{
	if (m->pc.mana > 1)
		my_put_image(&m->area.drow, &(*m->magic.magic_lst)->spell, 550, 350);
	return (0);
}

int	draw_type_magic(t_main *m)
{
	my_put_image(&m->area.drow, &(*m->magic.magic_lst)->icon_m,
		0, m->win.y - 100);
	return (1);
}

int	draw_left_hand(t_main *m)
{
	static int	c;
	static int	i;
	static int	torch;

	if (c >= 30 || i == 0)
	{
		i = 0;
		if (c <= 0)
			i = 1;
		c -= 2;
	}
	else
		c += 2;
	if (torch > 1)
	{
		torch = 0;
		m->pc.left_sp = m->pc.left_sp->next;
	}
	else
		torch++;
	my_put_image(&m->area.drow, &m->pc.left_sp->left_sp, 0, m->win.y - 798 + c);
	return (1);
}

void	draw_all_1(t_main *m)
{
	char	*ar;

	if (m->bonus == 2)
	{
		draw_mana(m);
		draw_type_magic(m);
	}
	if (m->magic.cast == 1 && m->bonus == 2)
		m->magic.cast = draw_spell(m);
	mlx_put_image_to_window(m->win.mlx, m->win.win, m->area.drow.r, 0, 0);
	if (m->bonus == 2)
	{
		mlx_string_put(m->win.mlx, m->win.win, 112, 946, 6750207, "MANA");
		ar = ft_itoa(m->pc.mana);
		mlx_string_put(m->win.mlx, m->win.win, 155, 946, 6750207,
			ar);
		free(ar);
	}
}
