/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:51:12 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/26 08:20:31 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new;
	size_t	i;
	size_t	total_size;

	total_size = nmemb * size;
	if (total_size != nmemb * size)
		return (NULL);
	new = (char *) malloc(total_size);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		new[i] = 0;
		i++;
	}
	return ((void *) new);
}
