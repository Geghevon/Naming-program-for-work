#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100

# endif

typedef struct s_list
{
    char **name_nickname;
    char **name;
    char **nickname;
    char **graphic;
    char **time;
}			t_list;

char	*get_next_line(int fd);
char	*ft_while(int fd, long rsize, char *sline);
size_t	ft_strlen1(char *s);
char	*ft_strchr1(char *s, int c);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_substr1(char *s, unsigned int start, size_t len);
char	*ft_strdup1(char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char 	*ft_strstr(char *haystack, char *needle);
void	ft_putchar_fd(char c, int fd);
int     ft_split(char const *s, char c, t_list *t, int n);
size_t	ft_strlen(const char *str);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
