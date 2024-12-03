/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfattah <hfattah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:27:25 by hfattah           #+#    #+#             */
/*   Updated: 2024/06/20 15:01:27 by hfattah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_number(int nb, int *length)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (nb < 0)
	{
		ft_printcharacter('-', length);
		ft_number(-1 * nb, length);
	}
	else
	{	
		if (nb > 9)
			ft_number(nb / 10, length);
		ft_printcharacter(nb % 10 + '0', length);
	}
}

void	ft_unsigned_int(unsigned int u, int *length)
{
	if (u > 9)
		ft_unsigned_int(u / 10, length);
	ft_printcharacter(u % 10 + '0', length);
}

void	ft_hexadecimal(unsigned int x, int *length, char format)
{
	char	string[25];
	char	*check;
	int		i;

	i = 0;
	if (x == 0)
	{
		ft_printcharacter('0', length);
		return ;
	}
	if (format == 'x')
		check = "0123456789abcdef";
	else
		check = "0123456789ABCDEF";
	while (x != 0)
	{
		string[i] = check[x % 16];
		x /= 16;
		i++;
	}
	while (i--)
		ft_printcharacter(string[i], length);
}

void	ft_pointer(size_t pointer, int *length)
{
	char	string[25];
	char	*check;
	int		i;

	i = 0;
	check = "0123456789abcdef";
	if (pointer == 0)
	{
		write(1, "(nil)", 5);
		(*length) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*length) += 2;
	while (pointer != 0)
	{
		string[i] = check[pointer % 16];
		pointer /= 16;
		i++;
	}
	while (i--)
		ft_printcharacter(string[i], length);
}
