#include "libft.h"

void	ft_init(t_list *t)
{
	t->name_nickname = malloc(sizeof(char *) * 15);
	t->name = malloc(sizeof(char *) * 15);
	t->nickname = malloc(sizeof(char *) * 15);
	t->graphic = malloc(sizeof(char *) * 50);
	t->time = malloc(sizeof(char *) * 30);
}

void	ft_free(char **arr)
{
	int i;

	i = -1;
	while(arr[++i])
		free(arr[i]);
	free(arr);
}

void	list_free(t_list *t)
{
	ft_free(t->graphic);
	ft_free(t->name);
	ft_free(t->name_nickname);
	ft_free(t->nickname);
	ft_free(t->time);
}

void ft_name_nickname(t_list *t)
{
	int i;
	int fd;

	i = 0;
	fd = open("names.txt", O_RDONLY);
	if(fd < 1)
	{
		list_free(t);
		exit(EXIT_FAILURE);
	}
	t->name_nickname[i] = get_next_line(fd);
	while(t->name_nickname[i] != NULL)
	{
		i++;
		t->name_nickname[i] = get_next_line(fd);
	}
	close(fd);
}

void ft_graphic(t_list *t)
{
	int i;
	int fd;

	i = 0;
	fd = open("graphic.txt", O_RDONLY);
	if(fd < 1)
	{
		list_free(t);
		exit(EXIT_FAILURE);
	}
	t->graphic[i] = get_next_line(fd);
	while(t->graphic[i] != NULL)
	{
		i++;
		t->graphic[i] = get_next_line(fd);
	}
	close(fd);
}

void	ft_time(t_list *t)
{
	int fd;
	int i;
	char *str;

	i = 0;
	fd = open("time.txt", O_RDONLY);
	if (fd < 1)
	{
		list_free(t);
		exit(EXIT_FAILURE);
	}
	str = malloc(sizeof(char) * 10);
	str = get_next_line(fd);
	while(str)
	{
		t->time[i] = ft_strtrim(str, "\n");
		i++;
		str = get_next_line(fd);
	}
	t->time[i] = '\0';
	free(str);
	close(fd);
}

void ft_nicknames(t_list *t)
{
	int i;

	i = 0;
	while(t->name_nickname[i])
	{
		ft_split(t->name_nickname[i], '-', t, i);
		i++;
	}
	t->name[i] = '\0';
}

void ft_second(t_list t, int i, int fd)
{
	int j;

	j = 0;
	while (t.name[j])
	{
		if(ft_strstr(t.graphic[i], t.name[j]))
			ft_putstr_fd(t.nickname[j], fd);
		j++;
	}
}

int ft_len(t_list t)
{
	int i;

	i = 0;
	while(t.graphic[i])
		i++;
	return(i);
}

void ft_writing(t_list t)
{
	int i;
	int j;
	int fd;
	int k;
	int h;

	h = ft_len(t) - 1;
	i = 0;
	k = 0;
	fd = open("video_names.txt", O_WRONLY);
	if (fd < 1)
	{
		list_free(&t);
		exit(EXIT_FAILURE);
	}
	while(t.graphic[i][0] >= 'A' && t.graphic[i][0] <= 'Z')
	{
		i++;
		j = 0;
		while (t.name[j])
		{
			if(ft_strstr(t.graphic[i - 1], t.name[j]))
			{
				ft_putstr_fd("Table Football | ", fd);
				ft_putstr_fd(t.nickname[j], fd);
				ft_putstr_fd(" - ", fd);
				ft_second(t, i, fd);
				ft_putstr_fd(" | ", fd);
				ft_putstr_fd(t.graphic[h], fd);
				ft_putchar_fd(' ', fd);
				ft_putstr_fd(t.time[k], fd);
				ft_putstr_fd("(GMT+4)", fd);
				ft_putstr_fd(" | MFL", fd);
				ft_putchar_fd('\n', fd);
				k++;
			}
			j++;
		}
		i++;
	}
	close(fd);
}

int	main()
{
	t_list t;

	ft_init(&t);
	ft_name_nickname(&t);
	ft_graphic(&t);
	ft_time(&t);
	ft_nicknames(&t);
	ft_writing(t);
	list_free(&t);
	return(0);
}
