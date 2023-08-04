#include "libft.h"

void	ft_free(char **arr)
{
	int i;

	i = -1;
	while(arr[++i])
		free(arr[i]);
	free(arr);
}

void list_free(t_helping *help)
{
	ft_free(help->raw);
	ft_free(help->raw_player_team_1);
	ft_free(help->raw_player_team_2);
	ft_free(help->raw_time_day);
	ft_free(help->tmp_id);
	ft_free(help->utils);
	free(help);
}

/*t_list	*new()
{
	t_list	*t;

	t = malloc(sizeof * t);
	if (!t)
		return (NULL);
	t->player_and_team_1 = NULL;
	t->player_and_team_2 = NULL;
	t->id = NULL;
	t->day_and_time = NULL;
	t->next = NULL;
	return (t);
}*/



/*int ft_len(t_list t)
{
	int i;

	i = 0;
	while(t.graphic[i])
		i++;
	return(i);
}*/



int ft_length(char *name)
{
	char *str;
	int fd;
	int l = 0;
	fd = open(name, O_RDONLY);
	str = get_next_line(fd);
	while(str)
	{
		str = get_next_line(fd);
		l++;
	}
	free(str);
	close(fd);
	return(l);
}

void ft_utils(t_helping *help)
{
	int fd;
	int i;
	char *str;

	i = 0;
	fd = open("utils.txt", O_RDONLY);
	if(fd < 1)
	{
		list_free(help);
		exit(EXIT_FAILURE);
	}
	help->utils = malloc(sizeof(char *) * (5));
	help->utils[5] = '\0';
	str = get_next_line(fd);
	while(str && help->utils[i])
	{
		help->utils[i] = ft_strtrim(str, "\n");
		i++;
		str = get_next_line(fd);
	}
	help->utils[i] = '\0';
	free(str);
	close(fd);
}

/*void ft_init(t_list *t, int game_count)
{
	int i = 1;
	t_list *tmp;
	t = new();
	tmp = t;
	while(i < game_count)
	{
		tmp->next = new();
		i++;
		tmp = tmp->next;
	}
}*/

/*void ft_lst_free(t_list *t)
{
	t_list *tmp;

	while(t)
	{
		tmp = t->next;
		free(t);
		t = tmp;
	}
}*/

void ft_get_raw(t_helping *help)
{
	int fd;
	int i= 0;

	fd = open("id.txt", O_RDONLY);
	if(fd < 0)
		exit(EXIT_FAILURE);
	help->raw = malloc(sizeof(char *) * (help->game_cont + 1));
	help->raw[i] = get_next_line(fd);
	while (help->raw[i])
	{
		i++;
		help->raw[i] = get_next_line(fd);		
	}
	close(fd);
}

void ft_init_help(t_helping *help)
{
	help->raw_player_team_1 = malloc(sizeof(char *) * (help->game_cont + 1));
	help->raw_player_team_2 = malloc(sizeof(char *) * (help->game_cont + 1));
	help->raw_time_day = malloc(sizeof(char *) * (help->game_cont + 1));
	help->tmp_id = malloc(sizeof(char *) * (help->game_cont + 1));
}

void ft_help_parse(t_helping *help)
{
	int i = 0;
	char **tmp;

	while (help->raw[i])
	{
		tmp = ft_split(help->raw[i], '\t');
		help->raw_time_day[i] = tmp[1];
		help->raw_player_team_1[i] = tmp[2];
		help->raw_player_team_2[i] = tmp[3];
		help->tmp_id[i] = tmp[0];
		i++;
		free(tmp[4]);
		free(tmp[5]);
		free(tmp[6]);
		free(tmp[7]);
	}
	help->raw_time_day[i] = NULL;
	help->raw_player_team_1[i] = NULL;
	help->raw_player_team_2[i] = NULL;
	help->tmp_id[i] = NULL;
}

void ft_changing_day(t_helping *help)
{
	char **tmp_1;
	char **tmp_2;
	int i = 0;
	char *string_1;
	char *string_2;

	while (help->raw_time_day[i])
	{
		tmp_1 = ft_split(help->raw_time_day[i], ' ');
		tmp_2 = ft_split(tmp_1[0], '-');
		string_1 = ft_strjoin(tmp_2[2], ".");
		string_2 = ft_strjoin(string_1, tmp_2[1]);
		free(string_1);
		string_1 = ft_strjoin(string_2, ".");
		free(string_2);
		string_2 = ft_strjoin(string_1, tmp_2[0]);
		free(string_1);
		string_1 = ft_strjoin(string_2, " ");
		free(string_2);
		string_2 = ft_strjoin(string_1, ft_substr(tmp_1[1], 0, 5));
		free(string_1);
		ft_free(tmp_1);
		ft_free(tmp_2);
		free(help->raw_time_day[i]);
		help->raw_time_day[i] = string_2;
		i++;
	}
}


void ft_writing(t_helping help)
{
	int fd;
	int i;

	i = help.game_cont - 1;
	fd = open(ft_strjoin(ft_substr(help.raw_time_day[0], 0 , 10), " Table Tennis.txt"), O_CREAT | O_WRONLY | O_TRUNC);
	if (fd < 1)
	{
		list_free(&help);
		exit(EXIT_FAILURE);
	}
	while(i >= 0)
	{
		ft_putstr_fd(help.utils[0], fd);
		ft_putstr_fd(help.raw_player_team_1[i], fd);
		ft_putstr_fd(help.utils[1], fd);
		ft_putstr_fd(help.raw_player_team_2[i], fd);
		ft_putstr_fd(help.utils[2], fd);
		ft_putstr_fd(help.raw_time_day[i], fd);
		ft_putstr_fd(help.utils[3], fd);
		ft_putstr_fd(help.tmp_id[i], fd);
		ft_putchar_fd('\n', fd);
		i--;
	}
	close(fd);
}

int	main()
{
	t_helping help;
	


	help.game_cont = ft_length("id.txt");

	ft_get_raw(&help);
	ft_init_help(&help);
	ft_help_parse(&help);
	ft_changing_day(&help);
	ft_utils(&help);
	ft_writing(help);
	
	list_free(&help);
	
	return(0);
}
