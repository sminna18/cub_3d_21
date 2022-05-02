/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:10:03 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 02:49:05 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	draw_all(t_main *m)
{
	mlx_clear_window(m->win.mlx, m->win.win);
	if (m->win.draw_w == 1)
	{
		draw_wall(m);
		if (m->bonus == 2)
		{
			draw_left_hand(m);
			draw_minimap(m);
			my_put_image(&m->area.drow, &m->pc.mana_sp, 100, 925);
		}
		m->win.draw_w = 0;
	}
	check_button(m);
	draw_all_1(m);
	return (1);
}

int	loop_h(void *main)
{
	t_main		*m;

	m = (t_main *)main;
	draw_all(m);
	mana(m);
	return (1);
}

void	make_angle_vision(t_pc *pc, t_main *m, t_cub *cub)
{
	int		i;
	char	c;

	i = 15;
	c = cub->pos_angle;
	if (c == 'N')
		i = 30;
	else if (c == 'S')
		i = 0;
	pc->mana = 50;
	pc->pos_a = 1.571f;
	pc->pos_x = cub->pos_x + 0.5f;
	pc->pos_y = cub->pos_y - 8 + 0.5f;
	pc->view_a = 1.05f;
	pc->plane_x = 0.660f;
	pc->plane_y = -0.019f;
	while (i > 0)
	{
		if (c == 'W')
			key_e(m);
		else
			key_q(m);
		i--;
	}
}

int	make_pc(t_pc *pc, t_main *m, t_cub *cub)
{
	pc->mana_sp = ft_new_sprite(m->win.mlx, "mana.xpm");
	pc->left_sp = malloc(sizeof (t_lhand));
	pc->left_sp->left_sp = ft_new_sprite(m->win.mlx, "xpm_torch0.xpm");
	pc->left_sp->next = malloc(sizeof (t_lhand));
	pc->left_sp->next->left_sp = ft_new_sprite(m->win.mlx, "xpm_torch1.xpm");
	pc->left_sp->next->next = malloc(sizeof (t_lhand));
	pc->left_sp->next->next->left_sp = ft_new_sprite(m->win.mlx,
			"xpm_torch2.xpm");
	pc->left_sp->next->next->next = malloc(sizeof (t_lhand));
	pc->left_sp->next->next->next->left_sp = ft_new_sprite(m->win.mlx,
			"xpm_torch3.xpm");
	pc->left_sp->next->next->next->next = malloc(sizeof (t_lhand));
	pc->left_sp->next->next->next->next->left_sp = ft_new_sprite(m->win.mlx,
			"xpm_torch4.xpm");
	pc->left_sp->next->next->next->next->next = pc->left_sp;
	make_angle_vision(pc, m, cub);
	return (1);
}
