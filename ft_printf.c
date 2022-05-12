/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:02:37 by vmourtia          #+#    #+#             */
/*   Updated: 2022/05/12 15:35:13 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

static void	put_unbr(unsigned int n)
{
	if (n <= 9)
		ft_putchar_fd(n + '0', 1);
	else
	{
		ft_putnbr_fd(n / 10, 1);
		ft_putnbr_fd(n % 10, 1);
	}
}

static void	putnbr_hex(char *base_hexa, int n)
{
	if (n == INT_MIN)
		ft_putstr_fd("-80000000", 1);
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar_fd('-', 1);
		}
		if (n < 16)
			ft_putchar_fd(base_hexa[n], 1);
		else
		{
			putnbr_hex(base_hexa, n / 16);
			putnbr_hex(base_hexa, n % 16);
		}
	}
}

static char	*gen_hexabase(int lower_mode)
{
	char	*base_hexa;
	int		i;

	base_hexa = malloc(17 * sizeof(char));
	i = 0;
	while (i < 10)
	{
		base_hexa[i] = '0' + i;
		i++;
	}
	while (i < 16)
	{
		if (lower_mode)
			base_hexa[i] = 'a' + i - 10;
		else
			base_hexa[i] = 'A' + i - 10;
		i++;
	}
	base_hexa[i] = '\0';
	return (base_hexa);
}

static void	putnbr_dec_to_hexa(int lower_mode, va_list args)
{
	char	*base;

	base = gen_hexabase(lower_mode);
	putnbr_hex(base, va_arg(args, int));
	free(base);
}

static void	check_options(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'i' || c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		put_unbr(va_arg(args, unsigned int));
	else if (c == 'x')
		putnbr_dec_to_hexa(1, args);
	else if (c == 'X')
		putnbr_dec_to_hexa(0, args);
	else if (c == '%')
		ft_putchar_fd(c, 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	s_length;
	size_t	i;

	va_start(args, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			check_options(s[++i], args);
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(args);
	s_length = ft_strlen(s);
	return (s_length);
}
/*
int main(void)
{
	int		len;
	
    len = ft_printf("(c) Character to display : %c.\n(s) String to display : %s.\n(d) Decimal to display : %d.\n(i) Int to display : %i.\n(u) Unsigned decimal to display : %u.\n(x) Hexadecimal lowercase to display : %x.\n(X) Hexadecimal uppercase to display : %X.\n(%%) .\n", 'A', "AH!", INT_MIN, INT_MAX, UINT_MAX, INT_MIN, INT_MAX);
	ft_printf("\nString length : %i.\n", len);
	return (0);
}*/
