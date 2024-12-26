/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexamaj_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:13:05 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/26 09:05:53 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_puthexamaj_pf(unsigned int n, int *count)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (n > 15)
		ft_puthexamaj_pf(n / 16, count);
	ft_putchar_pf(str[n % 16], count);
}
