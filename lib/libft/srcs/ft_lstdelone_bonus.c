/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:02:03 by angomes-          #+#    #+#             */
/*   Updated: 2023/05/22 12:40:55 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*temp_node;

	if (!lst || !del)
		return ;
	temp_node = lst -> next;
	del(lst -> content);
	free (lst);
	lst = temp_node;
}
