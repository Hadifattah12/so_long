/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfattah <hfattah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:16:16 by hfattah           #+#    #+#             */
/*   Updated: 2024/06/20 14:28:03 by hfattah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printcharacter(char c, int *length)
{
	write(1, &c, 1);
	(*length)++;
}

void	ft_string(char *str, int *length)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (str[i])
	{
		ft_printcharacter(str[i], length);
		i++;
	}
}
