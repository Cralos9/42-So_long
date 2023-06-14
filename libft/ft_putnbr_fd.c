/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:23:10 by cacarval          #+#    #+#             */
/*   Updated: 2023/04/28 11:15:46 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	c;

	c = n;
	if (c < 0)
	{
		ft_putchar_fd ('-', fd);
		c = -c;
	}
	if (c > 9)
	{
		ft_putnbr_fd (c / 10, fd);
		c = c % 10;
	}
	ft_putchar_fd (c + 48, fd);
}
