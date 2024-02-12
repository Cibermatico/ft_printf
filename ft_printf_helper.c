/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:44:25 by lsquarci          #+#    #+#             */
/*   Updated: 2024/02/12 18:58:53 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}
void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}
char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	copy = (char *)malloc(i * sizeof(char) + 1);
	if (!copy)
		return (NULL);
	while (j <= i)
	{
		copy[j] = src[j];
		j++;
	}
	copy[i] = '\0';
	return (copy);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
static int	ft_magnitude(int number)
{
	int	res;

	res = 0;
	if (number == 0)
		return (1);
	while (number >= 1)
	{
		number = number / 10;
		res = res + 1;
	}
	return (res);
}

static int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power == 0)
		return (1);
	while (power >= 1)
	{
		result = nb * result;
		power--;
	}
	return (result);
}

static void	initialize(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

static void	sign_handle(int *a, int *b, int *c)
{
	*a = -*a;
	*b = 1;
	*c = 1;
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int		i;
	int		power;
	int		sign;

	initialize(&i, &power, &sign);
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr < 0)
		sign_handle(&nbr, &sign, &i);
	result = (char *)malloc((ft_magnitude(nbr) + 1 + sign) * sizeof(char));
	if (!result)
		return (NULL);
	power = ft_iterative_power(10, ft_magnitude(nbr) - 1);
	while (power >= 1)
	{
		result[i++] = (nbr / power) + 48;
		nbr = nbr % power;
		power = power / 10;
	}
	if (sign == 1)
		*result = '-';
	result[i] = '\0';
	return (result);
}