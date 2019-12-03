/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublepointpointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 22:55:33 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 14:18:03 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_doublepointpointer(char *s, va_list args, int nb, int num)
{
	size_t	i;
	int		j;
	int		l;

	i = (size_t)va_arg(args, void*);
	j = ft_strlen(ft_hexap(i)) + 2;
	if (i == 0)
		j--;
	l = num;
	if (nb >= 0)
	{
		nb = nb - j;
		while (nb-- > 0)
			ft_putchar(' ');
		ft_printpo(s, l, i, num);
	}
	else
	{
		nb *= -1;
		nb = nb - j;
		ft_printpo(s, l, i, num);
		while (nb-- > 0)
			ft_putchar(' ');
	}
}

void		ft_doublepointcent(char *s, int nb, int num)
{
	int j;
	int l;
	int i;

	i = 1;
	j = 1;
	l = num;
	if (nb >= 0)
	{
		nb = nb - j;
		while (nb-- > 0)
			ft_putchar(' ');
		ft_putchar('%');
	}
	else
	{
		nb *= -1;
		nb = nb - j;
		num = 0;
		ft_printpo(s, l, i, num);
		while (nb-- > 0)
			ft_putchar(' ');
	}
}

void		ft_spaceinthelp(int *i, int *j, char *s, va_list args)
{
	if (format_specifier(s) == 'd' || format_specifier(s) == 'i')
	{
		*i = va_arg(args, int);
		*j = ft_strlen(ft_itoa(*i));
	}
	else
		*j = 1;
}

void		ft_pospoun(int **nb, int **num, int **j)
{
	if (**num == 0 || **num < **j)
	{
		**nb = **nb - **j;
		**num = **num - **j;
	}
	else if (**nb == 0 && **num > 0)
		**num = **num - (**j - 1);
	else if (**nb <= **num)
	{
		**nb = 0;
		**num = **num - **j;
	}
	else if (**nb > **num)
	{
		**nb = **nb - **num;
		**num = **num - **j;
	}
}

void		ft_zeropoun(unsigned int *k, int *nb, int *num, int *j)
{
	if (*k == 0)
	{
		*j += 1;
		if (*num < 0)
		{
			*num = 0;
			*nb = *nb - *j;
		}
		if (*num == 0 && *nb == 0)
			ft_putstr("");
		else
		{
			*nb = *nb - *num;
			*num = *num - *j;
		}
	}
	else
		ft_pospoun(&nb, &num, &j);
}
