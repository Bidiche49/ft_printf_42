/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:39:06 by ntardy            #+#    #+#             */
/*   Updated: 2022/05/24 20:39:24 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_hex(long long hex, const char *s, int i)
{
    if (s[i] == 'x')
    {
        ft_putnbr_base(hex, "0123456789abcdef");
        return (ft_size_number(hex, 16));
    }
    if (s[i] == 'X')
    {
        ft_putnbr_base(hex, "0123456789ABCDEF");
        return (ft_size_number(hex, 16));
    }
    return (0);
}
