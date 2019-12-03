/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublepoints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 06:37:12 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 14:01:11 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_doublepoints(va_list args, int nb, int num)
{
	char	*str;
	int		j;
	int		l;

	if (!(str = va_arg(args, char*)))
		str = ft_strdup("(null)");
	j = ft_strlen(str);
	l = 0;
	if (nb > 0)
	{
		ft_doublepointshelper(&num, &nb, j);
		while (nb-- > 0)
			ft_putchar(' ');
		while (l < j && l < num)
		{
			ft_putchar(str[l]);
			l++;
		}
	}
	else
		ft_doublepointsneg(str, num, nb, j);
}

void		ft_doublepointsneg(char *str, int num, int nb, int j)
{
	int l;

	l = 0;
	nb *= -1;
	if (num != 0 && num >= j)
		nb = nb - j;
	else if (num < 0)
	{
		num = j;
		nb = nb - j;
	}
	else if (num < j)
		nb = nb - num;
	while (l < j && l < num)
	{
		ft_putchar(str[l]);
		l++;
	}
	while (nb-- > 0)
		ft_putchar(' ');
}

void		ft_doublepointshelper(int *num, int *nb, int j)
{
	if (*num != 0 && *num >= j)
		*nb = *nb - j;
	else if (*num < 0)
	{
		*num = j;
		*nb = *nb - j;
	}
	else if (*num < j)
		*nb = *nb - *num;
}

void		format_specifier_shelp(va_list args, char **s, char c)
{
	if (format_specifier(*s) == '.')
	{
		if (format_specifier(*s) == '*')
			*s = ft_star((char *)*s, args);
		ft_doublepreci(args, *s);
	}
	else
		ft_printcom(args, *s, c);
}

void		ft_doublepointneghelper(char *s, int *nb, int i)
{
	if ((format_specifier(s) == 'x' || format_specifier(s) == 'X') && i < 0)
		*nb += 1;
	while (*nb > 0)
	{
		ft_putchar(' ');
		*nb -= 1;
	}
}
