#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;

	i = 0;
	if ((size_t)start > ft_strlen(s))
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
		return (s1);
	}
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	s1 = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
