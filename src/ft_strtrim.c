/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:27:58 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/26 08:20:31 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_trim_len(const char *s, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s);
	if (len == 0)
		return (0);
	i = 0;
	while (ft_is_set(s[i], set))
		i++;
	if (i == len)
		return (0);
	j = 0;
	while (ft_is_set(s[len - j - 1], set) && (len - j) > 0)
		j++;
	return (len - i - j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	len = ft_trim_len(s1, set);
	trim = (char *) malloc((len + 1) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	i = 0;
	while (ft_is_set(s1[i], set))
		i++;
	j = 0;
	while (j < len)
	{
		trim[j] = s1[i + j];
		j++;
	}
	trim[j] = '\0';
	return (trim);
}
