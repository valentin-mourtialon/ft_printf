/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:02:37 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/07 15:27:43 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_fd(int n, int fd, size_t *output_length)
{
	if (n == INT_MIN)
		ft_putstr_fd("-2147483648", fd, output_length);
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar_fd('-', fd, output_length);
		}
		if (n <= 9)
			ft_putchar_fd(n + '0', fd, output_length);
		else
		{
			ft_putnbr_fd(n / 10, fd, output_length);
			ft_putnbr_fd(n % 10, fd, output_length);
		}
	}
}

static void	put_unsgn_nbr_base(\
	char *base,
	unsigned int base_length,
	unsigned long n,
	size_t	*output_length)
{
	if (n < base_length)
		ft_putchar_fd(base[n], 1, output_length);
	else
	{
		put_unsgn_nbr_base(base, base_length, n / base_length, output_length);
		put_unsgn_nbr_base(base, base_length, n % base_length, output_length);
	}
}

static void	put_ptr_to_hexa(va_list args, size_t *output_length)
{
	unsigned long	p;

	p = va_arg(args, unsigned long);
	if ((void *)p == NULL)
		ft_putstr_fd("(nil)", 1, output_length);
	else
	{
		ft_putstr_fd("0x", 1, output_length);
		put_unsgn_nbr_base("0123456789abcdef", 16, p, output_length);
	}
}

static void	check_options(char c, va_list args, size_t *output_length)
{	
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1, output_length);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1, output_length);
	else if (c == 'p')
		put_ptr_to_hexa(args, output_length);
	else if (c == 'i' || c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1, output_length);
	else if (c == 'u')
		put_unsgn_nbr_base(
			"0123456789", 10, va_arg(args, unsigned int), output_length);
	else if (c == 'x')
		put_unsgn_nbr_base(
			"0123456789abcdef", 16, va_arg(args, unsigned int), output_length);
	else if (c == 'X')
		put_unsgn_nbr_base(
			"0123456789ABCDEF", 16, va_arg(args, unsigned int), output_length);
	else if (c == '%')
		ft_putchar_fd(c, 1, output_length);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	output_length;
	size_t	i;

	va_start(args, s);
	i = 0;
	output_length = 0;
	while (s[i])
	{
		if (s[i] == '%')
			check_options(s[++i], args, &output_length);
		else
			ft_putchar_fd(s[i], 1, &output_length);
		i++;
	}
	va_end(args);
	return (output_length);
}
