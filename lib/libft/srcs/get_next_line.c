/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 10:42:50 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/03 14:25:46 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*get_line(char *content, t_list **rest_node, size_t len);
static char	*look_for_line(t_list **rest_node, int fd);
static char	*join_content(t_list **lst);
static int	make_node(int fd, t_list **lst_node);

char	*get_next_line(int fd)
{
	char			*result;
	static t_list	*rest_node;
	int				check_line;
	t_list			*head;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	if (rest_node)
	{
		check_line = ft_check_end_line(rest_node, 1, rest_node);
		if (check_line && ft_lstsize(rest_node) != check_line)
			result = get_line(join_content(&rest_node), &rest_node, check_line);
		else if (rest_node->content)
		{
			head = ft_lstnew(join_content(&rest_node));
			head->next = ft_lstnew(look_for_line(&rest_node, fd));
			result = join_content(&head);
		}
	}
	else
		result = look_for_line(&rest_node, fd);
	return (result);
}

static char	*look_for_line(t_list **rest_node, int fd)
{
	t_list	*head;
	int		bytes_read;
	int		check_line;
	t_list	*new_node;

	bytes_read = make_node(fd, &new_node);
	if (bytes_read <= 0)
		return (NULL);
	head = new_node;
	check_line = ft_check_end_line(head, bytes_read, head);
	while (check_line == 0)
	{
		bytes_read = make_node(fd, &new_node->next);
		new_node = new_node->next;
		check_line = ft_check_end_line(new_node, bytes_read, head);
	}
	if (check_line && ft_lstsize(new_node) != check_line && bytes_read > 0)
		new_node->content = get_line(new_node->content, rest_node, check_line);
	else if (bytes_read < 0)
		return (NULL);
	return (join_content(&head));
}

static int	make_node(int fd, t_list **lst_node)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (0);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		free(buffer);
	else if (bytes_read > 0)
		*lst_node = ft_lstnew(buffer);
	return (bytes_read);
}

static char	*join_content(t_list **lst)
{
	char	*str;
	int		iterator;
	int		size;
	int		second_iterator;
	t_list	*start_node;

	iterator = 0;
	start_node = *lst;
	size = ft_lstsize(*lst);
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (start_node)
	{
		second_iterator = 0;
		while (size && start_node->content[second_iterator])
		{
			str[iterator++] = start_node->content[second_iterator++];
			size--;
		}
		start_node = start_node->next;
	}
	ft_lstclear(lst);
	return (str);
}

static char	*get_line(char *content, t_list **rest_node, size_t len)
{
	char	*rest_of_content;
	char	*clear_content;
	int		iterator;
	char	*rest_result;

	rest_of_content = &content[len];
	iterator = 0;
	clear_content = (char *)ft_calloc(len + 1, sizeof(char));
	if (!clear_content)
		return (NULL);
	while (len--)
		clear_content[len] = content[len];
	while (rest_of_content[iterator])
		iterator++;
	rest_result = (char *)ft_calloc(iterator + 1, sizeof(char));
	if (!rest_result)
		return (NULL);
	while (iterator--)
		rest_result[iterator] = rest_of_content[iterator];
	*rest_node = ft_lstnew(rest_result);
	free(content);
	return (clear_content);
}
