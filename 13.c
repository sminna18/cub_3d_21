/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:10:00 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 02:22:34 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	make_magic1(t_magic_lst	*lstf, t_magic_lst	*lstwa, t_magic_lst	*lstt,
					t_magic_lst	*lsta)
{
	lstf->type = 1;
	lstwa->type = 1;
	lsta->type = 1;
	lstt->type = 1;
	lstf->next = lstwa;
	lstwa->next = lstt;
	lstt->next = lsta;
	lsta->next = lstf;
	lstf->prev = lsta;
	lstwa->prev = lstf;
	lstt->prev = lstwa;
	lsta->prev = lstt;
}

int	make_magic(t_magic *magic, t_main *main)
{
	t_magic_lst	*lstf;
	t_magic_lst	*lstwa;
	t_magic_lst	*lstt;
	t_magic_lst	*lsta;

	magic->type = 0;
	magic->cast = 0;
	lstf = malloc(sizeof(t_magic_lst));
	lstwa = malloc(sizeof(t_magic_lst));
	lstt = malloc(sizeof(t_magic_lst));
	lsta = malloc(sizeof(t_magic_lst));
	make_magic1(lstf, lstwa, lstt, lsta);
	lstf->icon_m = ft_new_sprite(main->win.mlx, "fire_ic.xpm");
	lstwa->icon_m = ft_new_sprite(main->win.mlx, "water_ic.xpm");
	lsta->icon_m = ft_new_sprite(main->win.mlx, "wind_ic.xpm");
	lstt->icon_m = ft_new_sprite(main->win.mlx, "earth_ic.xpm");
	lstf->spell = ft_new_sprite(main->win.mlx, "fire_spell.xpm");
	lstwa->spell = ft_new_sprite(main->win.mlx, "water_spell.xpm");
	lsta->spell = ft_new_sprite(main->win.mlx, "aer_spell.xpm");
	lstt->spell = ft_new_sprite(main->win.mlx, "earth_spell.xpm");
	magic->magic_lst = malloc(sizeof(t_magic_lst *));
	*magic->magic_lst = lstwa;
	return (1);
}

void	make_area_1(t_area *area, t_main *main, t_cub *cub)
{
	area->drow = ft_new_sprite(main->win.mlx, "../all.xpm");
	area->wall_l = ft_new_sprite(main->win.mlx, "../earth_spell.xpm");
	area->wall_r = ft_new_sprite(main->win.mlx, "../aer_spell.xpm");
	area->wall_b = ft_new_sprite(main->win.mlx, "../fire_spell.xpm");
	area->wall_f = ft_new_sprite(main->win.mlx, "../water_spell.xpm");
	area->floor = ft_new_sprite(main->win.mlx, "../wall.xpm");
	area = NULL;
	main = NULL;
	cub = NULL;
}
