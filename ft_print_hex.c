/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:39:06 by ntardy            #+#    #+#             */
/*   Updated: 2022/05/26 10:23:10 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_basex(unsigned int nb, char *base, unsigned int i)
{
	const unsigned int	len_base = ft_strlen(base);

	if (nb >= len_base)
	{
		i += ft_putnbr_base_unsign(nb / len_base, base, i);
		ft_putchar_fd(base[nb % len_base], 1);
		return (++i);
	}
	else
	{
		ft_putchar_fd(base[nb], 1);
		return (++i);
	}
}
int ft_print_hex(unsigned int hex, char format)
{
    if (format == 'x')
        return (ft_putnbr_basex(hex, "0123456789abcdef", 0));
    else
        return (ft_putnbr_basex(hex, "0123456789ABCDEF", 0));
}
