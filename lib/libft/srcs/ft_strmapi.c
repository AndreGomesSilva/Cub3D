/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:04:11 by angomes-          #+#    #+#             */
/*   Updated: 2024/04/30 17:48:12 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			s_len;
	char			*new_str;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	new_str = (char *) malloc ((s_len + 1) * sizeof(char));
	if (new_str != NULL)
	{
		while (*s)
		{
			*new_str = f(i, *s);
			s++;
			new_str++;
			i++;
		}	
		*new_str = '\0';
		return (new_str - i);
	}
	return (NULL);
}
