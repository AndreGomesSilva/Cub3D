/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:27:04 by angomes-          #+#    #+#             */
/*   Updated: 2024/04/30 17:47:54 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	if ((!dst || !src) && size == 0)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	dst = &dst[dst_len];
	if (size < dst_len)
		return (src_len + size);
	if (size > 0)
	{
		while (*src && size - 1 > dst_len)
		{
			*dst++ = *src++;
			size--;
		}
		*(dst) = '\0';
	}
	return (dst_len + src_len);
}
