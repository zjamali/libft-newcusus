/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 22:00:57 by zjamali           #+#    #+#             */
/*   Updated: 2019/10/31 22:27:20 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstprint(t_list *lst)
{
	while(lst)
	{
		printf("%s",(char*)lst->content);
		printf("i");
		lst = lst->next;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	

}

int main()
{
	t_list *head;
	t_list *temp;
	temp = head;
	int i = 0;
	while(i < 5)
	{

		head= (t_list*)malloc(sizeof(t_list));
		head->content = "i";
		head = head->next;
		i++;
	}
	ft_lstprint(temp);
	return 0;
}
