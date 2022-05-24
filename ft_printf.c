/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:26:35 by ntardy            #+#    #+#             */
/*   Updated: 2022/05/24 11:35:03 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_ptr(void *arg, const char *s, int i)
{
    if (arg == NULL)
        return (i += 2);
    if (s[i + 1] == 's')
        ft_putstr_fd((char *)arg, 1);
    if (s[i + 1] == 'p')
    {
        ft_putstr_fd("0x", 1);
        ft_putnbr_base((unsigned long)arg, "0123456789abcdef");
    }
    return (i += 2);
}

int ft_print_int(int arg, const char *s, int i)
{

    if (s[i + 1] == 'd' || s[i + 1] == 'i')
        ft_putnbr_fd(arg, 1);
    if (s[i + 1] == 'c')
        ft_putchar_fd(arg, 1);
    return (i += 2);
}

int ft_print_hex(long long hex, const char *s, int i)
{
    if (s[i + 1] == 'x')
        ft_putnbr_base(hex, "0123456789abcdef");
    if (s[i + 1] == 'X')
        ft_putnbr_base(hex, "0123456789ABCDEF");
    return (i += 2);
}

int ft_print_unsign(unsigned unsign, int i)
{
    ft_putnbr_base_unsign(unsign, "0123456789");
    return (i += 2);
}

int    ft_printf(const char *s, ...)
{
    va_list   argument;
    int       i;

    i = 0;
    va_start(argument, s);
    while (s[i])
    {
        if (s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 'd' || s[i + 1] == 'i'))
            i = ft_print_int(va_arg(argument, int), s, i);
        if (s[i] == '%' && (s[i + 1] == 's' || s[i + 1] == 'p'))
            i = ft_print_ptr(va_arg(argument, void *), s, i);
        if (s[i] == '%' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
            i = ft_print_hex(va_arg(argument, long long), s, i);
        if (s[i] == '%' && s[i + 1] == 'u')
            i = ft_print_unsign(va_arg(argument, unsigned), i);
        if (s[i] == '%' && s[i + 1] == '%')
        {
            ft_putchar_fd(s[i], 1);
            i += 2;
        }
        if (s[i])
            ft_putchar_fd(s[i++], 1);
    }
    return (0);
}

// int main(void)
// {
//     // // printf("%c ", '0' + 256);
//     // // ft_printf("%c ", '0' + 256); // ok
//     // // printf(" %c", '0' - 256);
//     // // ft_printf(" %c", '0' - 256); // ok
//     // // printf("\nprintf : ");
//     // printf(" %c %c %c ", '0', 0, '1');
//     // // printf("\nft_printf : ");
//     // ft_printf(" %c %c %c ", '0', 0, '1'); // ok
//     // // printf("\nprintf : ");
//     // printf(" %c %c %c ", ' ', ' ', ' ');
//     // // printf("\nft_printf : ");
//     // ft_printf(" %c %c %c ", ' ', ' ', ' '); // ok
//     // // printf("\nprintf : ");
//     // printf(" %c %c %c ", '1', '2', '3');
//     // // printf("\nft_printf : ");
//     // ft_printf(" %c %c %c ", '1', '2', '3'); // ok
//     // // printf("\nprintf : ");
//     // printf(" %c %c %c ", '2', '1', 0);
//     // // printf("\nft_printf : ");
//     // ft_printf(" %c %c %c ", '2', '1', 0); // ok
//     // // printf("\nprintf : ");
//     // printf(" %c %c %c ", 0, '1', '2');
//     // // printf("\nft_printf : ");
//     // ft_printf(" %c %c %c ", 0, '1', '2'); // ok
//     // printf("%s", "");
//     // ft_printf("%s", ""); // ok
//     // printf(" %s", "");
//     // ft_printf(" %s", ""); // ok
//     // printf("%s ", "");
//     // ft_printf("%s ", ""); // ok
//     char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
//     // printf(" %s %s ", "", "-");
//     // ft_printf(" %s %s ", "", "-");  // ok
// 	// printf(" %s %s ", " - ", "");
// 	// ft_printf(" %s %s ", " - ", "");  // ok
// 	// printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
// 	// ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
// 	printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
// 	// ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");

//     // if(argc == 393)
//     //     return (0);
//     // void *ptr = "bonjour";
//     // int age = ft_atoi(argv[2]);
//     // ft_printf("b%cnjour, %p je %x m'ap%%pelle %s et %u j'ai %i ans\n", 'o', ptr, 10, argv[1], -2147483647, age);
//     // printf("b%cnjour, %p je %x m'ap%%pelle %s et %u j'ai %i ans\n", 'o', ptr, 10, argv[1], -2147483647, age);
//     // printf("%lu\n", adressvoid);
//     // ft_printf("bonjour, je m'appelle %s et j'ai %d ans, j'habitais à %s et j'habite maintenant à %s\n", argv[1], age, argv[3], argv[4], argv[5]);
//     return (0);
// }
