/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:08 by klaayoun          #+#    #+#             */
/*   Updated: 2024/11/22 13:32:10 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "stdarg.h"
# include <unistd.h>

int		ft_printf(const char *, ...);
void	ft_putchar_fd(char c, int fd);
int ft_putnbr_fd(int n, int fd);
char	*ft_strchr(const char *s, int c);

#endif
