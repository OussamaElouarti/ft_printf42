/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 02:24:54 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 08:26:21 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_pointint(char *s, va_list args)
{
	int k;
	int i;
	int j;

	i = va_arg(args, int);
	j = ft_strlen(ft_itoa(i));
	k = ft_atoi(s);
	if (i < 0)
	{
		j--;
		ft_putchar('-');
		i *= -1;
	}
	k = k - j;
	if (k > 0)
	{
		while (k)
		{
			ft_putchar('0');
			k--;
		}
	}
	ft_putunsigned(i);
}

void		ft_pointstring(char *s, va_list args)
{
	int		k;
	int		i;
	char	*str;
	int		j;

	i = 0;
	if (!(str = va_arg(args, char*)))
		str = ft_strdup("(null)");
	k = ft_atoi(s);
	j = ft_strlen(str);
	if (k < 0)
		k = j;
	while (i < k && i < j)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		ft_pointunint(char *s, va_list args)
{
	int				k;
	unsigned int	i;
	int				j;
	unsigned int	nb;

	i = va_arg(args, unsigned int);
	j = 0;
	nb = i;
	while (i)
	{
		i /= 10;
		j++;
	}
	if (nb == 0)
		j++;
	k = ft_atoi(s);
	k = k - j;
	if (k > 0)
	{
		while (k--)
			ft_putchar('0');
	}
	ft_putunsigned(nb);
}
