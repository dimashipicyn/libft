/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:59:17 by lbespin           #+#    #+#             */
/*   Updated: 2021/06/01 19:43:46 by lbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"
# define TRUE 1
# define FALSE 0
# define BOOLEAN int

/*
** function from standard c library
** libft part 1
** ctring
*/
char				*ft_strchr(const char *str, int val);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *str, int val);
char				*ft_strdup(const char *str);
char				*ft_strnstr(const char *s1, const char *s2, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strrev(char *str);
size_t				ft_strnlen(const char *s, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_str_repeat(int stream, int repeat, char *str);
char				**ft_split_reg(char *s, char *reg);
int					ft_isalnum(int character);
int					ft_isalpha(int character);
int					ft_isascii(int character);
int					ft_isdigit(int character);
int					ft_isprint(int character);
int					ft_isnewline(int character);
int					ft_isdigit_str(const char *s);
int					ft_tolower(int character);
int					ft_toupper(int character);
void				ft_toupper_str(char *str);

/*
** libft part 2
** memory manipulation, etc
*/
void				ft_bzero(void *memptr, size_t n);
void				*ft_memset(void *memptr, int val, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *memptr, int val, size_t n);
int					ft_memcmp(const void *memptr1,
						const void *memptr2, size_t n);
int					ft_atoi(char *str);
long				ft_atol(char *str);
char				*ft_itoa_base(unsigned long long nb, int base);
char				*ft_itoa(int n);
void				*ft_calloc(size_t nmem, size_t size);
void				*ft_realloc(void *mem, size_t size, size_t bytes);
void				ft_swap(void *a, void *b, int size);
void				ft_bubblesort(void *array, int size,
						int len, int (*cmp)(void *, void *));
void				aFailed(char *file, int line, char *expr);
void				test_check(int res, char *file, int line, char *expr);
char				*ft_getprogname(void);
void				ft_setprogname(char *name);
size_t				ft_ptrlen(const void **ptr);
void				ft_free_array_ptr(void	**array);

/*
** lists function
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/*
** mooore lists
*/
t_list				*ft_create_elem(void *content);
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
void				ft_list_clear(t_list **begin_list);
t_list				*ft_list_find(t_list *begin_list,
						void *data_ref, int (*cmp)());
void				ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
						void *data_ref, int (*cmp)(void *, void *));
void				ft_list_foreach(t_list *begin_list, void (*f)(void *));
t_list				*ft_list_last(t_list *begin_list);
void				ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void				ft_list_push_back(t_list **begin_list, void *data);
void				ft_list_push_front(t_list **begin_list, void *data);
t_list				*ft_list_push_params(int ac, char **av);
void				ft_list_remove_if(t_list **begin_list,
						void *data_ref, int (*cmp)());
void				ft_list_reverse_fun(t_list *begin_list);
void				ft_list_reverse(t_list **begin_list);
int					ft_list_size(t_list *begin_list);
void				ft_list_sort(t_list **begin_list, int (*cmp)());

/*
** input output function
*/
int					get_next_line(int fd, char **line);
int					ft_printf(const char *fmt, ...);
void				ft_eprintf(const char *fmt, ...);
void				ft_wprintf(const char *fmt, ...);
int					ft_fprintf(int stream, const char *fmt, ...);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

#endif
