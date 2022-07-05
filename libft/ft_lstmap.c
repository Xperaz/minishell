/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:54:21 by houazzan          #+#    #+#             */
/*   Updated: 2021/11/15 19:19:17 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*lst1;

	head = NULL;
	while (lst != NULL)
	{
		lst1 = ft_lstnew(f(lst->content));
		if (lst1 == NULL)
		{
			ft_lstclear(&head, del);
		}
		ft_lstadd_back(&head, lst1);
		lst = lst->next;
	}
	return (head);
}
