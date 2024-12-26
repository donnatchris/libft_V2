/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:42:36 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/26 08:20:31 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_is_split(char c1, char c2)
{
	return (c1 == c2);
}

static int	ft_word_count(char const *s, char c)
{
	size_t	i;
	int		count;
	int		in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (s[i])
	{
		if (ft_is_split(s[i], c))
			in_word = 0;
		else
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
		}
		i++;
	}
	return (count);
}

static void	ft_free_split(char **str_split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(str_split[i]);
		i++;
	}
}

static char	**ft_allocate(char const *s, char c, int words, char **str_split)
{
	int		i;
	int		j;
	size_t	backup_i;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (ft_is_split(s[i], c))
			i++;
		backup_i = i;
		while (!ft_is_split(s[i], c) && s[i])
			i++;
		str_split[j] = ft_substr(s, (unsigned int) backup_i, i - backup_i);
		if (str_split[j] == NULL)
		{
			ft_free_split(str_split, j);
			return (NULL);
		}
		j++;
	}
	str_split[j] = NULL;
	return (str_split);
}

char	**ft_split(char const *s, char c)
{
	char	**str_split;
	int		words;

	if (s == NULL)
		return (NULL);
	words = ft_word_count(s, c);
	str_split = (char **) malloc((words + 1) * sizeof(char *));
	if (str_split == NULL)
		return (NULL);
	if (ft_allocate(s, c, words, str_split) == NULL)
	{
		free(str_split);
		return (NULL);
	}
	return (str_split);
}
