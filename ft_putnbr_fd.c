/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:56:19 by zjamali           #+#    #+#             */
/*   Updated: 2019/10/29 21:23:19 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + '0', fd);
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n >= -9 && n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd((-1 * n) + '0', fd);
	}
	else if (n < -9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(-1 * (n % 10) + '0', fd);
	}
}
