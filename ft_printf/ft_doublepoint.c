/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublepoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 00:59:33 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 14:16:27 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_doublepointint(char *s, va_list args, int nb, int num)
{
	int i;
	int j;
	int l;

	i = va_arg(args, int);
	ft_doublepointhelper(s, &j, i);
	l = num;
	if (nb >= 0)
	{
		ft_pospoint(&i, &nb, &num, &j);
		ft_negpoint(&i, &nb, &num, &j);
		ft_zeropoin(&i, &nb, &num, &j);
		if ((format_specifier(s) == 'x' || format_specifier(s) == 'X') && i < 0)
			nb++;
		while (nb-- > 0)
			ft_putchar(' ');
		if (i < 0 && (format_specifier(s) == 'd' || format_specifier(s) == 'i'))
		{
			ft_putchar('-');
			i *= -1;
		}
		ft_printpo(s, l, i, num);
	}
	else
		ft_doublepointneg(s, i, num, nb);
}

void		ft_zeropoin(int *i, int *nb, int *num, int *j)
{
	if (*i == 0)
	{
		if (*num < 0)
		{
			*num = 0;
			*nb = *nb - *j;
		}
		else if (*num == 0 && *nb == 0)
			ft_putstr("");
		else
		{
			*nb = *nb - *num;
			*num = *num - *j;
		}
	}
}

void		ft_negpoint(int *i, int *nb, int *num, int *j)
{
	if (*i < 0)
	{
		if (*num < 0)
		{
			*num = 0;
			*nb = *nb - *j;
		}
		else if (*num == 0 || *num < *j)
		{
			*nb = *nb - *j;
			*num = *num - *j;
		}
		else if (*nb > *num)
		{
			*nb = *nb - (*num + 1);
			*num = *num - (*j - 1);
		}
		else if (*nb <= *num)
		{
			*nb = -1;
			*num = *num - (*j - 1);
		}
	}
}

void		ft_pospoint(int *i, int *nb, int *num, int *j)
{
	if (*i > 0)
	{
		if (*num < 0)
		{
			*num = 0;
			*nb = *nb - *j;
		}
		else if (*nb == 0 && *num > 0)
			*num = *num - (*j - 1);
		else if (*num == 0 || *num < *j)
		{
			*nb = *nb - *j;
			*num = *num - *j;
		}
		else if (*nb <= *num)
		{
			*nb = 0;
			*num = *num - *j;
		}
		else if (*nb > *num)
		{
			*nb = *nb - *num;
			*num = *num - *j;
		}
	}
}

void		ft_printpo(char *s, int l, int i, int num)
{
	while (num-- > 0)
		ft_putchar('0');
	if (format_specifier(s) == '%')
		ft_putchar('%');
	else if (l != 0 || i != 0)
	{
		if (format_specifier(s) == 'd' || format_specifier(s) == 'i')
			ft_putunsigned(i);
		else if (format_specifier(s) == 'x')
			ft_putstr(ft_hexaa(i));
		else if (format_specifier(s) == 'X')
			ft_putstr(ft_hexa(i));
		else
		{
			ft_putstr("0x");
			ft_putstr(ft_hexap(i));
		}
	}
	else if (l == 0 && format_specifier(s) == 'p')
		ft_putstr("0x");
}
