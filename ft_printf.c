/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:02:37 by vmourtia          #+#    #+#             */
/*   Updated: 2022/05/12 12:03:28 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

/*int	count_args(const char *s)
{
	int	nb;
	int	i;
	
	nb = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			nb++;
			i++;
		}
		i++;
	}
	return (nb);
}*/

/*void	display_arg(char c, void *arg)
{
	if (c == 'c')
		ft_putchar_fd((*(char *)arg), 1);
	else if (c == 's')
		ft_putstr_fd((char *)arg, 1);
}*/

/*void	ft_put_unbr(unsigned int n)
{
	if (n == INT_MIN)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar_fd('-', fd);
		}
		if (n <= 9)
			ft_putchar_fd(n + '0', fd);
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}*/	

int ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	s_length;
	size_t	i;

	va_start(args, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			
			if (s[i] == 'c')
				//printf("%c", va_arg(args, int));
				ft_putchar_fd(va_arg(args, int), 1);
			else if (s[i] == 's')
				//printf("%s", va_arg(args, char *));
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (s[i] == 'i' || s[i] == 'd')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (s[i] == 'u')
				ft_put_unbr(va_arg(args, unsigned int));
		}
		else
			//printf("%c", s[i]);
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(args);
	s_length = ft_strlen(s);
    return (s_length);
}

int main(void)
{
	unsigned int	un=3000000000;
	int				len;
	
    len = ft_printf("(c) Character to display : %c.\n(s) String to display : %s.\n(d) Decimal to display : %d.\n(i) Int to display : %i.\n(u) Unsigned decimal to display : %u.\n", 'A', "AH!", -10478, 50, un);
	ft_printf("\nString length : %i.\n", len);
	return (0);
}

