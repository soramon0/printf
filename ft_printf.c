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
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
	else
		ft_putchar_fd(num + '0', fd);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == '%')
			{
				write(1, &format[i + 1], 1);
				i += 2;
			}
			if (format[i + 1] == 'd')
			{
				int d = (int)va_arg(args, int);
				ft_putnbr_fd(d, 1);
				i += 2;
			}
		}
		write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}

int main()
{
	size_t val = 5;
	char *format = "Hello %zu\n";
	int bytes = ft_printf(format, val);
	printf("Wrote %d\n", bytes);
	bytes = printf(format, val);
	printf("Wrote %d\n", bytes);
	return (0);
}
