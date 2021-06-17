/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:04:36 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/17 14:05:47 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	if (!dst && size == 0)
		return (srclen);
	dstlen = ft_strlen(dst);
	if (size <= dstlen)
		return (srclen + size);
	size = size - dstlen;
	while (*dst)
		dst++;
	ft_strlcpy(dst, src, size);
	return (srclen + dstlen);
}
