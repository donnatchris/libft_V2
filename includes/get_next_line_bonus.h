/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:38:25 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/26 09:29:07 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

// typedef struct s_list
// {
// 	char			*content;
// 	struct s_list	*next;
// }					t_list;

int		ft_has_newline(t_list *list);
void	ft_free_list(t_list *list);
t_list	*ft_lst_get_last(t_list *list);
void	ft_clean_list(t_list **list);
char	*get_next_line(int fd);
int		ft_read_to_list(int fd, t_list **list);
void	ft_add_to_list(t_list **list, char *buf, int n_read);
void	ft_extract_line(t_list *list, char **line);
void	ft_create_line(char **line, t_list *list);

#endif
