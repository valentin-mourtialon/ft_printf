/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:50:41 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/07 15:33:47 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd, size_t *output_length);
void	ft_putstr_fd(char *s, int fd, size_t *output_length);
int		ft_printf(const char *s, ...);

#endif