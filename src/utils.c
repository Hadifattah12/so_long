/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfattah <hfattah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:13:51 by hfattah           #+#    #+#             */
/*   Updated: 2024/08/22 10:18:32 by hfattah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_height(char *file_name)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		return (0);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (i);
}

void	read_map(char *file_name)
{
	int		fd;
	char	*lines;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		f();
	lines = get_next_line(fd);
	while (lines != NULL)
	{
		i = ft_strlen(lines);
		if (lines[i - 1] == '\n')
		{
			lines[i - 1] = '\0';
			i--;
		}
		g_game.data[g_game.maph] = ft_strdup(lines);
		if (g_game.maph == 0)
			g_game.mapw = i;
		g_game.maph++;
		free(lines);
		lines = get_next_line(fd);
	}
	close(fd);
}

void	get_map(char **av)
{
	int	num_lines;

	g_game.data = NULL;
	g_game.maph = 0;
	g_game.mapw = 0;
	num_lines = get_height(av[1]);
	g_game.data = (char **)malloc(sizeof(char *) * num_lines);
	if (!g_game.data)
	{
		ft_printf("Error allocation data\n");
		exit(1);
	}
	read_map(av[1]);
}

void	load_map(int row, int col)
{
	if (g_game.data[row][col] == '1')
		g_game.img_ptr = mlx_xpm_file_to_image(g_game.mlx, "./img/wall.xpm",
				&g_game.imgw, &g_game.imgh);
	else if (g_game.data[row][col] == '0')
		g_game.img_ptr = mlx_xpm_file_to_image(g_game.mlx, "./img/floor.xpm",
				&g_game.imgw, &g_game.imgh);
	else if (g_game.data[row][col] == 'E')
	{
		if (count_collec() == 0)
			g_game.img_ptr = mlx_xpm_file_to_image(g_game.mlx, "./img/o-e.xpm",
					&g_game.imgw, &g_game.imgh);
		else
			g_game.img_ptr = mlx_xpm_file_to_image(g_game.mlx, "./img/e-c.xpm",
					&g_game.imgw, &g_game.imgh);
	}
	else if (g_game.data[row][col] == 'C')
		g_game.img_ptr = mlx_xpm_file_to_image(g_game.mlx, "./img/coin-bag.xpm",
				&g_game.imgw, &g_game.imgh);
	else if (g_game.data[row][col] == 'P')
		g_game.img_ptr = mlx_xpm_file_to_image(g_game.mlx, g_game.spt_path,
				&g_game.imgw, &g_game.imgh);
	mlx_put_image_to_window(g_game.mlx, g_game.win, g_game.img_ptr,
		SPRITE_W * col,
		SPRITE_H * row);
	mlx_destroy_image(g_game.mlx, g_game.img_ptr);
}

int	draw_map(void)
{
	int	row;
	int	col;

	row = 0;
	while (row < g_game.maph)
	{
		col = 0;
		while (col < g_game.mapw)
		{
			load_map(row, col);
			col++;
		}
		row++;
	}
	return (0);
}
