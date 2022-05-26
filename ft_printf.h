/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:28:43 by ntardy            #+#    #+#             */
/*   Updated: 2022/05/26 10:25:21 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

int		ft_printf(const char *, ...);
int		ft_putchar_pf(int c);
int		ft_putstr_pf(char *s);
int		ft_print_unsign(unsigned unsign);
int		ft_print_hex(unsigned int hex, char format);
int		ft_print_ptr(void *arg, char format);
int		ft_print_int(int arg, char format);
int		ft_putnbr_base(long long nbr, char *base);
int		ft_putnbr_base_unsign(unsigned long long nb, char *base, unsigned int i);

#endif
