/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:32:57 by angomes-          #+#    #+#             */
/*   Updated: 2024/04/30 17:48:59 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new_str;
	const char	*substr;
	size_t		s_len;

	if (!s)
		return (NULL);
	substr = &*(s + start);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	new_str = (char *) malloc((len + 1) * sizeof(char));
	if (new_str != NULL)
	{
		ft_strlcpy(new_str, substr, len + 1);
		return (new_str);
	}
	return (NULL);
}
