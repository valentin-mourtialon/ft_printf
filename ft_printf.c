/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:02:37 by vmourtia          #+#    #+#             */
/*   Updated: 2022/06/07 11:47:46 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_unsgn_nbr_base(\
	char *base,
	unsigned int base_length,
	unsigned long n)
{
	if (n < base_length)
		ft_putchar_fd(base[n], 1);
	else
	{
		put_unsgn_nbr_base(base, base_length, n / base_length);
		put_unsgn_nbr_base(base, base_length, n % base_length);
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

static void	put_unsgn_dec_to_hexa(int lower_mode, va_list args)
{
	char			*base_hexa;

	base_hexa = gen_hexabase(lower_mode);
	put_unsgn_nbr_base(\
		base_hexa, ft_strlen(base_hexa), va_arg(args, unsigned long));
	free(base_hexa);
}

static void	check_options(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		put_unsgn_dec_to_hexa(1, args);
	else if (c == 'i' || c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		put_unsgn_nbr_base("0123456789", 10, va_arg(args, unsigned int));
	else if (c == 'x')
		put_unsgn_dec_to_hexa(1, args);
	else if (c == 'X')
		put_unsgn_dec_to_hexa(0, args);
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

int main(void)
{
	unsigned int	u1 = 1245;
	unsigned int	u2 = 37;
	unsigned int	u3 = 0;
	int				len;
	void			*p;
	
	len = ft_printf("\nTests :\n");
	p = &len;

	ft_printf("\nft_printf character %%c    = %c", 'A');
	ft_printf("\nft_printf string    %%s    = %s", "AH!");
	ft_printf("\nft_printf void *ptr %%p    = %p || %p || %p || %p", p, (void *)&u1, (void *)&u2, (void *)&u3);
	ft_printf("\nft_printf int (dec) %%d    = %d || %d || %d || %d || %d || %d", INT_MIN, INT_MAX, -34, 0, -0, 9);
	ft_printf("\nft_printf int       %%i    = %i || %i || %i || %i || %i || %i", INT_MIN, INT_MAX, -34, 0, -0, 9);
	ft_printf("\nft_printf unsigned  %%u    = %u || %u || %u || %u", UINT_MAX, u1, u2, u3);
	ft_printf("\nft_printf unsigned  %%x    = %x || %x || %x || %x", UINT_MAX, u1, u2, u3);
	ft_printf("\nft_printf unsigned  %%X    = %X || %X || %X || %X", UINT_MAX, u1, u2, u3);
	ft_printf("\n\n");

	printf("\nprintf character    %%c       = %c", 'A');
	printf("\nprintf string       %%s       = %s", "AH!");
	printf("\nprintf void *ptr    %%p       = %p || %p || %p || %p", p, (void *)&u1, (void *)&u2, (void *)&u3);
	printf("\nprintf int (dec)    %%d       = %d || %d || %d || %d || %d || %d", INT_MIN, INT_MAX, -34, 0, -0, 9);
	printf("\nprintf int          %%i       = %i || %i || %i || %i || %i || %i", INT_MIN, INT_MAX, -34, 0, -0, 9);
	printf("\nprintf unsigned     %%u       = %u || %u || %u || %u", UINT_MAX, u1, u2, u3);
	printf("\nprintf unsigned     %%x       = %x || %x || %x || %x", UINT_MAX, u1, u2, u3);
	printf("\nprintf unsigned     %%X       = %X || %X || %X || %X", UINT_MAX, u1, u2, u3);
	printf("\n\n");

	return (0);
}