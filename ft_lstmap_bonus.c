/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:20:55 by zjamali           #+#    #+#             */
/*   Updated: 2019/11/05 23:13:04 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*allocation(t_list *lst, void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tempnew;
	int		len;
	int		i;

	if (!lst)
		return (NULL);
	len = ft_lstsize(lst);
	newlst = (t_list*)malloc(sizeof(t_list));
	tempnew = newlst;
	i = 1;
	while (i < len)
	{
		if (!(tempnew->next = (t_list*)malloc(sizeof(t_list))))
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		tempnew = tempnew->next;
		i++;
	}
	tempnew->next = NULL;
	return (newlst);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*tempnew;
	int		i;

	i = 0;
	newlist = allocation(lst, del);
	tempnew = newlist;
	while (i < ft_lstsize(newlist))
	{
		tempnew->content = f(lst->content);
		lst = lst->next;
		tempnew = tempnew->next;
		i++;
	}
	return (newlist);
}
