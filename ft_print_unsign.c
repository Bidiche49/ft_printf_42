/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:40:06 by ntardy            #+#    #+#             */
/*   Updated: 2022/05/24 20:40:17 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_unsign(unsigned unsign, int i)
{
    ft_putnbr_base_unsign(unsign, "0123456789");
    return (ft_size_number(unsign, 10));
}
