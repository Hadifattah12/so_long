/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfattah <hfattah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:13:21 by hfattah           #+#    #+#             */
/*   Updated: 2024/08/22 15:31:36 by hfattah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	f(void)
{
	free_map();
	exit(1);
}

void	walls_valide(void)
{
	int	i;

	i = 0;
	while (i < g_game.mapw)
	{
		if (g_game.data[0][i] != '1' || g_game.data[g_game.maph - 1][i] != '1')
		{
			ft_printf("Invalide map\n");
			f();
		}
		i++;
	}
	i = 0;
	while (i < g_game.maph)
	{
		if (g_game.data[i][0] != '1'
			|| g_game.data[i][g_game.mapw - 1] != '1')
		{
			ft_printf("Invalide map\n");
			f();
		}
		i++;
	}
}

void	is_rectangular(void)
{
	int	i;

	i = 0;
	while (i < g_game.maph)
	{
		if ((int)ft_strlen(g_game.data[i]) != g_game.mapw)
		{
			free_map();
			ft_printf("not rectangular");
			exit(1);
		}
		i++;
	}
}

int	is_valid(char c)
{
	return (c == 'E' || c == 'P' || c == 'C' || c == '1' || c == '0');
}

void	collectibale_validation(void)
{
	int	i;
	int	j;
	int	collect;

	collect = 0;
	i = 0;
	while (i < g_game.maph)
	{
		j = 0;
		while (j < g_game.mapw)
		{
			if (!is_valid(g_game.data[i][j]))
				g();
			if (g_game.data[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	if (collect == 0)
		c();
	g_game.collec = collect;
}
