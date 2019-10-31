/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:43:53 by zjamali           #+#    #+#             */
/*   Updated: 2019/10/22 19:27:27 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	size;
	char	*s2;

	size = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	else
	{
		while (*s1)
		{
			*s2 = *s1;
			s1++;
			s2++;
		}
		*s2 = '\0';
		return (s2 - size);
	}
}
