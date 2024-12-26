/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:09:26 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/26 09:42:06 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_switch_pf(char format, va_list *ap, int *count)
{
	if (format == 'c')
		ft_putchar_pf((char) va_arg(*ap, int), count);
	else if (format == 's')
		ft_putstr_pf(va_arg(*ap, char *), count);
	else if (format == 'p')
		ft_check_address_pf(va_arg(*ap, void *), count);
	else if (format == 'd')
		ft_putint_pf(va_arg(*ap, int), count);
	else if (format == 'i')
		ft_putint_pf(va_arg(*ap, int), count);
	else if (format == 'u')
		ft_putuint_pf(va_arg(*ap, unsigned int), count);
	else if (format == 'x')
		ft_puthexamin_pf(va_arg(*ap, unsigned int), count);
	else if (format == 'X')
		ft_puthexamaj_pf(va_arg(*ap, unsigned int), count);
	else if (format == '%')
		ft_putchar_pf('%', count);
}

static int	ft_is_charset_pf(char c)
{
	char	*charset;

	charset = "cspdiuxX%";
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	ft_metchar_pf(const char *str, size_t i, va_list *ap, int *count)
{
	i++;
	if (ft_is_charset_pf(str[i]) == 0)
	{
		i--;
		ft_putchar_pf(str[i], count);
		return (i);
	}
	else
	{
		ft_switch_pf(str[i], ap, count);
		return (i);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	int		count;

	count = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = ft_metchar_pf(str, i, &ap, &count);
		}
		else
			ft_putchar_pf(str[i], &count);
		i++;
	}
	va_end(ap);
	return (count);
}
