# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 08:59:54 by christophed       #+#    #+#              #
#    Updated: 2024/12/26 09:05:10 by christophed      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################################################
## ARGUMENTS

NAME			= libft.a
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
INCLUDES		= -I includes/

#############################################################
## SOURCES

SRC_DIR			= src/

OBJ_DIR			= obj/

SRC_FILES		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
ft_lstmap_bonus.c ft_check_address_pf.c ft_printf.c ft_putchar_pf.c \
ft_puthexamaj_pf.c ft_puthexamin_pf.c ft_putint_pf.c ft_putstr_pf.c ft_putuint_pf.c

OBJ_FILES		= $(SRC_FILES:%.c=$(OBJ_DIR)%.o)

#############################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
