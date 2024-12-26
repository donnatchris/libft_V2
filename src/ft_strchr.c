/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:28:47 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/26 08:20:31 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			len;
	unsigned char	uc;

	len = ft_strlen(s);
	uc = (unsigned char) c;
	i = 0;
	while (i <= len)
	{
		if ((unsigned char) s[i] == uc)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
