/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:09:51 by jarumuga          #+#    #+#             */
/*   Updated: 2024/06/07 07:57:12 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* check the format specifier cspduxX% and calls the appropriate funct to print
each function return the number of characters printed */
static int	ft_handle_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_print_char((char)va_arg(args, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_int_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (format == '%')
		return (ft_print_char('%'));
	else
		return (0);
}

/* printed_chars is a counter to keep track of the total nb of char printed
va_list args to store the variable arguments
va_start to initialize args
check if the current char is %
move to the next char, which is the format specifier (cspduxX%)
call handle_format to print the corresponding args
if the current char is not %, it is a plain char to be printed */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0' || *(format + 1) == ' ')
			{
				va_end(args);
				return (-1);
			}
			format++;
			count += ft_handle_format(*format, args);
		}
		else
			count += ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (count);
}
/*
# include <stdio.h>

int	main(void)
{
	ft_printf("'test'");
	printf(" vs 'test' (plain)\n");

	ft_printf("'%c'", 'Q');
	printf(" vs '%c' (char)\n", 'Q');

	ft_printf("'%s'", "Bonjour");
	printf(" vs '%s' (string)\n", "Bonjour");

	int x = 42;
	int	*ptr = &x;
	ft_printf("'%p'", ptr);
	printf(" vs '%p' (pointer)\n", ptr);

	ft_printf("'%d'", 42);
	printf(" vs '%d' (decimal)\n", 42);

	ft_printf("'%i'", 42);
	printf(" vs '%i' (decimal)\n", 42);

	ft_printf("'%u'", 42);
	printf(" vs '%u' (unsigned decimal)\n", 42);

	ft_printf("'%x'", 42);
	printf(" vs '%x' (hexadecimal lower)\n", 42);

	ft_printf("'%X'", 42);
	printf(" vs '%X' (hexadecimal upper)\n", 42);

	ft_printf("'%%'");
	printf(" vs '%%' (literal pourcent)\n");

    int mine = ft_printf(NULL);
	int real = printf(NULL);
    printf("%d vs %d (return -1 if format NULL)\n", mine, real);

    return (0);
} */
