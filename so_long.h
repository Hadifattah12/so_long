/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfattah <hfattah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:12:41 by hfattah           #+#    #+#             */
/*   Updated: 2024/08/22 10:48:36 by hfattah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MinilibX/mlx.h"
# include "ft_printf/includes/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113
# define KEY_ESC 65307
# define SPRITE_H 32
# define SPRITE_W 32
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

typedef struct l_position
{
	int	width;
	int	height;
}	t_position;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			collec;
	int			steps;
	int			mapw;
	int			maph;
	char		**data;
	void		*img_ptr;
	char		*spt_path;
	int			imgw;
	int			imgh;
	int			posw;
	int			posh;
}				t_game;

extern t_game	g_game;

void		get_map(char **av);
void		initialize(void);
void		read_map(char *file_name);
void		collectibale_validation(void);
void		contains_one_exit(void);
int			is_valid(char c);
void		is_rectangular(void);
void		walls_valide(void);
void		fill(char **data, t_position start, t_position size, int **visited);
void		has_valid_path(void);
void		free_visited(int **visited, t_position size);
void		is_reachable(int **visited, t_position size);
void		free_visited(int **visited, t_position size);
void		free_exit(char		*sms);
void		free_map(void);
void		c(void);
void		e(void);
void		g(void);
void		reach(int **visited, t_position size);
void		move_player(int key);
int			mlx_close(void);
void		init_position(void);
void		load_map(int row, int col);
void		moves(int key);
void		check_collect(void);
void		print_steps(void);
void		f(void);
int			get_height(char *file_name);
int			key_press(int key);
int			count_collec(void);
int			draw_map(void);
t_position	start_position(void);

#endif
