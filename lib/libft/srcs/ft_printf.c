/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:54:18 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/03 14:28:06 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	check_flag(char flag, va_list arg)
{
	int	result;

	result = 0;
	if (flag == 'c')
		result = print_char(va_arg(arg, int));
	else if (flag == 's')
		result = print_string(va_arg(arg, char *));
	else if (flag == 'd')
		result = print_number(va_arg(arg, int));
	else if (flag == 'i')
		result = print_number(va_arg(arg, int));
	else if (flag == 'u')
		result = print_unsigned_number(va_arg(arg, int));
	else if (flag == 'x')
		result = hexadecimal_convert(va_arg(arg, unsigned int), result, 0);
	else if (flag == 'X')
		result = hexadecimal_convert(va_arg(arg, unsigned int), result, 1);
	else if (flag == 'p')
		result = hexadecimal_convert(va_arg(arg, unsigned long), result, 2);
	else if (flag == '%')
		result = print_char('%');
	return (result);
}

static int	find_flag(const char *str, va_list arg)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			while (*str == ' ')
				str++;
			count += check_flag(*str, arg);
			str++;
		}
		else
		{
			count += print_char(*str);
			str++;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		result;

	if (!str)
		return (-1);
	va_start(arg, str);
	result = find_flag(str, arg);
	va_end(arg);
	return (result);
}
