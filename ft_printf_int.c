/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:38:21 by ntardy            #+#    #+#             */
/*   Updated: 2022/05/24 20:38:42 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_int(int arg, const char *s, int i)
{

    if (s[i] == 'd' || s[i] == 'i')
    {
        ft_putnbr_pf(arg);
        return (ft_size_number(arg, 10));
    }
    if (s[i] == 'c')
        return (ft_putchar_pf(arg));
    return (0);
}
