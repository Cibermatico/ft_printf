/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:40:18 by lsquarci          #+#    #+#             */
/*   Updated: 2024/02/13 11:55:38 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_dimension(unsigned long long int nbr)
{
	int	magnitude;

	magnitude = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		magnitude++;
	}
	return (magnitude);
}

int	print_hex(uintptr_t nbr)
{
	int	remainder;
	int	*container;
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	container = (int *)malloc(hex_dimension(nbr) * sizeof(int));
	while (j < hex_dimension(nbr))
		j++;
	while (nbr > 0)
	{
		remainder = nbr % 16;
		container[i++] = remainder;
		nbr = nbr / 16;
	}
	while (--i >= 0)
		ft_putchar(HEX_LETTERS[container[i]]);
	free(container);
	return (j);
}

int	print_up_hex(unsigned int nbr)
{
	int	remainder;
	int	*container;
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	container = (int *)malloc(hex_dimension(nbr) * sizeof(int));
	while (j < hex_dimension(nbr))
		j++;
	while (nbr > 0)
	{
		remainder = nbr % 16;
		container[i++] = remainder;
		nbr = nbr / 16;
	}
	while (--i >= 0)
		ft_putchar(HEX_UP_LETTERS[container[i]]);
	free(container);
	return (j);
}

int	print_ptr(uintptr_t ptr)
{
	int	count;

	count = 0;
	while (count < hex_dimension(ptr))
		count++;
	write(1, "0x", 2);
	if (ptr == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	print_hex(ptr);
	return (count + 2);
}
