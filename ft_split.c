/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:27:26 by zjamali           #+#    #+#             */
/*   Updated: 2019/10/31 22:36:41 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			*leak(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static int			nmwords(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int			nmchars(char const *s, char c, int i)
{
	int size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static void			fillin(char const *s, int i, char tab[], int len)
{
	int k;

	k = 0;
	while (k < len)
	{
		tab[k++] = s[i++];
	}
	tab[k] = '\0';
}

char				**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;
	int		words;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	words = nmwords(s, c);
	if (!(tab = malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	tab[words] = NULL;
	j = 0;
	while (words--)
	{
		while (s[i] == c)
			i++;
		len = nmchars(s, c, i);
		if (!(tab[j++] = malloc(sizeof(char) * ((len + 1)))))
			return (leak(tab));
		fillin(s, i, tab[j - 1], len);
		i = i + len;
	}
	return (tab);
}
