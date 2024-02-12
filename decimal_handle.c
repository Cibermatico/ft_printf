/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:41:38 by lsquarci          #+#    #+#             */
/*   Updated: 2024/02/12 18:59:05 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_decimal(int nbr)
{
	char *res;
	res = 0;

	res = ft_itoa(nbr);
	ft_putstr(res);
	return (ft_strlen(res));
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