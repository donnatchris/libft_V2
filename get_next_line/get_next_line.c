/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:37:15 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/25 15:30:06 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_add_to_list(t_list **p_list, char *buff, int readed)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = (char *) malloc(readed + 1);
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buff[i] && i < readed)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*p_list == 0)
	{
		*p_list = new_node;
		return ;
	}
	last = ft_lst_get_last(*p_list);
	last->next = new_node;
}

int	ft_read_to_list(int fd, t_list **p_list)
{
	char	*buff;
	int		readed;

	readed = 1;
	while (ft_has_newline(*p_list) == 0 && readed != 0)
	{
		buff = (char *) malloc(BUFFER_SIZE + 1);
		if (buff == 0)
			return (readed);
		readed = (int) read(fd, buff, BUFFER_SIZE);
		if ((*p_list == 0 && readed == 0) || readed == -1)
		{
			free (buff);
			return (readed);
		}
		buff[readed] = '\0';
		ft_add_to_list(p_list, buff, readed);
		free (buff);
	}
	return (readed);
}

void	ft_generate_line(char **p_line, t_list *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		list = list->next;
	}
	*p_line = (char *) malloc(len + 1);
}

void	ft_extract_line(t_list *list, char **p_line)
{
	int	i;
	int	j;

	if (!list)
		return ;
	ft_generate_line(p_line, list);
	if (*p_line == 0)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				(*p_line)[j++] = list->content[i];
				break ;
			}
			(*p_line)[j++] = list->content[i++];
		}
		list = list->next;
	}
	(*p_line)[j] = '\0';
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;
	t_list			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_read_to_list(fd, &list) == -1)
	{
		while (list)
		{
			temp = list->next;
			free(list->content);
			free(list);
			list = temp;
		}
	}
	if (!list)
		return (NULL);
	ft_extract_line(list, &line);
	ft_clean_list(&list);
	if (line[0] == '\0')
		return (ft_free_list(list), list = NULL, free(line), NULL);
	return (line);
}
/*
#include <stdio.h>
int main(void)
{
	int	fd;
	char	*line;

	fd = open("test", O_RDONLY);
	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
