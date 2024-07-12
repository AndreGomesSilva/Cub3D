/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:18:43 by angomes-          #+#    #+#             */
/*   Updated: 2024/04/30 17:40:06 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew(f(lst -> content));
	if (!new_list)
		return (NULL);
	head = new_list;
	lst = lst -> next;
	while (lst)
	{
		new_list -> next = ft_lstnew(f(lst -> content));
		if (!new_list)
		{
			del(new_list);
			free(new_list);
		}
		new_list = new_list -> next;
		lst = lst -> next;
	}
	return (head);
}
