/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 10:47:58 by angomes-          #+#    #+#             */
/*   Updated: 2023/06/22 19:39:07 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int	ft_lstsize(t_list *lst)
{
	int	count;
	int	iterator;

	iterator = 0;
	count = 0;
	while (lst && lst->content)
	{
		iterator = 0;
		while (lst->content[iterator] && lst->content)
		{
			count++;
			iterator++;
		}
		lst = lst->next;
	}
	return (count);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp_node;
	t_list	*next;

	if (!lst)
		return ;
	temp_node = *lst;
	while (temp_node != NULL)
	{
		next = temp_node->next;
		free(temp_node->content);
		free(temp_node);
		temp_node = next;
	}
	*lst = NULL;
}

int	ft_check_end_line(t_list *lst, int bytes_read, t_list *rest_node)
{
	int	iterator;

	iterator = 0;
	if (bytes_read == 0)
		return (ft_lstsize(rest_node));
	else if (bytes_read == -1)
	{
		if (rest_node->content)
			ft_lstclear(&rest_node);
		return (-1);
	}
	else
	{
		while (lst->content[iterator])
		{
			if (lst->content[iterator] == '\n')
				return (iterator + 1);
			iterator++;
		}
	}
	return (0);
}
