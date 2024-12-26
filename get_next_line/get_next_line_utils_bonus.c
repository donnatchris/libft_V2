/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:37:31 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/25 15:30:30 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_has_newline(t_list *list)
{
	int		i;
	t_list	*current;

	if (!list)
		return (0);
	current = ft_lst_get_last(list);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_list(t_list *list)
{
	t_list	*current;
	t_list	*next;

	current = list;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

t_list	*ft_lst_get_last(t_list *list)
{
	t_list	*current;

	current = list;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	ft_clean_list(t_list	**p_list)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = (t_list *) malloc(sizeof(t_list));
	if (!(*p_list) || !clean_node)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*p_list);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = (char *) malloc((ft_strlen(last->content) - i) + 1);
	if (!(clean_node->content))
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	ft_free_list(*p_list);
	*p_list = clean_node;
}
