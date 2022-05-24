/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:41:03 by ntardy            #+#    #+#             */
/*   Updated: 2022/05/23 23:05:59 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_base(char *base)
{
	int i;
	int j;

	i = -1;
	while (base[++i])
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32 || base[i] >= 127)
			return (0);
		while (base[j])
			if (base[i] == base[j++])
				return (0);
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base_unsign(unsigned long long nb, char *base)
{
	const unsigned int	len_base = ft_strlen(base);

	if (nb > len_base - 1)
	{
		ft_putnbr_base_unsign(nb / len_base, base);
		ft_putchar_fd(base[nb % len_base], 1);
	}
	else
		ft_putchar_fd(base[nb], 1);
}

void	ft_putnbr_base(long long nb, char *base)
{
	if (!ft_check_base(base))
		return ;
	if (nb == 0)
		return (ft_putchar_fd(base[0], 1));
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		return (ft_putnbr_base_unsign((nb * -1), base));
	}
	ft_putnbr_base_unsign(nb, base);
}
