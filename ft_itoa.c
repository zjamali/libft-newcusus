/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:02:58 by zjamali           #+#    #+#             */
/*   Updated: 2019/10/31 22:31:38 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		much(int n)
{
	int counter;

	counter = 0;
	if (n < 0)
		counter++;
	if (n == 0)
		counter++;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		c;
	int		res;

	len = much(n);
	c = 0;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		c = 1;
		str[0] = '-';
	}
	while (len >= c)
	{
		if (n < 0)
			res = (n % 10) * -1;
		else
			res = n % 10;
		str[len--] = res + '0';
		n = n / 10;
	}
	return (str);
}
