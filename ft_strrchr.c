/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:39:57 by zjamali           #+#    #+#             */
/*   Updated: 2019/10/22 19:29:04 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (p[i])
	{
		i++;
	}
	if (p[i] == c)
		return (&p[i]);
	while (i >= 0)
	{
		if (p[i] == c)
			return (&p[i]);
		i--;
	}
	return (NULL);
}
