#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100

# endif

/*typedef struct s_list
{
    char *player_and_team_1;
    char *player_and_team_2;
    char *day_and_time;
    char *id;
    struct s_list *next;
}			t_list;*/

typedef struct s_helping
{
    char **raw;
    char **raw_time_day;
    char **raw_player_team_1;
    char **raw_player_team_2;
    char **tmp_id;
    char **utils;
    int  game_cont;
}			t_helping;

void	ft_get_id(t_list *t);
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
char    **ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
int     ft_length(char *name);
char	**ft_split_1(char const *s, char c);

#endif
