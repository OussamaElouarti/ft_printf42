/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 01:52:19 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/12/01 13:51:43 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *str, char c);
char		*ft_itoa(int n);
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_putnbr(int nb);
char		*ft_hexa(int b);
char		*ft_hexaa(int b);
void		ft_putunsigned(unsigned int nb);
void		ft_spacestring(char *s, va_list args, char c);
void		ft_spacehexa(char *s, va_list args, char c);
void		ft_spacepointer(char *s, va_list args, char c);
void		ft_spaceint(char *s, va_list args, char c);
void		ft_spacechar(char *s, va_list args, char c);
char		format_specifier(char *s);
void		format_specifiers(va_list args, char *s, char c);
int			ft_escape(char *s);
void		ft_printcom(va_list args, char *s, char c);
void		ft_printmoins(va_list args, char *s, char c);
void		ft_moinsstring(char *s, va_list args, char c);
void		ft_moinshexa(char *s, va_list args, char c);
void		ft_moinspointer(char *s, va_list args, char c);
void		ft_moinsint(char *s, va_list args, char c);
void		ft_moinschar(char *s, va_list args, char c);
void		format_specifierspoint(va_list args, char *s);
void		ft_pointint(char *s, va_list args);
void		ft_printpoint(va_list args, char *s);
void		ft_pointstring(char *s, va_list args);
void		ft_doublepreci(va_list args, char *s);
void		ft_doublepointint(char *s, va_list args, int nb, int num);
void		ft_negatifdoublepoint(char *s, int i, int nb, int num);
void		ft_negpoint(int *i, int *nb, int *num, int *j);
void		ft_pospoint(int *i, int *nb, int *num, int *j);
void		ft_printpo(char *s, int l, int i, int num);
void		ft_zeropoin(int *i, int *nb, int *num, int *j);
void		ft_doublepointneg(char*s, int i, int num, int nb);
void		ft_doublepoints(va_list args, int i, int j);
void		ft_doublepointsneg(char *s, int num, int nb, int j);
void		ft_moinsuns(char *s, va_list args, char c);
void		ft_spaceuns(char *s, va_list args, char c);
void		ft_pospoun(int **nb, int **num, int **j);
void		ft_zeropoun(unsigned int *k, int *nb, int *num, int *j);
void		ft_doublepointun(va_list args, int nb, int num);
void		ft_printpouns(int l, unsigned int i, int num);
void		ft_pointunint(char *s, va_list args);
void		ft_doublepounneg(unsigned int i, int num, int nb);
int			ft_printf(const char *s, ...);
char		*ft_hexap(size_t nb);
char		*ft_star(char *s, va_list args);
void		ft_doublepointpointer(char *s, va_list args, int nb, int num);
void		ft_doublepointcent(char *s, int nb, int num);
void		ft_change(char *s, char **str, char **str2);
void		starfirst_split(char *s, va_list args, char **str2, int *j);
void		starsecond_split(char **str, va_list args, char **str2);
void		ft_spaceinthelp(int *i, int *j, char *s, va_list args);
void		format_specifier_shelp(va_list args, char **s, char c);
void		format_specifier_thelp(va_list args, char **s, char c);
void		format_specifier_fhelp(va_list args, char **s, int i, char c);
void		format_specifier_fohelp(va_list args, char *s);
void		format_specifier_sihelp(va_list args, char **s, char c);
void		format_specifierspoint_helper(va_list args, char *s, int i);
int			double_precihelper(char *s, int *k, int *j, va_list args);
void		ft_doublepointhelper(char *s, int *j, int i);
void		ft_do_fhelper(va_list args, char *s, int i);
void		ft_do_shelper(va_list args, char *s, int i);
void		ft_doublepointshelper(int *num, int *nb, int j);
void		ft_doublepointneghelper(char *s, int *nb, int i);
#endif
