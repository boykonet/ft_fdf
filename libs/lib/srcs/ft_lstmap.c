/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarina <gkarina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 14:49:00 by gkarina           #+#    #+#             */
/*   Updated: 2020/05/13 14:49:00 by gkarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*mapping(t_list **head, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*prev;
	void	*new_content;

	head = ft_lstnew((*f)(current->content));
	if (head == NULL)
		return (NULL);
	current = current->next;
	while (current != NULL)
	{
		prev = current;
		current = current->next;
		new_content = (*f)(prev->content);
		node = ft_lstnew(new_content);
		if (node == NULL)
		{
			ft_lstclear(&head, del);
			return (-1);
		}
		ft_lstadd_back(&head, node);
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	current = lst;
	if (lst == NULL)
		return (NULL);
	if (mapping(&head, f, del) == -1)
		return (NULL);
	return (head);
}
