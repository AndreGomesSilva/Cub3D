/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:43:17 by angomes-          #+#    #+#             */
/*   Updated: 2024/04/30 17:45:16 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cpys;
	unsigned char	cpyc;

	cpys = (unsigned char *)s;
	cpyc = (unsigned char)c;
	while (n--)
	{
		if (*cpys == cpyc)
			return ((void *)cpys);
		cpys++;
	}
	return (NULL);
}
