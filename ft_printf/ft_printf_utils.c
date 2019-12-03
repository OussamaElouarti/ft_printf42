/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:28:25 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 13:25:15 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printcom(va_list args, char *s, char c)
{
	if (format_specifier(s) == 'd' || format_specifier(s) == 'i'
			|| format_specifier(s) == '%')
		ft_spaceint(s, args, c);
	else if (format_specifier(s) == 'c')
		ft_spacechar(s, args, c);
	else if (format_specifier(s) == 's')
		ft_spacestring(s, args, c);
	else if (format_specifier(s) == 'p')
		ft_spacepointer(s, args, c);
	else if (format_specifier(s) == 'x' || format_specifier(s) == 'X')
		ft_spacehexa(s, args, c);
	else if (format_specifier(s) == 'u')
		ft_spaceuns(s, args, c);
}

void		ft_printmoins(va_list args, char *s, char c)
{
	if (format_specifier(s) == 'd' || format_specifier(s) == 'i'
			|| format_specifier(s) == '%')
		ft_moinsint(s, args, c);
	else if (format_specifier(s) == 'c')
		ft_moinschar(s, args, c);
	else if (format_specifier(s) == 's')
		ft_moinsstring(s, args, c);
	else if (format_specifier(s) == 'p')
		ft_moinspointer(s, args, c);
	else if (format_specifier(s) == 'x' || format_specifier(s) == 'X')
		ft_moinshexa(s, args, c);
	else if (format_specifier(s) == 'u')
		ft_moinsuns(s, args, c);
}

char		format_specifier(char *s)
{
	while (*s != '\0')
	{
		if (*s == 'd' || *s == 'i')
			return ('d');
		else if (*s == 's')
			return ('s');
		else if (*s == 'c')
			return ('c');
		else if (*s == 'X')
			return ('X');
		else if (*s == 'x')
			return ('x');
		else if (*s == 'p')
			return ('p');
		else if (*s == 'u')
			return ('u');
		else if (*s == '.')
			return ('.');
		else if (*s == '*')
			return ('*');
		else if (*s == '%')
			return ('%');
		s++;
	}
	return (0);
}

void		format_specifiers(va_list args, char *s, char c)
{
	int i;

	i = 0;
	if (*s == '-')
	{
		i = -1;
		s++;
	}
	if (*s == 'd' || *s == 'i' || *s == 's' || *s == 'c' || *s == 'x'
	|| *s == 'p' || *s == 'X' || *s == 'u')
		format_specifier_fohelp(args, s);
	else if (*s > '0' && *s <= '9' && i != -1)
		format_specifier_shelp(args, &s, c);
	else if (*s > '0' && *s <= '9' && i == -1)
		format_specifier_thelp(args, &s, c);
	else if (*s == '0')
		format_specifier_fhelp(args, &s, i, c);
	else if (*s == '.' || *s == '*')
		format_specifier_sihelp(args, &s, c);
	else
		format_specifiers(args, s, c);
}
