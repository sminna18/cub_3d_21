/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:20:34 by kdakota           #+#    #+#             */
/*   Updated: 2022/04/24 01:42:55 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include "mlx_st/mlx.h"
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		draw_w;
	int		x;
	int		y;
}t_win;

typedef struct s_vector
{
	int	x;
	int	y;
}t_vector;

typedef struct s_image {
	void		*r;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_lhand{
	t_image			left_sp;
	struct s_lhand	*next;
}t_lhand;

typedef struct s_pc
{
	int		mana;
	t_image	mana_sp;
	t_lhand	*left_sp;
	float	pos_x;
	float	pos_y;
	float	pos_a;
	float	view_a;
	float	plane_x;
	float	plane_y;
}t_pc;

typedef struct s_area
{
	char	**map;
	int		map_h;
	int		map_w;
	t_image	drow;
	t_image	wall_l;
	t_image	wall_f;
	t_image	wall_r;
	t_image	wall_b;
	t_image	floor;
	t_image	pika;
}t_area;

typedef struct s_key
{
	int	key_left;
	int	key_right;
	int	key_mid;
	int	key_top;
	int	key_bot;
	int	x;
	int	y;
}t_key;

typedef struct s_m_a
{
	t_image			p_magic;
	struct s_m_a	*next;
}t_m_a;

typedef struct s_magic_lst
{
	t_m_a				**m_a;
	t_image				icon_m;
	t_image				spell;
	int					type;
	struct s_magic_lst	*next;
	struct s_magic_lst	*prev;
}t_magic_lst;

typedef struct s_magic
{
	int			type;
	t_magic_lst	**magic_lst;
	int			cast;
}t_magic;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}t_color;

typedef struct s_minimap
{
	int			x;
	int			y;
	int			x_h;
	int			y_h;
	float		x_a;
	float		y_a;
	float		i;
	t_color		mmap_w;
	t_color		mmap_p;
	t_color		mmap_e;
	int			rev;
	int			iden;
	float		luch;
}t_minimap;

typedef struct s_color_uc
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}t_color_uc;

typedef struct s_ray_c{
	int		ceil;
	int		floor;
	float	x_for_get;
	float	y_for_get;
	int		x;
	int		y;
	float	dist_w;
	double	ray_d_x;
	double	ray_d_y;
	float	ray_angle;
	int		find_wall;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	floor_x_wall;
	double	floor_y_wall;
	double	wall_x;
	double	step;
	double	tex_pos;
	double	dist_wall;
	double	dist_player;
	double	current_dist;
	int		line_height;
	double	weight;
	double	current_floor_x;
	double	current_floor_y;
	int		floor_tex_x;
	int		floor_tex_y;

	t_color	fon;
	t_color	fon_n;
	t_image	sp;
	t_image	wall;
}t_ray_c;

typedef struct s_main
{
	char	bonus;
	t_win	win;
	t_pc	pc;
	t_area	area;
	t_key	keys;
	t_magic	magic;
	t_ray_c	ray_c;
}t_main;

typedef struct s_cub {
	int		map_height;
	int		map_width;
	int		map_start;
	char	**file;
	char	**map;
	int		pos_x;
	int		pos_y;
	char	pos_angle;
	int		pos_count;
	int		color_f[4];
	int		color_c[4];
}				t_cub;

char	*get_next_line(int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);

void	free_end_exit(t_cub *cub);
int		check_extension(char *arg);
int		open_file(char *argv);
int		file_check(int argc, char **argv);
void	count_file_height(int fd, t_cub *cub);

void	copy_file(int fd, t_cub *cub);
void	print_free_exit(t_cub *cub);
void	color_write(char *str, int *nums, t_cub *cub, int i);
void	checking_borders_of_colors(t_cub *cub);
void	check_color_e(t_cub *cub);

void	set_vars(int i, int j, t_cub *cub);
void	many_player_error(t_cub *cub);
void	checking_map_symbols(t_cub *cub);
int		take_o(t_cub *cub, int i, int j, int cykle);
void	search_accessible_zone(t_cub *cub);

void	search_for_holes(t_cub *cub);
void	check_texture(t_cub *cub);
void	path_change(t_cub *cub);
int		hole_check(t_cub *cub, int i, int j);
void	initial_values(t_cub *cub);
t_cub	*emil(int argc, char **argv);

int		main(int ac, char **av);

void	my_put_pixel(char *pixels, int x, int y, t_color color);
t_image	ft_new_sprite(void *mlx, char *path);
int		ft_close(void);
int		make_win(t_main *m);
int		check_int(int i1, int i2, t_main *m);

int		key_a(t_main *m);
int		key_s(t_main *m);
int		key_d(t_main *m);
int		key_w(t_main *m);
int		key_q(t_main *m);

int		key_e(t_main *m);
int		check_key(int key, t_main *main);
int		mana(t_main *main);
t_color	get_color_sprite(int y, int x, t_image *sprite, int *i);
int		my_put_image(t_image *screen, t_image *sprite, int x, int y);

void	draw_fon_floor_ceil(t_main *m);
void	draw_textures_floor_ceil_1(t_main *m);
void	draw_textures_floor_ceil(t_main *m);
void	draw_x_line1(t_main *m);
void	draw_x_line2(t_main *m);

void	draw_x_line3(t_main *m);
void	draw_x_line4(t_main *m);
void	draw_left_side(t_main *m, int tex_x, int tex_y);
void	draw_forward_side(t_main *m, int tex_x, int tex_y);
void	draw_right_side(t_main *m, int tex_x, int tex_y);

void	draw_back_side(t_main *m, int tex_x, int tex_y);
void	draw_x_line5(t_main *m);
void	draw_x_line(t_main *m);
int		draw_wall(t_main *m);
int		check_color(int x, int y, t_image *all, t_color m_wall);

int		draw_mana(t_main *m);
int		dark_blue(int r);
int		dark_green(int r);
int		dark_red(int r);
int		dark(char *i, char *rez, double index);

void	minimap_color(t_minimap *mm);
void	minimap_1(t_minimap *mm, t_main *m);
void	minimap_21(t_minimap *mm, t_main *m);
void	minimap_2(t_minimap *mm, t_main *m);
int		draw_minimap(t_main *m);

int		mouse_left(t_main *m);
int		mouse_right(t_main *m);
int		mouse_circle(t_main *main);
int		mouse_circle_top(t_main *main);
int		mouse_circle_bot(t_main *main);

int		check_button(t_main *m);
int		draw_spell(t_main *m);
int		draw_type_magic(t_main *m);
int		draw_left_hand(t_main *m);
void	draw_all_1(t_main *m);

int		draw_all(t_main *m);
int		loop_h(void *main);
void	make_angle_vision(t_pc *pc, t_main *m, t_cub *cub);
int		make_pc(t_pc *pc, t_main *m, t_cub *cub);
int		mouse_h(int key, t_main *main);

int		make_area(t_area *area, t_main *main, t_cub *cub);
int		move_mouse(int x, int y, t_main *m);
int		mouse_button_pr(int key, int x, int y, t_main *m);
int		mouse_button_re(int key, int x, int y, t_main *m);
int		make_key(t_key *key);

void	make_magic1(t_magic_lst	*lstf, t_magic_lst	*lstwa, t_magic_lst	*lstt,
			t_magic_lst	*lsta);
int		make_magic(t_magic *magic, t_main *main);
void	make_area_1(t_area *area, t_main *main, t_cub *cub);

#endif
