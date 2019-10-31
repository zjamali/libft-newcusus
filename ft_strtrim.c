/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:31:40 by zjamali           #+#    #+#             */
/*   Updated: 2019/10/31 22:37:25 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_beginstr(char const *s1, char const *set)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (!(ft_strchr(set, s1[i])))
			return (i);
		i++;
	}
	return (i);
}

static int		ft_endstr(char const *s1, char const *set)
{
	size_t i;

	i = ft_strlen(s1);
	while (i > 0)
	{
		if (!(ft_strchr(set, s1[i])))
			return (i);
		i--;
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		indb;
	int		inde;
	int		i;
	char	*res;

	if (s1 && set)
	{
		indb = ft_beginstr(s1, set);
		inde = ft_endstr(s1, set);
		if (inde - indb < 0)
			return ("");
		if (!(res = (char *)malloc(sizeof(char) * (inde - indb + 2))))
			return (NULL);
		i = 0;
		while (indb <= inde)
		{
			res[i] = s1[indb];
			indb++;
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
