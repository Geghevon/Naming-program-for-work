/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:57:31 by geghevon          #+#    #+#             */
/*   Updated: 2022/03/24 20:57:40 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*string;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 && !s2)
		return (ft_strdup(""));
	else if (!s1 || !s2)
	{
		if (!s1)
			return (ft_strdup(s2));
		else if (!s2)
			return (ft_strdup(s1));
	}
	string = malloc(sizeof(char) * (s1_len + s2_len + 1));
	ft_memmove(string, s1, s1_len);
	ft_memmove(&string[s1_len], s2, s2_len);
	string[s1_len + s2_len] = '\0';
	return (string);
}
