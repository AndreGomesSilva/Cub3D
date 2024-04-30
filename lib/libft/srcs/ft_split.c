/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:22:59 by angomes-          #+#    #+#             */
/*   Updated: 2024/04/30 17:47:09 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_words(char const *s, char c);
static int	ft_str_len(char *str, char c);
static void	ft_free(char **obj, int len);
static char	**add_substrings(char **strings, const char *s, char c, int len);

char	**ft_split(char const *s, char c)
{
	int		n_words;
	char	**strings;

	if (!s)
		return (NULL);
	n_words = count_words(s, c);
	strings = (char **) malloc((n_words + 1) * sizeof(char *));
	if (strings != NULL)
		strings = add_substrings(strings, s, c, n_words);
	return (strings);
}

static char	**add_substrings(char **strings, const char *s, char c, int len)
{
	int	s_len;
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			s_len = ft_str_len((char *)s, c);
			strings[i] = ft_substr((char *)s, 0, s_len);
			if (!strings[i])
			{
				ft_free(strings, len);
				return (NULL);
			}
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	strings[i] = NULL;
	return (strings);
}

static void	ft_free(char **obj, int len)
{	
	int	i;

	i = 0;
	while (*obj && i < len)
	{
		free(obj[i]);
		i++;
	}
	free(obj);
}

static int	ft_str_len(char *str, char c)
{
	int	s_len;

	s_len = 0;
	while (str[s_len] && str[s_len] != c)
	{
		s_len++;
	}
	return (s_len);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	old_i;
	int	n_words;

	i = 0;
	n_words = 0;
	while (*s)
	{
		while (*s && *s == c)
		{
			s++;
			i++;
		}
		old_i = i;
		while (*s && *s != c)
		{
			s++;
			i++;
		}
		if (i > old_i)
			n_words += 1;
	}
	return (n_words);
}
