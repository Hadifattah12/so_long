/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfattah <hfattah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:39:48 by hfattah           #+#    #+#             */
/*   Updated: 2024/06/21 10:54:18 by hfattah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_formats(char format, va_list *args, int *len, int *i)
{
	if (format == 's')
		ft_string(va_arg(*args, char *), len);
	else if (format == 'd' || format == 'i')
		ft_number(va_arg(*args, int), len);
	else if (format == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (format == 'x' || format == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, format);
	else if (format == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (format == 'c')
		ft_printcharacter(va_arg(*args, int), len);
	else if (format == '%')
		ft_printcharacter('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_formats(str[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_printcharacter ((char)str[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
