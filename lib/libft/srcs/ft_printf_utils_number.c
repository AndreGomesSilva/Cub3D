/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:56:48 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/03 14:28:51 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	hexadecimal_convert(unsigned long number, int result, int flag_type)
{
	int	remainder;

	if (flag_type == 2)
	{
		if (!number)
			return (print_string("(nil)"));
		else
			result += print_string("0x");
		flag_type = 0;
	}
	if (number > 15)
		result += hexadecimal_convert(number / 16, 0, flag_type);
	remainder = number % 16;
	if (remainder < 10)
		result += print_char('0' + remainder);
	else if (flag_type == 0)
		result += print_char('a' + remainder - 10);
	else if (flag_type == 1)
		result += print_char('A' + remainder - 10);
	return (result);
}

int	print_unsigned_number(long int number)
{
	long int	limits;
	long int	result;

	limits = 0;
	result = 0;
	if (number < 0)
	{
		limits = 4294967296 + (number);
		result = print_number(limits);
	}
	else
		result = print_number(number);
	return (result);
}

static long int	count_len_int(long int number)
{
	long int	len;

	len = 0;
	if (number < 0)
	{
		number = number * (-1);
		len++;
	}
	while (number > 9)
	{
		len++;
		number /= 10;
	}
	len++;
	return (len);
}

int	print_number(long int number)
{
	char		*str;
	long int	len;
	long int	i;

	i = 0;
	len = count_len_int(number);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	if (number < 0)
	{
		*str = '-';
		number = number * (-1);
	}
	while (i++, number > 9)
	{
		*(str + len - i) = (number % 10 + '0');
		number /= 10;
	}
	*(str + len - i) = (number % 10 + '0');
	*(str + len) = '\0';
	print_string(str);
	free(str);
	return (len);
}
