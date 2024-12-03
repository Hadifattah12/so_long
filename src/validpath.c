/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfattah <hfattah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:13:28 by hfattah           #+#    #+#             */
/*   Updated: 2024/08/22 09:59:58 by hfattah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_position	start_position(void)
{
	t_position	start;
	int			i;
	int			j;

	i = 0;
	start.width = 0;
	start.height = 0;
	while (i < g_game.maph)
	{
		j = 0;
		while (j < g_game.mapw)
		{
			if (g_game.data[i][j] == 'P')
			{
				start.width = j;
				start.height = i;
			}
			j++;
		}
		i++;
	}
	return (start);
}

void	is_reachable(int **visited, t_position size)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_game.maph)
	{
		j = 0;
		while (j < g_game.mapw)
		{
			if ((g_game.data[i][j] == 'E' || g_game.data[i][j] == 'C')
			&& !visited[i][j])
			{
				if (g_game.data[i][j] == 'E' || (g_game.data[i][j] == 'C'))
					reach(visited, size);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	has_valid_path(void)
{
	int			**visited;
	int			i;
	t_position	start;
	t_position	size;

	size.width = g_game.mapw;
	size.height = g_game.maph;
	visited = (int **)malloc(g_game.maph * sizeof(int *));
	if (!visited)
		free_map();
	i = 0;
	while (i < g_game.maph)
	{
		visited[i] = (int *)ft_calloc(g_game.mapw, sizeof(int));
		i++;
	}
	start = start_position();
	fill(g_game.data, start, size, visited);
	is_reachable(visited, size);
	free_visited(visited, size);
}

void	reach(int **visited, t_position size)
{
	ft_printf("error no path");
	free_map();
	free_visited(visited, size);
	exit(1);
}

void	c(void)
{
	free_map();
	ft_printf("the map should contain at least one coin\n");
	exit(1);
}
