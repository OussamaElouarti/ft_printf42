/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 03:18:37 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/11/29 03:18:44 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_print_number(int nb)
{
	int num;
	int length;

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

void			ft_putnbr(int nb)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	if (nb >= 0)
	{
		ft_print_number(nb);
	}
	else if (nb < 0 && nb != -2147483648)
	{
		ft_putchar('-');
		nb = -nb;
		ft_print_number(nb);
	}
}
