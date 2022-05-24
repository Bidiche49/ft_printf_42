/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:28:43 by ntardy            #+#    #+#             */
/*   Updated: 2022/05/23 22:46:57 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

int		ft_printf(const char *, ...);
void	ft_putnbr_base(long long nbr, char *base);
void	ft_putnbr_base_unsign(unsigned long long nb, char *base);

#endif
