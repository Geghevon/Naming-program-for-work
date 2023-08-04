/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:05:00 by geghevon          #+#    #+#             */
/*   Updated: 2022/03/29 16:07:33 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_str_num_1(char const *s, char c)
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

char	**ft_mal_1(char **array, char const *s, char c, int a)
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

char	**ft_fill_1(char **array, char const *s, char c)
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

char	**ft_split_1(char const *s, char c)
{
	char	**array;
	int		str_num;
	int i = 0;

	str_num = ft_str_num_1(s, c);
	if (!s || !*s)
	{
		array = malloc(sizeof(char *) * 1);
		if (!array)
			return (NULL);
		*array = (void *)0;
		return (array);
	}
	array = malloc(sizeof(char *) * (str_num + 1));
	array[str_num] = 0;
	array = ft_mal_1(array, s, c, str_num);
	array = ft_fill_1(array, s, c);
	while (array[i])
	{

		ft_putstr_fd(array[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	
	return (array);
}
