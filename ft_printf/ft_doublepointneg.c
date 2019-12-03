/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublepointneg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 05:06:23 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 14:02:41 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_doublepointneg(char *s, int i, int num, int nb)
{
	int j;
	int l;

	if (format_specifier(s) == 'x' || format_specifier(s) == 'X')
	{
		j = ft_strlen(ft_hexaa(i));
		if (i < 0)
			j++;
	}
	else
		j = ft_strlen(ft_itoa(i));
	l = num;
	nb *= -1;
	ft_pospoint(&i, &nb, &num, &j);
	ft_negpoint(&i, &nb, &num, &j);
	ft_zeropoin(&i, &nb, &num, &j);
	if (i < 0 && (format_specifier(s) == 'd' || format_specifier(s) == 'i'))
	{
		ft_putchar('-');
		i *= -1;
	}
	ft_printpo(s, l, i, num);
	ft_doublepointneghelper(s, &nb, i);
}

void		ft_doublepointhelper(char *s, int *j, int i)
{
	if (format_specifier(s) == 'x' || format_specifier(s) == 'X')
	{
		*j = ft_strlen(ft_hexaa(i));
		if (i < 0)
			*j += 1;
	}
	else
		*j = ft_strlen(ft_itoa(i));
}

void		format_specifier_fohelp(va_list args, char *s)
{
	if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(args, int));
	else if (*s == 's')
		ft_putstr(va_arg(args, char*));
	else if (*s == 'c')
		ft_putchar(va_arg(args, int));
	else if (*s == 'X')
		ft_putstr(ft_hexa(va_arg(args, int)));
	else if (*s == 'x')
		ft_putstr(ft_hexaa(va_arg(args, int)));
	else if (*s == 'p')
	{
		ft_putstr("0x");
		ft_putstr(ft_hexap((size_t)(va_arg(args, void *))));
	}
	else if (*s == 'u')
		ft_putunsigned(va_arg(args, unsigned int));
}

void		format_specifier_thelp(va_list args, char **s, char c)
{
	if (format_specifier(*s) == '.')
	{
		if (format_specifier(*s) == '*')
		{
			*s = ft_star((char *)*s, args);
			ft_doublepreci(args, *s);
		}
		else
			ft_doublepreci(args, *s - 1);
	}
	else
		ft_printmoins(args, *s, c);
}

void		format_specifier_fhelp(va_list args, char **s, int i, char c)
{
	*s += 1;
	if (**s > '0' && **s <= '9' && i != -1 && format_specifier(*s) == '.')
	{
		if (format_specifier(*s) == '*')
		{
			*s = ft_star((char *)*s, args);
			ft_doublepreci(args, *s);
		}
		else
			ft_doublepreci(args, *s - 1);
	}
	else
		format_specifiers(args, *s, c);
}
