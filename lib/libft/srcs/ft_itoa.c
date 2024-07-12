/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:04:29 by angomes-          #+#    #+#             */
/*   Updated: 2024/04/30 17:38:28 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static long int	count_len_int(long int n);

char	*ft_itoa(int n)
{
	char		*s;
	long int	len;
	long int	i;
	long int	number;

	number = n;
	len = count_len_int(number);
	i = 1;
	s = (char *) malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	if (number < 0)
	{
		*s = '-';
		number = number * (-1);
	}
	while (number > 9)
	{
		*(s + len - i) = (number % 10 + 48);
		number /= 10;
		i++;
	}
	*(s + len - i) = (number % 10 + 48);
	*(s + len) = '\0';
	return (s);
}

static long int	count_len_int(long int n)
{
	long int	len;

	len = 0;
	if (n < 0)
	{
		n = n * (-1);
		len++;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}
