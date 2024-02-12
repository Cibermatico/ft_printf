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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_putstr.c"
#include "ft_itoa.c"
#include "ft_strlen.c"
#include "ft_putchar.c"
#define HEX_LETTERS "0123456789abcdef"
#define HEX_UP_LETTERS "0123456789ABCDEF"

static int hex_dimension(unsigned long long int nbr)
{
	int magnitude = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		magnitude++;
	}	
	return magnitude;
}

int print_char(int c)
{
	return (write(1, &c, 1));
}

int print_str(char *str)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		print_char((int)str[i]);
		i++;
		count++;
	}
	return (count);
}

int print_decimal(int nbr)
{
	char *res;
	res = 0;

	res = ft_itoa(nbr);
	ft_putstr(res);
	return (ft_strlen(res));
}

int print_hex(unsigned int nbr) 
{
	int remainder;
	int *container;
	int i;
	int j;

	j = 0;
	i = 0;
	container = (int *)malloc(hex_dimension(nbr) * sizeof(int));
	while (j < hex_dimension(nbr))
		j++;	
	while (nbr > 0) 
	{
		remainder = nbr % 16;
		container[i] = remainder;
		nbr = nbr / 16;
		i++;
	}
	while(--i >= 0) 
		ft_putchar(HEX_LETTERS[container[i]]);
	free(container);
	return (j);
}
int	print_uint(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
		count += ft_putchar(n + 48);
	else
	{
		count += print_uint(n / 10);
		count += print_uint(n % 10);
	}
	return (count);
}

int print_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	while (count < hex_dimension(ptr))
		count++;	
	write(1,"0x",2);	
	print_hex(ptr);
	
	return (count - 2);
}

int print_up_hex(unsigned int nbr) 
{
	int remainder;
	int *container;
	int i;
	int j;

	j = 0;
	i = 0;
	container = (int *)malloc(hex_dimension(nbr) * sizeof(int));
	while (j < hex_dimension(nbr))
		j++;	
	while (nbr > 0) 
	{
		remainder = nbr % 16;
		container[i] = remainder;
		nbr = nbr / 16;
		i++;
	}
	while(--i >= 0) 
		ft_putchar(HEX_UP_LETTERS[container[i]]);
	free(container);
	return (j);
} 

int print_format(char type, va_list *ap)
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
		count = count + print_ptr(va_arg(*ap, unsigned long long));
	else if (type == '%')
		count += print_char('%');
	else if (type == 'X')
		count += print_up_hex(va_arg(*ap, unsigned int));
	else 
		count += write(1, &type, 1);
	return (count);	
}

int ft_printf(const char *format, ...)
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

int main(void)
{
	int count;
	int intero;
	char *stringa;

	intero = 6;
	stringa = "aa";
	count = ft_printf("%% ciao %X\n", 255);
	printf("%d", count);	
	
	return 0;
}