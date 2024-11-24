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

#include "ft_printf.h"

static int	ft_putnbr_base(long long num, char *base, int baselen, int nillable)
{
	int	i;

	i = 1;
	if (num < 0)
		return (ft_putchr('-') + ft_putnbr_base(-num, base, baselen, nillable));
	if (num >= baselen)
	{
		i += ft_putnbr_base(num / baselen, base, baselen, nillable);
		return (i + ft_putchr(base[num % baselen]));
	}
	else
		return (ft_putchr(base[num]));
}

int	ft_putnbr_hex(unsigned int num, int uppercase)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;
	if (uppercase == 1)
		hex = "0123456789ABCDEF";
	if (num >= 16)
	{
		i += ft_putnbr_hex(num / 16, uppercase);
		return (i + ft_putchr(hex[num % 16]));
	}
	else
		return (ft_putchr(hex[num]));
}

int	ft_putptr(void *num)
{
	if (num == NULL)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putnbr_hex((unsigned long)num, 0));
}

int	ft_putnbr(int n)
{
	int		i;
	long	num;

	i = 1;
	num = n;
	if (num < 0)
		return (ft_putchr('-') + ft_putnbr(-num));
	if (num >= 10)
	{
		i += ft_putnbr(num / 10);
		return (i + ft_putchr(num % 10 + '0'));
	}
	else
		return (ft_putchr(num + '0'));
}

int	ft_putunbr(unsigned int n)
{
	return (ft_putnbr(n));
}
