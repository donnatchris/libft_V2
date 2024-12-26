/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:45:58 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/26 09:20:06 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*******************************************************************************
PRINT AND WRITE FUNCTIONS
******************************************************************************/

void	ft_putchar_fd(char c, int fd);
//	Writes the character c to the file descriptor fd.

void	ft_putstr_fd(char *s, int fd);
//	Writes the string s to the file descriptor fd.

void	ft_putendl_fd(char *s, int fd);
//	Writes the string s followed by '\n' to the file descriptor fd.

void	ft_putnbr_fd(int n, int fd);
//	Writes the integer n to the fils descriptor fd.

/*******************************************************************************
CHARACTER MANIPULATION FUNCTIONS
******************************************************************************/

int		ft_isalpha(int c);
//	Tests if c character is a letter (the value of the argument must be
//		representable as an unsigned char or the value of EOF),
//		which is any character between 65 and 90 or 97 and 122.
//	-> Returns zero if the character tests false
//		and returns non-zero if the character tests true.

int		ft_isdigit(int c);
//	Tests for a decimal digit character (the value of the argument must be
//		representable as an unsigned char or the value of EOF),
//		which is any charactyer between 48 and 57.
//	-> Returns 0 if the character tests false, or 1 if the character tests true.

int		ft_isalnum(int c);
//	Tests for any character for which ft_isalpha() or ft_isdigit() is true (the
//		value of the argument must be representable as an unsigned char or the
//		value of EOF),
//		which is any character between 65 and 90, 97 and 122, 48 and 57.
//	-> Returns 0 if the character tests false, or 1 if the character tests true.

int		ft_isascii(int c);
//	Tests for an ASCII character,
//		which is any character between 0 and 127.
//	-> Returns 0 if the character tests false, or 1 if the character tests true.

int		ft_isprint(int c);
//	Tests for any printing character, including space (‘ ’) (the value of the
//		argument must be representable as an unsigned char or the value of EOF),
//		which is any character between 32 and 126.
//	-> Returns 0 if the character tests false or 1 if the character tests true.

int		ft_toupper(int c);
//	Converts a lower-case letter to the corresponding upper-case letter (the
//		argument must be representable as an unsigned char or the value of EOF).
//	-> If the argument is a lower-case letter, the function returns the
//	corresponding upper-case letter if there is one,
//	otherwise, the argument is returned unchanged.

int		ft_tolower(int c);
//	Converts an upper-case letter to the corresponding lower-case letter (the
//		argument must be representable as an unsigned char or the value of EOF).
//	-> If the argument is an upper-case letter, the function returns the
//		corresponding lower-case letter if there is one;
//		otherwise, the argument is returned unchanged.

/*******************************************************************************
STRING MANIPULATION FUNCTIONS
******************************************************************************/

size_t	ft_strlen(const char *s);
//	Computes the length of the string s.
//	-> Returns the number of characters that precede the terminating NULL
//		character.

int		ft_strncmp(const char *s1, const char *s2, size_t n);
//	Like ft_strcmp() but ft_strncmp() compares not more than n characters.
//	-> Return an integer greater than, equal to, or less than 0, according as
//		the string s1 is greater than, equal to, or less than the string s2.

int		ft_atoi(const char *nptr);
//	Converts the initial portion of the string pointed to by nptr to int
//		representation, ignoring leading spaces and stopping conversion at
//		first non-numeric character.
//	-> Returns the integer represented by the initial numeric characters of
//		the string nptr.

size_t	ft_strlcat(char *dst, const char *src, size_t size);
//	Appends string src to the end of string dst
//		(it will append at most size - strlen(dst) - 1 characters),
//		it will then null-terminate,
//		unless size is 0 or the original dst string was longer than dstsize.
//		!! If the src and dst strings overlap, the behavior is undefined.
//	-> Returns the total length of the string it tried to create
//		(that means the initial length of dst plus the length of src).
//	!! If the return value is >= dstsize, the output string has been truncated.

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
//	Copies up to size - 1 characters from the NUL-terminated string src to dst,
//		NUL-terminating the result.
//		It takes the full size of the buffer (not just the length) and
//		guarantee to NUL-terminate the result (only if size is larger than 0).
//	-> Returns the lenght of src (makes truncation detection easier).

char	*ft_strnstr(const char *big, const char *little, size_t len);
//	Locates the first occurrence of the null-terminated string little in the
//		string big, where not more than len characters are searched
//		(characters that appear after a ‘\0’ character are not searched).
//	-> If little is an empty string, big is returned,
//		if little occurs nowhere in big, NULL is returned,
//		otherwise a pointer to the first character of the first occurrence
//		of little is returned.

char	*ft_strchr(const char *s, int c);
//	Locates the first occurrence of c (converted to a char) in the string
//		pointed to by s (the terminating null character is considered
//		to be part of the string, therefore if c is ‘\0’,
//		the functions locate the terminating ‘\0’).
//	-> Returns a pointer to the located character,
//		or NULL if the character does not appear in the string.

char	*ft_strrchr(const char *s, int c);
//	Like ft_strchr() except it locates the last occurrence of c.
//	-> Returns a pointer to the located character,
//		or NULL if the character does not appear in the string.

char	*ft_strdup(const char *s);
//	Allocates sufficient memory for a copy of the string s ande does the copy.
//	-> Returns a pointer to the copy (the pointer may subsequently be used as
//		an argument to the function free())
//		(if insufficient memory is available, NULL is returned).

char	*ft_substr(char const *s, unsigned int start, size_t len);
//	Allocates with malloc() and copies a substring of string s
//		(the substring begins at index start and has a lenght of len).
//	!! If start and len do not specify a valid substring, behavior is undefined.
//	-> Returns the newly created copy, or NULL if allocation fails.

char	*ft_strjoin(char const *s1, char const *s2);
//	Allocates with malloc() and creates a new string resulting from the
//		concatenation of s1 (prefix string) and s2 (sufix string).
//	-> Returns the newly created string, or NULL if allocation fails.

char	*ft_strtrim(char const *s1, char const *set);
//	Allocates with malloc() and creates a copy of string s1
//		without the leading and trailing characters specified in set.
//	-> Returns the newly created string (if s contains no leading or trailing
//		set characters, returns a copy of s), or NULL if allocation fails.

char	*ft_itoa(int n);
//	Allocates with malloc() and creates a new null-terminated string
//		representing the integer n.
//	-> Returns the newly created string, or NULL if allocation fails.

char	**ft_split(char const *s, char c);
//	Allocates with malloc() and creates an array of null-terminated strings
//		resulting from splitting the string s according to the character c.
//	-> Returns the newly created array of strings, or NULL if allocation fails.

/*******************************************************************************
MEMORY MANIPULATION FUNCTIONS
******************************************************************************/

void	ft_bzero(void *s, size_t n);
//	Writes n zeroed bytes to the string s.
//		If n is zero, ft_bzero() does nothing.

void	*ft_calloc(size_t nmemb, size_t size);
//	Allocates memory for an array of nmemb elements of size bytes each.
//		The  memory  is set to zero.
//	-> Returns a pointer to the allocated memory.
//		If nmemb or size is wero, returns a unique pointer value that can be
//		passed to free.
//		If the multiplication of nmemb * size would result in integer overflow,
//		calloc() returns NULL.

void	*ft_memset(void *s, int c, size_t n);
//	Writes n bytes of value c (converted to an unsigned char) to the string s.
//	-> Returns its first argument.

int		ft_memcmp(const void *s1, const void *s2, size_t n);
//	Compares byte string s1 against byte string s2
//		(both strings are assumed to be n bytes long).
//	-> Returns zero if the two strings are identical, otherwise returns the
//		difference between the first two differing bytes treated as
//		unsigned char values (zero-length strings are always identical).

void	*ft_memcpy(void *dst, const void *src, size_t n);
//	Copies n bytes from memory area src to memory area dst.
//	!! If dst and src overlap, behavior is undefined.
//	-> Returns the original value of dst.

void	*ft_memmove(void *dest, const void *src, size_t n);
//	Copies len bytes from string src to string dest. The two strings may
//		overlap; the copy is always done in a non-destructive manner.
//	-> Returns the original value of dest.

void	*ft_memchr(const void *s, int c, size_t n);
//	Locates the first occurrence of c (converted to an unsigned char)
//		in string s.
//	-> Returns a pointer to the byte located,
//		or NULL if no such byte exists within n bytes.

/*******************************************************************************
CALLBACK FUNCTIONS
******************************************************************************/

void	ft_striteri(char *s, void (*f)(unsigned int, char *));
//	Applies the function f to each character of the string s,
//		specifying its index as the first argument.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));	
//	Applies the function f to each character of the string s,
//		specifying the characters's index, to create a new string
//		allocated with malloc() resulting from the successive applications of f.
//	-> Returns the new created string.

/*******************************************************************************
LIST MANIPULATION FUNCTIONS
******************************************************************************/

t_list	*ft_lstnew(void *content);
//	Allocates (using malloc()) and returns a new link.
//		The content field in the new link is initialized with the value of the
//		content parameter.
//		The next field is initialized to NULL.
//	-> Returns the "fresh" link, or NULL if allocation fails.

void	ft_lstdelone(t_list *lst, void (*del)(void *));
//	Frees the memory of the element passed as parameter using the 'del'
//		function, then with free().
//	!! The memory of the next field is not freed.

void	ft_lstadd_front(t_list **lst, t_list *new);
//	Add the element new at the start of the list
//		(lst is the address of the pointer to the first element of the list,
//		and new is the address of the pointer to the element to be added).

int		ft_lstsize(t_list *lst);
//	Counts the number of elements of the list.
//		Lst is the start of the list.
//	-> Returns the count.

t_list	*ft_lstlast(t_list *lst);
//	Finds the last element of the list (where lst is the first element).
//	-> Returns the last element of the list.

void	ft_lstadd_back(t_list **lst, t_list *new);
//	Add the element new to the end of the list.
//		(lst is the adress of the pointer to  the first element of the list,
//		and new is the address of the pointer to the element to be added).

void	ft_lstclear(t_list **lst, void (*del)(void*));
//	Deletes and frees the memory of the element passed as parameter and of all
//		the following elements, using the del() function and free().
//		Sets the initial pointer to NULL.
//		(lst is the address to the pointer to an element and del is the adress
//		of the function that can suppress the content of an element).

void	ft_lstiter(t_list *lst, void (*f)(void *));
//	Iterates over the list lst and applies the function f() to the content
//		of each element (lst is the address of the pointer to an element and
//		f is the address of the function to apply).

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//	Iterates over the list lst and applies the function f() to the content
//		of each element.
//		Creates a new list resulting from the successive applications of
//		f().
//		The function del() is here to destroy the content of an element if
//		needed.
//	-> Returns the new list otr NULL if allocation fails.


/*******************************************************************************
OTHER FUNCTIONS
******************************************************************************/

int	ft_printf(const char *str, ...);
//	Outputs the string str to the standard output (like printf())
// 	allowing the use of meta-characters to print variables.
//		-> Returns the number of characters printed.

char	*get_next_line(int fd);
//	Reads a line from a file descriptor.
//		-> Returns a pointer to the line read or NULL if an error occurs.

#endif
