/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:12:01 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/07 15:48:46 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

void	ft_putchar_fd(char c, int fd, size_t *output_length)
{
	write(fd, &c, 1);
	(*output_length)++;
}

void	ft_putstr_fd(char *s, int fd, size_t *output_length)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		*output_length = *output_length + ft_strlen(s);
	}
	else
	{
		write(fd, "(null)", 6);
		*output_length = *output_length + 6;
	}
}
