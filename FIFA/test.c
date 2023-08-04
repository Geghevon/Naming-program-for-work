#include "libft.h"

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

void get_id()
{
   int fd;
	int i;
	char **str;

	i = 0;
	
	
    str = malloc(sizeof(char *) * (ft_length("id.txt")+ 1));
	fd = open("id.txt", O_RDONLY);
	if(fd < 1)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
	str[i] = get_next_line(fd);
	while(str[i])
	{
        i++;
		str[i] = get_next_line(fd);
	}
	//t->id[i] = '\0';
	close(fd);
	ft_split_1(str[0], '\t');
}

int main()
{
	get_id();
	return(0);
}
