/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:21:48 by zjamali           #+#    #+#             */
/*   Updated: 2019/11/04 15:26:11 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;
	while(*lst)
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		del(temp->content);
		free(temp);
	}
	temp = NULL;
	*lst = NULL;
}

