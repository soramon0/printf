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

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
	return (i);
}

int	ft_putnbr_base(int n, char *base, int baselen)
{
	long	num;
	int		i;

	num = n;
	i = 1;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		return (1 + ft_putnbr_base(num * -1, base, baselen));
	}
	if (num >= baselen)
	{
		i += ft_putnbr_base(num / baselen, base, baselen);
		ft_putchar_fd(base[num % baselen], 1);
		return (i);
	}
	else
	{
		ft_putchar_fd(base[num], 1);
		return (1);
	}
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

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	i;

	i = 1;
	if (n > 9)
	{
		i += ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
		return (i);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
		return (1);
	}
}

int	ft_puthex_fd(int n, int casing, int fd)
{
	return (ft_putnbr_fd(n, fd));
}
