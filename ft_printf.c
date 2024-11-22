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

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	va_end(args);
	return (0);
}

int main()
{
	int val = 5;
	int bytes = ft_printf("Hello %d\n", val);
	printf("Wrote %d\n", bytes);
	bytes = printf("Hello %d\n", val);
	printf("Wrote %d\n", bytes);
	return (0);
}
