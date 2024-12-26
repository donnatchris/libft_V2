/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:29:30 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/26 08:20:31 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_nbr_len(int n, int sign)
{
	size_t	nbr_len;

	nbr_len = 1;
	while (n > 9)
	{
		n = n / 10;
		nbr_len++;
	}
	if (sign == 1)
		nbr_len++;
	return (nbr_len);
}

static char	*ft_nbr(char *nbr, int n, int sign, size_t nbr_len)
{
	size_t	i;

	i = nbr_len;
	nbr[i] = '\0';
	i--;
	while (n > 9)
	{
		nbr[i] = (char)(n % 10 + '0');
		n = n / 10;
		i--;
	}
	nbr[i] = (char)(n + '0');
	if (sign == 1)
		nbr[0] = '-';
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	size_t	nbr_len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	nbr_len = ft_nbr_len(n, sign);
	nbr = (char *) malloc((nbr_len + 1) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
	nbr = ft_nbr(nbr, n, sign, nbr_len);
	return (nbr);
}
