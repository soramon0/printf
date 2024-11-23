/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:41:52 by klaayoun          #+#    #+#             */
/*   Updated: 2024/11/22 13:41:54 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putchr_case(char c, int casing)
{
	if (c >= 'a' && c <= 'z' && casing)
		ft_putchr(c - 32);
	else
		ft_putchr(c);
}

static int	ft_putnbr_base(long long num, char *base, int baselen, int casing)
{
	int	i;

	i = 1;
	if (num == 0)
		return (ft_putstr("(nil)"));
	if (num < 0)
	{
		ft_putchr('-');
		return (1 + ft_putnbr_base(num * -1, base, baselen, casing));
	}
	if (num >= baselen)
	{
		i += ft_putnbr_base(num / baselen, base, baselen, casing);
		ft_putchr_case(base[num % baselen], casing);
		return (i);
	}
	else
	{
		ft_putchr_case(base[num], casing);
		return (1);
	}
}

int	ft_putnbr_hex(long long num, int casing)
{
	return (ft_putnbr_base(num, "0123456789abcdef", 16, casing));
}

int	ft_putnbr(int n)
{
	return (ft_putnbr_base(n, "0123456789", 10, 0));
}

int	ft_putunbr(unsigned int n)
{
	return (ft_putnbr_base(n, "0123456789", 10, 0));
}
