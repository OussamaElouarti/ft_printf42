/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:58:53 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 13:13:50 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern int g_a;

void		ft_do_fhelper(va_list args, char *s, int i)
{
	if (s[i] == '.')
	{
		i++;
		if (s[i] == '*')
		{
			s = ft_star((char *)s + i, args);
			i = 0;
			if (s[i] == '-')
			{
				format_specifiers(args, (char*)s + i, 'd');
				i += ft_escape((char *)s + i);
				i++;
			}
		}
		format_specifierspoint(args, (char*)s + i);
	}
	else if (s[i] == 'd' || s[i] == 's' || s[i] == 'c'
		|| s[i] == 'u' || s[i] == 'i' || s[i] == 'p' || s[i] == 'x'
		|| s[i] == 'X' || (s[i] > '0' && s[i] <= '9'))
		format_specifiers(args, (char *)s + i, ' ');
	else if (s[i] == '%')
	{
		ft_putchar('%');
		i++;
	}
}

void		ft_do_shelper(va_list args, char *s, int i)
{
	if (s[i] == '-')
	{
		if (s[i + 1] == '*')
		{
			if (s[i + 2] == '.')
			{
				s = ft_star((char *)s + i, args);
				i = 0;
				format_specifiers(args, (char*)s + i, 'd');
				i += ft_escape((char *)s + i);
			}
			else
				format_specifiers(args, (char *)s + i, ' ');
		}
		else if (s[i + 1] == '%')
		{
			ft_putchar('%');
			i++;
		}
		else
			format_specifiers(args, (char *)s + i, ' ');
		i++;
	}
}

void		ft_do(va_list args, char *s, int i)
{
	ft_do_fhelper(args, s, i);
	ft_do_shelper(args, s, i);
	if (s[i] == '0')
	{
		i++;
		if (s[i] == '%')
		{
			ft_putchar('%');
			i++;
		}
		else if (s[i] == '*')
		{
			if (s[i + 1] == '.')
			{
				s = ft_star((char *)s + (i - 1), args);
				i = 0;
				format_specifiers(args, (char*)s + i, 'd');
				i += ft_escape((char *)s + i);
			}
			else
				format_specifiers(args, (char *)s + i, ' ');
		}
		else
			format_specifiers(args, (char *)s + (i - 1), '0');
	}
}

int			ft_printf(const char *s, ...)
{
	va_list		args;
	int			i;

	i = 0;
	g_a = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			ft_do(args, (char *)s, i);
			if (s[i] == '*')
			{
				s = ft_star((char *)s + i, args);
				i = 0;
				ft_do(args, (char *)s, i);
			}
			i += ft_escape((char *)s + i);
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	return (g_a);
}
