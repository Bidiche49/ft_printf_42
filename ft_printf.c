/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:26:35 by ntardy            #+#    #+#             */
/*   Updated: 2022/05/26 10:18:46 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_isformat(char c)
{
    int         i;
    const char  *format = "cdispxXu%";

    i = -1;
    while (format[++i])
        if (format[i] == c)
            return (1);
    return (0);
}

static int ft_forest(const char *s, int i, va_list argument)
{
    if ((s[i] == 'c' || s[i] == 'd' || s[i] == 'i'))
        return (ft_print_int(va_arg(argument, int), s[i]));
    if ((s[i] == 's' || s[i] == 'p'))
        return (ft_print_ptr(va_arg(argument, void *), s[i]));
    if ((s[i] == 'x' || s[i] == 'X'))
        return (ft_print_hex(va_arg(argument, unsigned int), s[i]));
    if (s[i] == 'u')
        return (ft_print_unsign(va_arg(argument, unsigned)));
    if (s[i] == '%')
        return (ft_putchar_pf('%'));
    return (0);
}

int    ft_printf(const char *s, ...)
{
    va_list     argument;
    int         i;
    int         ret;

    i = 0;
    ret = 0;
    va_start(argument, s);
    while (s[i])
    {
        if (s[i] == '%' && (ft_isformat(s[i  + 1])))
        {
            ret += ft_forest(s, i + 1, argument);
            i += 2;
        }
        if (s[i] != '\0' && s[i] != '%')
            ret += ft_putchar_pf(s[i++]);
    }
    return (ret);
}

// int main(void)
// {
//     // void * ptr;
//     // ptr = "totiyguvugvg";
//     printf("ret = %d\n", printf(" %p ", 5647));
//     printf("ret = %d\n", ft_printf(" %p ", 5647));
// 	printf("ret = %d\n", printf(" %x ", -2147483648));
// 	printf("ret = %d\n", printf(" %x ", 922337203685477LL));
// 	// ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
//     // printf("\n");
//     // printf("%d\n", printf("%p", 17));

// }
// //====================%c====================
//     // ft_printf("%c", '0'); //ok
// 	// ft_printf(" %c ", '0'); //ok
// 	// ft_printf(" %c", '0' - 256); //ok
//     // ft_printf("%c ", '0' + 256); //ok
//     // ft_printf(" %c %c %c ", '0', 0, '1');
//     // ft_printf(" %c %c %c ", ' ', ' ', ' ');
//     // ft_printf(" %c %c %c ", '1', '2', '3');
//     // ft_printf(" %c %c %c ", '2', '1', 0);
//     // ft_printf(" %c %c %c ", 0, '1', '2');
// //==========================================
// //    // if(argc == 393)
// //     //     return (0);
// //     // void *ptr = "bonjour";
// //     // int age = ft_atoi(argv[2]);
// //     // ft_printf("b%cnjour, %p je %x m'ap%%pelle %s et %u j'ai %i ans\n", 'o', ptr, 10, argv[1], -2147483647, age);
// //     // printf("b%cnjour, %p je %x m'ap%%pelle %s et %u j'ai %i ans\n", 'o', ptr, 10, argv[1], -2147483647, age);
// //     // printf("%lu\n", adressvoid);
// //     // ft_printf("bonjour, je m'appelle %s et j'ai %d ans, j'habitais à %s et j'habite maintenant à %s\n", argv[1], age, argv[3], argv[4], argv[5]);
// //     return (0);
// // }
