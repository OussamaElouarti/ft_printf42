/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:17:35 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 13:22:14 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_hexa(int nb)
{
	char			*str;
	int				i;
	int				c;
	unsigned int	b;

	i = 1;
	b = (unsigned int)nb;
	while (b /= 16)
		i++;
	b = (unsigned int)nb;
	str = malloc(i);
	while (b)
	{
		c = b % 16;
		b /= 16;
		if (c >= 10 && c < 16)
			str[i - 1] = c + 55;
		else
			str[i - 1] = c + '0';
		i--;
	}
	if (nb == 0)
		str[0] = '0';
	str[ft_strlen(str) + 1] = '\0';
	return (str);
}

void		starsecond_split(char **str, va_list args, char **str2)
{
	int nb;
	int	k;

	k = 1;
	nb = va_arg(args, int);
	while (ft_split(*str2, '*')[k] != NULL)
	{
		if (k >= 2)
			*str = ft_strjoin(*str, "*");
		*str = ft_strjoin(*str, ft_split(*str2, '*')[k]);
		k++;
	}
	*str2 = ft_strjoin(ft_split(*str2, '*')[0], ft_itoa(nb));
	*str2 = ft_strjoin(*str2, *str);
}

void		ft_printpouns(int l, unsigned int i, int num)
{
	while (num-- > 0)
		ft_putchar('0');
	if (l != 0 || i != 0)
		ft_putunsigned(i);
}

int			ft_escape(char *s)
{
	int i;

	i = 0;
	while (s[i] != 'd' && s[i] != 'i' && s[i] != 'x' && s[i] != 'X'
	&& s[i] != 'c' && s[i] != 's' && s[i] != 'p' && s[i] != 'u'
	&& s[i] != '\0' && s[i] != '%')
		i++;
	return (i);
}

void		format_specifier_sihelp(va_list args, char **s, char c)
{
	if (**s == '.')
	{
		*s += 1;
		format_specifierspoint(args, *s);
	}
	else if (**s == '*')
	{
		*s = ft_star(*s, args);
		format_specifiers(args, *s, c);
	}
}
