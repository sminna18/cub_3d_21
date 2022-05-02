/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 03:18:28 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 03:18:28 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_main	main;
	t_cub	*cub;

	if (ft_strncmp(av[0], "./cub_3D_bonus", 10) == 0)
		main.bonus = 2;
	else
		main.bonus = 1;
	cub = emil(ac, av);
	if (!cub)
		exit(1);
	make_win(&main);
	make_pc(&main.pc, &main, cub);
	make_area(&main.area, &main, cub);
	make_key(&main.keys);
	make_magic(&main.magic, &main);
	mlx_hook(main.win.win, 2, 1L << 0, check_key, &main);
	mlx_hook(main.win.win, 6, 1L << 6, move_mouse, &main);
	mlx_hook(main.win.win, 4, 1L << 2, mouse_button_pr, &main);
	mlx_hook(main.win.win, 5, 1L << 3, mouse_button_re, &main);
	mlx_loop_hook(main.win.mlx, loop_h, &main);
	mlx_loop(main.win.mlx);
	return (0);
}
