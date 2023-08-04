#include "libft.h"

size_t	ft_strlen1(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr1(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == 0 && (char)c == 0)
		return ((char *)(s + i));
	return (0);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	s = (char *)malloc(sizeof(*s1) * (ft_strlen1(s1) + ft_strlen1(s2) + 1));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s[j++] = s2[i];
		i++;
	}
	s[j] = 0;
	if (s1)
		free(s1);
	return (s);
}

char	*ft_substr1(char	*s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!*s || !s)
		return (NULL);
	i = ft_strlen1(s);
	j = 0;
	if (start < i)
		j = i - start;
	if (j > len)
		j = len;
	substr = (char *)malloc(sizeof(char) * (j + 1));
	if (!substr)
		return (0);
	i = 0;
	while (s[start] && i < j)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup1(char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
	s = malloc(sizeof(char) * (ft_strlen1(s1) + 1));
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
