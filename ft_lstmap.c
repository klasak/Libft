/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/30 12:37:40 by klasak        #+#    #+#                 */
/*   Updated: 2021/02/01 14:35:01 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*element;
	t_list	*new_list;

	if (!lst || !f)
		return (NULL);
	temp = lst;
	new_list = ft_lstnew(f(temp->content));
	if (!new_list)
		return (NULL);
	temp = temp->next;
	while (temp != NULL)
	{
		element = ft_lstnew(f(temp->content));
		if (element == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, element);
		temp = temp->next;
	}
	return (new_list);
}
