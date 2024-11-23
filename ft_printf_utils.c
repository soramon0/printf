/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:41:52 by klaayoun          #+#    #+#             */
/*   Updated: 2024/11/22 13:41:54 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		i;

	num = n;
	i = 1;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		return (1 + ft_putnbr_fd(num * -1, 1));
	}
	if (num > 9)
	{
		i += ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
		return (i);
	}
	else
	{
		ft_putchar_fd(num + '0', fd);
		return (1);
	}
}
