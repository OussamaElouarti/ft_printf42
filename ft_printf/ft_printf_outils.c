/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 02:23:49 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 08:23:34 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		format_specifierspoint(va_list args, char *s)
{
	int i;

	i = 0;
	format_specifierspoint_helper(args, s, i);
	if (*s == 'p')
	{
		if (*s == 'p' && ((i = (int)va_arg(args, void*)) != 0))
		{
			ft_putstr("0x");
			ft_putstr(ft_hexap((size_t)i));
		}
		else
			ft_putstr("0x");
	}
	else if (*s == 'u' && (i = va_arg(args, unsigned int)) != 0)
		ft_putunsigned(i);
	else if (*s == 'u' && i == 0)
		ft_putstr("");
	else if ((*s > '0' && *s <= '9') || *s == '-')
		ft_printpoint(args, s);
	else if (*s == '0')
	{
		s++;
		format_specifierspoint(args, s);
	}
}

void		ft_printpoint(va_list args, char *s)
{
	if (format_specifier(s) == 'd' || format_specifier(s) == 'i')
		ft_pointint(s, args);
	else if (format_specifier(s) == 'c')
		ft_spacechar(s, args, '0');
	else if (format_specifier(s) == 's')
		ft_pointstring(s, args);
	else if (format_specifier(s) == 'p')
		ft_spacepointer(s, args, '0');
	else if (format_specifier(s) == 'x' || format_specifier(s) == 'X')
		ft_spacehexa(s, args, '0');
	else if (format_specifier(s) == 'u')
		ft_pointunint(s, args);
	else if (format_specifier(s) == '%')
		ft_putchar('%');
}

void		ft_doublepreci(va_list args, char *s)
{
	int i;
	int j;
	int k;

	k = 0;
	while (format_specifier(s + k) == '.')
		k++;
	if (*s == '-' && format_specifier(s + k) == 'c')
		ft_moinschar(s + 1, args, ' ');
	else if (format_specifier(s + k) == 'c')
		ft_spacechar(s, args, ' ');
	i = double_precihelper(s, &k, &j, args);
	if (format_specifier(s + k) == 'd' || format_specifier(s + k) == 'i'
	|| format_specifier(s + k) == 'x' || format_specifier(s + k) == 'X')
		ft_doublepointint(s + k, args, i, j);
	else if (format_specifier(s + k) == '%')
		ft_doublepointcent(s + k, i, j);
	else if (format_specifier(s + k) == 'p')
		ft_doublepointpointer(s + k, args, i, j);
	else if (format_specifier(s + k) == 's')
		ft_doublepoints(args, i, j);
	else if (format_specifier(s + k) == 'u')
		ft_doublepointun(args, i, j);
}

void		format_specifierspoint_helper(va_list args, char *s, int i)
{
	if (*s == 'd' || *s == 'i')
	{
		if ((i = va_arg(args, int)) != 0)
			ft_putnbr(i);
		else
			ft_putstr("");
	}
	else if (*s == '%')
		ft_putchar('%');
	else if (*s == 's')
	{
		i = va_arg(args, int);
		ft_putstr("");
	}
	else if (*s == 'c')
		ft_putchar(va_arg(args, int));
	else if (*s == 'x' || *s == 'X')
	{
		if (*s == 'x' && ((i = va_arg(args, int)) != 0))
			ft_putstr(ft_hexaa(i));
		else if (*s == 'X' && ((i = va_arg(args, int)) != 0))
			ft_putstr(ft_hexa(i));
		else
			ft_putstr("");
	}
}

int			double_precihelper(char *s, int *k, int *j, va_list args)
{
	int i;

	i = ft_atoi(s);
	*j = ft_atoi(s + *k);
	if (format_specifier(s + *k) == '*')
	{
		*j = va_arg(args, int);
		*k += 1;
	}
	if (*s == '0')
	{
		if ((format_specifier(s + *k) == 'd' || format_specifier(s + *k) == 'i'
		|| format_specifier(s + *k) == 'x' || format_specifier(s + *k) == 'X'
		|| format_specifier(s + *k) == 'u') && (*j < 0 && i > 0))
		{
			if (*j < 0)
				*j = i - 1;
			else
				*j = i;
			i = 0;
		}
	}
	return (i);
}
