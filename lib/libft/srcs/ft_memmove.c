/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:17:29 by angomes-          #+#    #+#             */
/*   Updated: 2023/05/21 21:59:57 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cpydest;
	char	*cpysrc;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	cpydest = (char *)dest;
	cpysrc = (char *)src;
	i = 0;
	if (src < dest)
	{
		while (i < n)
		{
			*(cpydest + n - 1 - i) = *(cpysrc + n - 1 - i);
			i++;
		}
	}
	while (i < n)
	{
		*(cpydest + i) = *(cpysrc + i);
		i++;
	}
	return (dest);
}
