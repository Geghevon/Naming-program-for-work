/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:23:44 by geghevon          #+#    #+#             */
/*   Updated: 2022/07/06 18:41:06 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*line1;
	char		*nl;
	char		*line2;
	long		size;
	long		len;

	size = 1;
	if (size == 0)
		return (NULL);
	line1 = ft_while(fd, size, line1);
	if (!line1)
		return (NULL);
	len = ft_strlen1(line1) - ft_strlen1(ft_strchr1(line1, '\n')) + 1;
	nl = ft_substr1(line1, 0, len);
	line2 = line1;
	line1 = ft_substr1(line1, len, ft_strlen1(line1));
	free(line2);
	return (nl);
}

char	*ft_while(int fd, long size, char *line1)
{
	char		buffer[BUFFER_SIZE + 1];

	while (1)
	{	
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = '\0';
		if (size == -1)
			return (0);
		if (!line1)
			line1 = ft_strdup1(buffer);
		else
			line1 = ft_strjoin1(line1, buffer);
		if (ft_strchr1(buffer, '\n') || size == 0)
			break ;
	}
	return (line1);
}
