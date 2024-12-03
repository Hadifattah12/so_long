/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfattah <hfattah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:13:00 by hfattah           #+#    #+#             */
/*   Updated: 2024/08/22 13:45:39 by hfattah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(void)
{
	ft_printf("Error opening file\n");
	exit(1);
}

void	fill(char **data, t_position start, t_position size, int **visited)
{
	t_position	next_positions[4];

	next_positions[0].width = start.width;
	next_positions[0].height = start.height + 1;
	next_positions[1].width = start.width;
	next_positions[1].height = start.height - 1;
	next_positions[2].width = start.width + 1;
	next_positions[2].height = start.height;
	next_positions[3].width = start.width - 1;
	next_positions[3].height = start.height;
	if (start.height < 0 || start.height >= size.height || start.width < 0
		|| start.width >= size.width
		|| data[start.height][start.width] == '1'
		|| data[start.height][start.width] == 'E'
		|| visited[start.height][start.width])
		return ;
	visited[start.height][start.width] = 1;
	fill(data, next_positions[0], size, visited);
	fill(data, next_positions[1], size, visited);
	fill(data, next_positions[2], size, visited);
	fill(data, next_positions[3], size, visited);
}

void	move_player(int key)
{
	g_game.data[g_game.posh][g_game.posw] = '0';
	if (key == KEY_A)
	{
		g_game.posw -= 1;
		g_game.spt_path = "./img/player/left.xpm";
	}
	if (key == KEY_D)
	{
		g_game.posw += 1;
		g_game.spt_path = "./img/player/right.xpm";
	}
	if (key == KEY_W)
	{
		g_game.posh -= 1;
		g_game.spt_path = "./img/player/back.xpm";
	}
	if (key == KEY_S)
	{
		g_game.posh += 1;
		g_game.spt_path = "./img/player/front.xpm";
	}
	g_game.data[g_game.posh][g_game.posw] = 'P';
	g_game.steps ++;
}

void	moves(int k)
{
	if ((k == KEY_A)
		&& (g_game.data[g_game.posh][g_game.posw - 1] == 'E'))
		check_collect();
	else if ((k == KEY_A) && (g_game.data[g_game.posh][g_game.posw - 1] != '1'))
		move_player(KEY_A);
	if ((k == KEY_D) && (g_game.data[g_game.posh][g_game.posw + 1] == 'E'))
		check_collect();
	else if ((k == KEY_D) && (g_game.data[g_game.posh][g_game.posw + 1] != '1'))
		move_player(KEY_D);
	if ((k == KEY_S) && (g_game.data[g_game.posh + 1][g_game.posw] == 'E'))
		check_collect();
	else if ((k == KEY_S) && (g_game.data[g_game.posh + 1][g_game.posw] != '1'))
		move_player(KEY_S);
	if ((k == KEY_W) && (g_game.data[g_game.posh - 1][g_game.posw] == 'E'))
		check_collect();
	else if ((k == KEY_W) && (g_game.data[g_game.posh - 1][g_game.posw] != '1'))
		move_player(KEY_W);
}

void	initialize(void)
{
	g_game.mlx = NULL;
	g_game.win = NULL;
	g_game.collec = 0;
	g_game.steps = 0;
	g_game.data = NULL;
	g_game.maph = 0;
	g_game.mapw = 0;
	g_game.img_ptr = NULL;
	g_game.spt_path = "./img/player/front.xpm";
	g_game.imgw = 0;
	g_game.imgh = 0;
	g_game.posw = 0;
	g_game.posh = 0;
}
