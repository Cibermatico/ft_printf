/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:28:35 by lsquarci          #+#    #+#             */
/*   Updated: 2024/02/12 19:22:20 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

#define HEX_LETTERS "0123456789abcdef"
#define HEX_UP_LETTERS "0123456789ABCDEF"

int ft_printf(const char *format, ...);

int	ft_putchar(char c);
int hex_dimension(unsigned long long int nbr);
int print_char(int c);
int print_str(char *str);
int print_decimal(int nbr);
int print_hex(unsigned int nbr);
int	print_uint(unsigned int n);
int print_ptr(unsigned long long ptr);
int print_up_hex(unsigned int nbr);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_itoa(int nbr);
void	ft_putstr(char *s);

#endif