/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:10:04 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 01:23:58 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	mouse_left(t_main *m)
{
	if (m->pc.mana >= 1)
	{
		m->pc.mana = m->pc.mana - 1;
		m->magic.cast = 1;
		m->win.draw_w = 1;
	}
	else
	{
		m->pc.mana = m->pc.mana;
		m->magic.cast = 0;
	}
	return (1);
}

int	mouse_right(t_main *m)
{
	if (m->pc.mana >= 40)
		m->pc.mana = m->pc.mana - 40;
	else
		m->pc.mana = m->pc.mana;
	return (1);
}

int	mouse_circle_top(t_main *main)
{
	t_magic_lst	*l1;

	l1 = *main->magic.magic_lst;
	l1 = l1->next;
	*main->magic.magic_lst = l1;
	main->keys.key_top = 0;
	return (1);
}

int	mouse_circle_bot(t_main *main)
{
	(*main->magic.magic_lst) = (*main->magic.magic_lst)->prev;
	main->keys.key_bot = 0;
	return (1);
}
