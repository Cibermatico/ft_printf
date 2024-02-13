/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:53:25 by lsquarci          #+#    #+#             */
/*   Updated: 2024/01/30 21:53:25 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char type, va_list *ap)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += print_char(va_arg(*ap, int));
	else if (type == 's')
		count = count + print_str(va_arg(*ap, char *));
	else if (type == 'd' || type == 'i')
		count = count + print_decimal(va_arg(*ap, int));
	else if (type == 'x')
		count = count + print_hex(va_arg(*ap, unsigned int));
	else if (type == 'u')
		count = count + print_uint(va_arg(*ap, unsigned int));
	else if (type == 'p')
		count = count + print_ptr(va_arg(*ap, uintptr_t));
	else if (type == '%')
		count += print_char('%');
	else if (type == 'X')
		count += print_up_hex(va_arg(*ap, unsigned int));
	else
		count += write(1, &type, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count = count + print_format(format[i + 1], &ap);
			i++;
		}
		else
			count = count + print_char(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
