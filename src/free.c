/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfattah <hfattah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:13:08 by hfattah           #+#    #+#             */
/*   Updated: 2024/08/19 10:30:41 by hfattah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(void)
{
	int	i;

	i = 0;
	if (g_game.mlx)
	{
		mlx_destroy_window(g_game.mlx, g_game.win);
		mlx_destroy_display(g_game.mlx);
	}
	free(g_game.mlx);
	while (i < g_game.maph)
	{
		free(g_game.data[i]);
		i++;
	}
	free(g_game.data);
}

void	free_exit(char	*sms)
{
	ft_printf("%s", sms);
	free_map();
	exit(EXIT_FAILURE);
}

void	free_visited(int **visited, t_position size)
{
	int	i;

	i = 0;
	while (i < size.height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	mlx_close(void)
{
	free_exit("\e[33m\e[1mGame closed! (X)\e[0m\n");
	return (0);
}
