/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:46:04 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 04:33:43 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_moinsstring(char *s, va_list args, char c)
{
	int		k;
	int		i;
	char	*str;

	if (!(str = va_arg(args, char*)))
		str = ft_strdup("(null)");
	k = ft_atoi(s);
	if (c == 'd')
		k = 0;
	i = ft_strlen(str);
	k = k - i;
	ft_putstr(str);
	if (k > 0)
	{
		while (k)
		{
			ft_putchar(c);
			k--;
		}
	}
}

void		ft_moinshexa(char *s, va_list args, char c)
{
	int k;
	int i;
	int j;

	i = va_arg(args, int);
	j = ft_strlen(ft_hexaa(i));
	k = ft_atoi(s);
	k = k - j;
	if (format_specifier((char*)s) == 'x')
		ft_putstr(ft_hexaa(i));
	else
		ft_putstr(ft_hexa(i));
	if (c == 'd')
		k = 0;
	if (k > 0)
	{
		while (k)
		{
			ft_putchar(c);
			k--;
		}
	}
}

void		ft_moinspointer(char *s, va_list args, char c)
{
	int		k;
	size_t	i;
	int		j;

	i = (size_t)va_arg(args, int);
	j = ft_strlen(ft_hexap(i)) + 2;
	k = ft_atoi(s);
	k = k - j;
	ft_putstr("0x");
	ft_putstr(ft_hexap(i));
	if (k > 0)
	{
		while (k)
		{
			ft_putchar(c);
			k--;
		}
	}
}

void		ft_moinsint(char *s, va_list args, char c)
{
	int k;
	int i;
	int j;

	i = 0;
	ft_spaceinthelp(&i, &j, s, args);
	k = ft_atoi(s);
	k = k - j;
	if (format_specifier(s) == '%')
		ft_putchar('%');
	else
		ft_putnbr(i);
	if (c == 'd')
		k = 0;
	if (k > 0)
	{
		while (k)
		{
			ft_putchar(c);
			k--;
		}
	}
}

void		ft_moinschar(char *s, va_list args, char c)
{
	int		k;
	char	i;

	i = va_arg(args, int);
	k = ft_atoi(s);
	k--;
	ft_putchar(i);
	if (k > 0)
	{
		while (k)
		{
			ft_putchar(c);
			k--;
		}
	}
}
