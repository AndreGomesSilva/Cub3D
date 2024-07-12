/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:45:01 by angomes-          #+#    #+#             */
/*   Updated: 2024/04/30 17:48:48 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	look_for_set_begning(char const *s1, char const *set);
static int	look_for_set_end(char const *s1, char const *set, size_t len);
static int	char_in_set(const char c1, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{	
	size_t	s1_len;
	size_t	index_start;
	size_t	total_len;
	char	*clear_s1;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	index_start = look_for_set_begning(s1, set);
	total_len = look_for_set_end(s1 + index_start, set, s1_len - index_start);
	clear_s1 = (char *) malloc(total_len + 1 * sizeof(char));
	if (clear_s1 != NULL)
	{
		ft_strlcpy(clear_s1, (s1 + index_start), total_len + 1);
	}
	return (clear_s1);
}

static int	look_for_set_begning(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (*(s1 + i) && char_in_set(*(s1 + i), set))
		i++;
	return (i);
}

static int	look_for_set_end(char const *s1, char const *set, size_t len)
{
	while (len > 0 && char_in_set(*(s1 + len - 1), set))
		len--;
	return (len);
}

static int	char_in_set(const char c1, const char *set)
{
	int	j;
	int	result;

	j = 0;
	result = 0;
	while (*(set + j))
	{
		if (*(set + j) == c1)
			result = 1;
		j++;
	}
	return (result);
}
