/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:01:34 by ntardy            #+#    #+#             */
/*   Updated: 2022/05/24 21:06:12 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_ptr(void *arg, const char *s, int i)
{
    if (arg == NULL)
        return (i += 2);
    if (s[i] == 's')
    {
        ft_putstr_fd((char *)arg, 1);
        return (ft_strlen((char *)arg));
    }
    if (s[i] == 'p')
    {
        ft_putstr_fd("0x", 1);
        ft_putnbr_base((unsigned long)arg, "0123456789abcdef");
        return (14);
    }
    return (i += 2);
}
