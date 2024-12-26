/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:21:46 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/15 12:21:58 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar_pf(char c, int *count);
void	ft_putstr_pf(char *s, int *count);
void	ft_putint_pf(int n, int *count);
void	ft_putuint_pf(unsigned int n, int *count);
void	ft_puthexamin_pf(unsigned int n, int *count);
void	ft_puthexamaj_pf(unsigned int n, int *count);
void	ft_check_address_pf(void *address, int *count);

#endif
