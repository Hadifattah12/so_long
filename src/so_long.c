/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfattah <hfattah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:13:43 by hfattah           #+#    #+#             */
/*   Updated: 2024/08/19 18:35:29 by hfattah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game	g_game;

void	check_arg(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("enter a file");
		exit(1);
	}
	else if (ac > 2)
	{
		ft_printf("multi argument");
		exit(1);
	}
	else
	{
		if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == NULL)
		{
			ft_printf("your file should be <.ber>");
			exit(1);
		}
	}
}

int	count_collec(void)
{
	int	row;
	int	col;

	row = 0;
	g_game.collec = 0;
	while (row < g_game.maph)
	{
		col = 0;
		while (col <= g_game.mapw)
		{
			if (g_game.data[row][col] == 'C')
				g_game.collec++;
			col++;
		}
		row++;
	}
	return (g_game.collec);
}

void	print_steps(void)
{
	char	*str;
	char	*convert;

	convert = ft_itoa(g_game.steps);
	str = ft_strjoin("nb of mouvment : ", convert);
	mlx_string_put(g_game.mlx, g_game.win, 10, 20, 0x00FF00, str);
	free(str);
	free(convert);
}

int	key_press(int key)
{
	int	steps;

	steps = g_game.steps ;
	if (key == KEY_ESC || key == KEY_Q)
		free_exit("\e[33m\e[1mGame closed! (X)\e[0m\n");
	else
		moves(key);
	if (steps != g_game.steps)
		ft_printf("⟹ 📍 Steps: %d\n", g_game.steps);
	draw_map();
	print_steps();
	return (0);
}

int	main(int argc, char **argv)
{
	initialize();
	check_arg(argc, argv);
	get_map(argv);
	walls_valide();
	is_rectangular();
	collectibale_validation();
	contains_one_exit();
	has_valid_path();
	g_game.mlx = mlx_init();
	if (g_game.mlx == NULL)
		perror("Failed to initialize MiniLibX");
	g_game.win = mlx_new_window(g_game.mlx, g_game.mapw * SPRITE_W,
			g_game.maph * SPRITE_H, "So___long");
	if (g_game.win == NULL)
	{
		free_map();
		perror("Failed to create window");
	}
	init_position();
	draw_map();
	mlx_hook(g_game.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &g_game);
	mlx_hook(g_game.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &g_game);
	mlx_expose_hook(g_game.win, draw_map, &g_game);
	mlx_loop(g_game.mlx);
	return (0);
}
