/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:28:43 by ntardy            #+#    #+#             */
/*   Updated: 2022/05/24 20:56:19 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

int		ft_printf(const char *, ...);
int		ft_putchar_pf(int c);
int		ft_print_unsign(unsigned unsign, int i);
int		ft_print_hex(long long hex, const char *s, int i);
int		ft_print_ptr(void *arg, const char *s, int i);
int		ft_print_int(int arg, const char *s, int i);
int		ft_size_number(long long nb, int len_base);
void	ft_putnbr_base(long long nbr, char *base);
void	ft_putnbr_base_unsign(unsigned long long nb, char *base);

#endif
