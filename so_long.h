/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:11 by rafaria           #+#    #+#             */
/*   Updated: 2024/07/17 17:17:02 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "so_path.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WALL '1'
# define GROUND '0'
# define COLLECTIBLES 'C'
# define PLAYER 'P'
# define EXIT 'E'

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define REALUP 65362
# define REALDOWN 65364
# define REALLEFT 65361
# define REALRIGHT 65363
# define ESC 65307

typedef struct s_img
{
	void	*ptr;
	int		x;
	int		y;
}			t_img;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct t_start
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_to_fill;
	char	*string;

	int		moves;

	int		collectibles_found;
	int		total_collectibles;
	int		exit_found;

	int		x_axis;
	int		y_axis;

	int		x_player;
	int		y_player;

	t_img	wall;
	t_img	floor;
	t_img	portal;
	t_img	collect;
	t_img	player;

}			t_struct;

// So_long ---------------------------------------------------
int			so_long(int argc, char **argv);

// Init mlx -----------------------------------------------------
void		init_mlx(t_struct *game);
void		init_components_map(t_struct *game);
t_img		new_sprite(t_struct *game, void *mlx, char *path);

// Init map -----------------------------------------------------
char		*read_map(char *str, t_struct *game);
char		**initialize_map(t_struct *game, char *str);
void		design_map(t_struct *game);
int			find_player(t_struct *game, char str);
void		build_images(t_struct *game, int x, int y);
char		*build_map(int fd);

// Check_maps ------------------------------------------------
void		checks_maps(t_struct *game, char *str, char **map);
void		check_map_valid(t_struct *game, char *str);
void		check_rectangular(t_struct *game, char *str);
void		check_wall_all_around(t_struct *game, char **map);
void		run_algo(t_struct *game);

// Flood_fill ---------------------------------------------

void		flood_fill(t_struct *game, t_point size, t_point begin);
void		fill(t_struct *game, t_point size, t_point cur, char to_fill);

// Parsing ----------------------------------------------------

void		parsing(int argc, char **argv, t_struct *game);
int			check_nb_of_args(int argc);
int			check_name_map(char *str);
int			check_no_coquin(t_struct *game, char *str);
char		*build_map(int fd);

// hooking
int			key_hook(int keycode, t_struct *game);

// Move
int			move_up(t_struct *game);
int			move_down(t_struct *game);
int			move_left(t_struct *game);
int			move_right(t_struct *game);

// Error ----------------------------------------------------
int			ft_close(t_struct *game);
char		**free_map(char **tab);
int			ft_light_close(t_struct *game);
int			init_all(t_struct *game);
int ft_close_free(t_struct *game);

// Annexe -----------------------------

int			ft_itoa(int n);
void		ft_fill_res(int size, int locate, int n, char *res);
int			ft_get_size(int n);
int			ft_putstr(char *str);
int			int_strlen(char *str);
// Split  --------------------------------------------------

char		**ft_split(char *s, char c);
int			int_strlen(char *str);
int			count_words(char *str, char c);

// Get next line  --------------------------------------------------
char		*get_next_line(int fd);
char		*ft_strjoin(char *left_str, char *buff);

#endif
