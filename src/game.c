/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfattah <hfattah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:13:15 by hfattah           #+#    #+#             */
/*   Updated: 2024/08/22 11:30:01 by hfattah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_position(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_game.maph)
	{
		j = 0;
		while (j < g_game.mapw)
		{
			if (g_game.data[i][j] == 'P')
			{
				g_game.posw = j;
				g_game.posh = i;
			}
			j++;
		}
		i++;
	}
}

void	check_collect(void)
{
	if (count_collec() == 0)
		free_exit("\e[32m\e[5m\e[1m🎉 CONGRATULATIONS 🎉\n!!!! You WON !!!!\e[0m\n");
	else
		ft_printf("\e[35m\e[1m ⚠️  Please, collect all the coins!!!\e[0m\n");
}

void	contains_one_exit(void)
{
	int	exit_count;
	int	start_count;
	int	i;
	int	j;

	start_count = 0;
	exit_count = 0;
	i = 0;
	while (i < g_game.maph)
	{
		j = 0;
		while (j < g_game.mapw)
		{
			if (g_game.data[i][j] == 'E')
				exit_count++;
			if (g_game.data[i][j] == 'P')
				start_count++;
			j++;
		}
		i++;
	}
	if (start_count != 1 || exit_count != 1)
		e();
}

void	e(void)
{
	free_map();
	ft_printf("error there are more than one Player or one Exit\n");
	exit(1);
}

void	g(void)
{
	free_map();
	ft_printf("the map should contain only (E,C,P,1,0)\n");
	exit(1);
}
