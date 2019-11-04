/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:20:55 by zjamali           #+#    #+#             */
/*   Updated: 2019/11/04 20:31:39 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list *new_lst;
	int	len;
	int i;
	t_list *temp;
	t_list *tempnew;
	len = ft_lstsize(lst);
	new_lst = (t_list*)malloc(sizeof(t_list));
	temp = lst;
	tempnew = new_lst;
	i = 0;
	while (i < len)
	{
		if(!(tempnew->next = (t_list*)malloc(sizeof(t_list))))
		{
			ft_lstclear(&new_lst,del);
			return NULL;
		}
		tempnew = tempnew->next;
		i++;
	}
	temp = lst;
	tempnew = new_lst;
	i = 0;
	while (lst)
	{
		new_lst->content = f(lst->content);
		lst = lst->next;
		new_lst = new_lst->next;
		i++;
	}
	return tempnew;
}

