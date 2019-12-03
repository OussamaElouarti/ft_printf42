/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:30:02 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 13:18:25 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_hexaa(int nb)
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
			str[i - 1] = c + 87;
		else
			str[i - 1] = c + '0';
		i--;
	}
	if (nb == 0)
		str[0] = '0';
	str[ft_strlen(str) + 1] = '\0';
	return (str);
}

char		*ft_hexap(size_t nb)
{
	char			*str;
	int				i;
	int				c;
	size_t			b;

	i = 1;
	b = nb;
	while (b /= 16)
		i++;
	b = nb;
	str = malloc(i);
	while (b)
	{
		c = b % 16;
		b /= 16;
		if (c >= 10 && c < 16)
			str[i - 1] = c + 87;
		else
			str[i - 1] = c + '0';
		i--;
	}
	if (nb == 0)
		str[0] = '0';
	str[ft_strlen(str) + 1] = '\0';
	return (str);
}

char		*ft_star(char *s, va_list args)
{
	char	*str;
	char	*str2;
	int		j;

	j = 0;
	ft_change(s, &str, &str2);
	while (*s != '\0')
	{
		if (*s == '*')
		{
			if (j == 0)
				starfirst_split(s, args, &str2, &j);
			else
				starsecond_split(&str, args, &str2);
		}
		else if (*s == 'd' || *s == 's' || *s == 'p' || *s == 'u' || *s == 'i'
				|| *s == 'c' || *s == 'x' || *s == 'X')
			return (str2);
		s++;
	}
	return (str2);
}

void		ft_change(char *s, char **str, char **str2)
{
	if (*s == '-')
		*str2 = ft_strdup("-");
	else if (*s == '0')
		*str2 = ft_strdup("0");
	else
		*str2 = ft_strdup("");
	*str = ft_strdup("");
}

void		starfirst_split(char *s, va_list args, char **str2, int *j)
{
	int nb;

	nb = va_arg(args, int);
	*str2 = ft_strdup(ft_strjoin((const char*)*str2, (const char*)ft_itoa(nb)));
	*str2 = ft_strjoin((const char*)*str2, (const char*)s + 1);
	*j += 1;
}
