/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:41:52 by klaayoun          #+#    #+#             */
/*   Updated: 2024/11/22 13:41:54 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static int	process(va_list args, char **format, char specifier)
{
	int		bytes;
	void	*data;

	bytes = 0;
	if (specifier == '%' && ++bytes)
		ft_putchar('%');
	else if (specifier == 'd' || specifier == 'i')
		bytes = ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		bytes = ft_putunbr(va_arg(args, int));
	else if (specifier == 'c' && ++bytes)
		ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		bytes = ft_putstr(va_arg(args, char *));
	else if (specifier == 'x' || specifier == 'X')
		bytes = ft_putnbr_hex(va_arg(args, int), specifier == 'X');
	else if (specifier == 'p')
	{
		data = (int *)va_arg(args, int *);
		if (data != NULL)
			bytes += ft_putstr("0x");
		bytes = ft_putnbr_hex((long long)data, 0);
	}
	*format += 2;
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes;
	char	*specifier;
	char	*s;

	bytes = 0;
	s = (char *)format;
	va_start(args, format);
	while (*s)
	{
		if (*s != '%' && ++bytes)
		{
			write(1, s++, 1);
			continue ;
		}
		specifier = ft_strchr("cspdiuxX%", *(s + 1));
		if (!specifier && ++bytes && ++s)
			write(1, "%", 1);
		else
			bytes += process(args, &s, *specifier);
	}
	va_end(args);
	return (bytes);
}

int	main(void)
{
	void	*val;
	char	*format;
	size_t	bytes;

	val = (int *)-1337;
	format = "Value is '%u'\n";
	bytes = ft_printf(format, val);
	printf("Wrote %zu bytes\n", bytes);
	printf("------------------\n");
	bytes = printf(format, val);
	printf("Wrote %zu bytes\n", bytes);
	return (0);
}
