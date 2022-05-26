/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:38:21 by ntardy            #+#    #+#             */
/*   Updated: 2022/05/26 10:22:49 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_int(int arg, char format)
{

    if (format == 'd' || format == 'i')
    {
        if (arg < 0)
            return(ft_putnbr_base((long long)arg, "0123456789") + 1);
        return(ft_putnbr_base((long long)arg, "0123456789"));
    }
    else
        return (ft_putchar_pf(arg));
}
