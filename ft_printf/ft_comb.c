/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:16:12 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 13:22:30 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_spacestring(char *s, va_list args, char c)
{
	int		k;
	int		i;
	char	*str;

	if (!(str = va_arg(args, char*)))
		str = ft_strdup("(null)");
	k = ft_atoi(s);
	i = ft_strlen(str);
	k = k - i;
	if (k > 0)
	{
		while (k)
		{
			ft_putchar(c);
			k--;
		}
	}
	ft_putstr(str);
}

void		ft_spacehexa(char *s, va_list args, char c)
{
	int k;
	int i;
	int j;

	i = va_arg(args, int);
	j = ft_strlen(ft_hexaa(i));
	k = ft_atoi(s);
	k = k - j;
	if (k > 0)
		while (k--)
			ft_putchar(c);
	if (format_specifier((char*)s) == 'x')
		ft_putstr(ft_hexaa(i));
	else
		ft_putstr(ft_hexa(i));
}

void		ft_spacepointer(char *s, va_list args, char c)
{
	int		k;
	size_t	i;
	int		j;

	i = (size_t)va_arg(args, void*);
	j = ft_strlen(ft_hexap(i)) + 2;
	k = ft_atoi(s);
	k = k - j;
	if (k > 0)
	{
		while (k)
		{
			ft_putchar(c);
			k--;
		}
	}
	ft_putstr("0x");
	ft_putstr(ft_hexap(i));
}

void		ft_spaceint(char *s, va_list args, char c)
{
	int k;
	int i;
	int	j;

	i = 0;
	ft_spaceinthelp(&i, &j, s, args);
	k = ft_atoi(s);
	k = k - j;
	if (i < 0 && c == '0')
		ft_putchar('-');
	if (k > 0)
		while (k--)
			ft_putchar(c);
	if (i < 0)
	{
		if (c == ' ')
			ft_putchar('-');
		i *= -1;
	}
	if (format_specifier(s) == '%')
		ft_putchar('%');
	else
		ft_putunsigned(i);
}

void		ft_spacechar(char *s, va_list args, char c)
{
	int		k;
	char	i;

	i = va_arg(args, int);
	k = ft_atoi(s);
	k--;
	if (k > 0)
	{
		while (k)
		{
			ft_putchar(c);
			k--;
		}
	}
	ft_putchar(i);
}
