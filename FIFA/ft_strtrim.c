#include "libft.h"

int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	size_t	s;
	size_t	l;

	s = 0;
	l = ft_strlen(s1);
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	while (is_set(s1[s], set) == 0)
		s++;
	if (s == l)
	{
		string = ft_strdup("");
		return (string);
	}
	while (is_set(s1[l - 1], set) == 0)
		l--;
	string = ft_substr(s1, s, l - s);
	return (string);
}
