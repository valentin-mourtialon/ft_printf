/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:02:37 by vmourtia          #+#    #+#             */
/*   Updated: 2022/05/10 16:12:08 by vmourtia         ###   ########.fr       */
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

int ft_printf(const char *s, ...)
{
	va_list	lst_arg;
	size_t	s_length;
	size_t	i;

	va_start(lst_arg, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c')
				ft_putchar_fd(*((char *)va_arg(lst_arg, void *)), 1);
			else if (s[i] == 's')
				ft_putstr_fd((char *)va_arg(lst_arg, void *), 1);
		}
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(lst_arg);
	s_length = ft_strlen(s);
    return (s_length);
}

int main(void)
{
	int	a;
	
    a = ft_printf("Character to display : %c!\nString to display : %s!\n", 'A', "AH!");
	return (a);
}

