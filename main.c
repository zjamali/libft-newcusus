/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:26:17 by zjamali           #+#    #+#             */
/*   Updated: 2019/11/05 21:55:01 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*f(void *content)
{
	char *s;	
	s = strdup(content);
	*s = *s - 32;
	return (s);
}
void del(void *content)
{
	free(content);
}

int main()
{
	t_list *head;
	int i = 0;
	head = ft_lstnew(strdup("k"));
	t_list *temp;
	temp = head;
	while(i < 5)
	{
		temp->next = ft_lstnew(ft_strdup("i"));
		temp = temp->next;
		i++;
	}
	temp = head;	
	while(temp)
	{
		printf("%s",temp->content);
		temp = temp->next;
	}

	printf("\n");
	t_list *new ;
	new = ft_lstmap(head,&f,&del);
	while(new)
	{
		printf("%s",new->content);
		new = new->next;
	}
	printf("\n");
	while(head)
	{
		printf("%s",head->content);
		head = head->next;
	}
}
