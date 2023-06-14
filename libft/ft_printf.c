/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:00:24 by cacarval          #+#    #+#             */
/*   Updated: 2023/05/26 16:04:42 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(va_list args, const char format)
{
	if (format == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == 'd' || format == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_printpercent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	arg;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start (arg, format);
	while (format[i])
	{
		if (format[i] != '%')
			print_len += ft_printchar(format[i]);
		else
			print_len += ft_formats(arg, format[++i]);
		i++;
	}
	va_end(arg);
	return (print_len);
}

// int main()
// {
// 	int *c;
// 	int a;
// 	a = 5;
// 	c = &a;
// 	ft_printf("%x\n", c);
// 	printf("%x", c);
// 	return(0);
// }