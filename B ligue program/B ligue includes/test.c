#include "libft.h"

void	ft_init(t_list *t)
{
	t->name_nickname = malloc(sizeof(char *) * 30);
	t->name = malloc(sizeof(char *) * 30);
	t->nickname = malloc(sizeof(char *) * 30);
	t->graphic = malloc(sizeof(char *) * 74);
	t->time = malloc(sizeof(char *) * 36);
}

void	ft_graphic(t_list *t)
{
	int i;
	int fd;

	i = 0;
	fd = open("graphic.txt", O_RDONLY);
	t->graphic[i] = get_next_line(fd);
	while(t->graphic[i] != NULL)
	{
		i++;
		t->graphic[i] = get_next_line(fd);
	}
	close(fd);
}

int main()
{
	t_list t;
	int i = 0;
	
	ft_init(&t);
	ft_graphic(&t);

	while(t.graphic[i] != NULL)
	{
		ft_putstr_fd(t.graphic[i], 1);
		i++;
	}
	return(0);
}
