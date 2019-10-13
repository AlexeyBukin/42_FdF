/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:23:19 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/13 04:03:24 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_isalpha(int ch);
int				ft_tolower(int ch);
int				ft_toupper(int ch);
void			*ft_memset(void *buf, int ch, size_t count);
void			*ft_memcpy(void *dest, const void *source, size_t count);
void			*ft_bzero(void *buf, size_t len);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			*ft_memset(void *buf, int ch, size_t count);
void			*ft_memchr(const void *p, int c, size_t n);
void			*ft_memccpy(void *d, const void *s, int c, size_t count);
void			*ft_memmove(void *dest, const void *source, size_t count);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *s);
char			*ft_strcpy(char *dest, const char *source);
char			*ft_strdup(const char *source);
char			*ft_strncpy(char *dest, const char *source, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t count);
size_t			ft_strlcat(char *s1, const char *s2, size_t length);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_strcmp(const char *str1, const char *str2);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
void			*ft_memalloc(size_t size);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putchar(char c);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
char			*ft_itoa(int n);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char			*ft_strfnr(char *s, int find, int replace);
char			*ft_strcfnr(const char *s, int find, int replace);
int				ft_abs(int a);
int				ft_pow(int num, int pow);
int				ft_word_count(const char *s, char c);
void			ft_lstappend(t_list **alst, t_list *new);

int				ft_atoi_base(const char *str, char base);

#endif
