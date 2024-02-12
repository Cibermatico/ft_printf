/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:40:18 by lsquarci          #+#    #+#             */
/*   Updated: 2024/02/12 18:59:12 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int hex_dimension(unsigned long long int nbr)
{
	int magnitude = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		magnitude++;
	}	
	return magnitude;
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