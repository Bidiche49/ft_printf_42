/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:26:35 by ntardy            #+#    #+#             */
/*   Updated: 2022/05/23 01:14:35 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int    ft_printf(const char *s, ...)
{
    unsigned char   *adressvoid;
    char      *res;
    va_list   argument;
    int       i;
    int       j;

    i = 0;
    j = 0;
    va_start(argument, s);
    while (s[i])
    {
        if (s[i] == '%' && s[i + 1] == 'c')
        {
            ft_putchar_fd(va_arg(argument, int), 1);
            i += 2;
        }
        if (s[i] == '%' && s[i + 1] == 's')
        {
            ft_putstr_fd(va_arg(argument, char*), 1);
            i += 2;
        }
        if (s[i] == '%' && s[i + 1] == 'd')
        {
            ft_putnbr_fd(va_arg(argument, int), 1);
            i += 2;
        }
        // if (s[i] == '%' && s[i + 1] == 'p')
        // {
        //     printf("%lu\n", va_arg(argument, void*));
        //     i += 2;
        // }
        ft_putchar_fd(s[i++], 1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    if(argc == 393)
        return (0);
    // void *ptr = "bonjour";
    // char *bjr;
    int age = ft_atoi(argv[2]);
    // ft_printf("b%cnjour, je m'appelle %s et j'ai %d ans\n", 17839, argv[1], age);
    // printf("b%cnjour, %p je m'appelle %s et j'ai %d ans\n", 17839, ptr, argv[1], 21);
    ft_printf("bonjour, je m'appelle %s et j'ai %d ans, j'habitais à %s et j'habite maintenant à %s\n", argv[1], age, argv[3], argv[4], argv[5]);
    return (0);
}