#include "libft.h"

int	ft_str_num(char const *s, char c)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	if (!c)
		return (1);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			num++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (num);
}

char	**ft_mal(char **array, char const *s, char c, int a)
{
	int	s_n;
	int	i;
	int	len;

	len = 0;
	s_n = 0;
	i = 0;
	while (s_n < a)
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			len++;
			i++;
		}
		array[s_n] = malloc(sizeof(char) * (len + 1));
		array[s_n][len] = '\0';
		s_n++;
	}
	return (array);
}

char	**ft_fill(char **array, char const *s, char c)
{
	int	s_n;
	int	j;
	int	i;

	i = 0;
	s_n = 0;
	j = 0;
	while (array[s_n])
	{
		i = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			array[s_n][i] = s[j];
			i++;
			j++;
		}
		s_n++;
	}
	return (array);
}

char **ft_split(char const *s, char c)
{
	char	**array;
	int		str_num;

	str_num = ft_str_num(s, c);
	if (!s || !*s)
	{
		array = malloc(sizeof(char *) * 1);
		if (!array)
			return (0);
		*array = (void *)0;
		return (0);
	}
	array = malloc(sizeof(char *) * (str_num + 1));
	array[str_num] = 0;
	array = ft_mal(array, s, c, str_num);
	array = ft_fill(array, s, c);
	return(array);
}
