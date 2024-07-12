/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:38:39 by angomes-          #+#    #+#             */
/*   Updated: 2023/05/09 17:16:10 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cpys1;
	unsigned char	*cpys2;

	cpys1 = (unsigned char *)s1;
	cpys2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*cpys1 == *cpys2 && --n)
	{
		cpys1++;
		cpys2++;
	}
	return (*cpys1 - *cpys2);
}
