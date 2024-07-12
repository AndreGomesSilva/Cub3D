/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:42:56 by angomes-          #+#    #+#             */
/*   Updated: 2023/05/22 13:06:08 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp_node;
	t_list	*next;

	if (!lst || !del)
		return ;
	temp_node = *lst;
	while (temp_node != NULL)
	{
		next = temp_node -> next;
		del(temp_node -> content);
		free (temp_node);
		temp_node = next;
	}
	*lst = NULL;
}
