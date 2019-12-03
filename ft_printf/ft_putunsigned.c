/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:45:28 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 13:21:42 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putunsigned(unsigned int nb)
{
	unsigned int	num;
	int				length;

	length = 1;
	num = nb;
	while ((num /= 10) > 0)
		length *= 10;
	num = nb;
	while (length)
	{
		ft_putchar((char)((nb / length)) + '0');
		nb %= length;
		length /= 10;
	}
}

void		ft_moinsuns(char *s, va_list args, char c)
{
	int				k;
	unsigned int	i;
	int				j;
	unsigned int	nb;

	j = 0;
	i = va_arg(args, unsigned int);
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
	ft_putunsigned(nb);
	if (c == 'd')
		k = 0;
	if (k > 0)
		while (k--)
			ft_putchar(c);
}

void		ft_spaceuns(char *s, va_list args, char c)
{
	int				k;
	unsigned int	i;
	int				j;
	unsigned int	nb;

	j = 0;
	i = va_arg(args, unsigned int);
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
		while (k--)
			ft_putchar(c);
	ft_putunsigned(nb);
}

void		ft_doublepointun(va_list args, int nb, int num)
{
	unsigned int	i;
	int				j;
	int				l;
	unsigned int	k;

	j = 0;
	i = va_arg(args, unsigned int);
	k = i;
	while (i)
	{
		i /= 10;
		j++;
	}
	l = num;
	if (nb >= 0)
	{
		ft_zeropoun(&k, &nb, &num, &j);
		while (nb-- > 0)
			ft_putchar(' ');
		ft_printpouns(l, k, num);
	}
	else
		ft_doublepounneg(k, num, nb);
}

void		ft_doublepounneg(unsigned int i, int num, int nb)
{
	int				j;
	int				l;
	unsigned int	k;

	k = i;
	j = 0;
	while (i)
	{
		i /= 10;
		j++;
	}
	l = num;
	nb *= -1;
	ft_zeropoun(&k, &nb, &num, &j);
	ft_printpouns(l, k, num);
	while (nb-- > 0)
		ft_putchar(' ');
}
