/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:47:46 by nkietwee          #+#    #+#             */
/*   Updated: 2022/11/23 02:21:36 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str, int mode)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (mode == 0)
	{	
		while (str[i] != '\0')
			i++;
	}
	else if (mode == 1)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
			i++;
	}
	return (i);
}

char	*ft_keeptmp(char *tmp)
{
	char	*kept;
	int		count_str;
	int		count_nl;
	int		i;

	if (!tmp || tmp[0] == 0)
	{
		free(tmp);
		return (NULL);
	}
	i = 0;
	count_nl = ft_strlen(tmp, 1);
	count_str = ft_strlen(tmp, 0);
	kept = (char *)malloc(sizeof(char) * (count_str - count_nl + 1));
	if (!kept)
		return (NULL);
	while (i < count_str - count_nl)
	{
		kept[i] = tmp[i + count_nl];
		i++;
	}
	kept[i] = '\0';
	free (tmp);
	return (kept);
}

char	*ft_keeptext(char *tmp)
{
	char	*str;
	int		i;
	int		count_nl;	

	i = 0;
	count_nl = ft_strlen(tmp, 1);
	if (tmp[0] == 0 || !tmp)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (count_nl + 1));
	if (!str)
		return (NULL);
	while (i < count_nl)
	{
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_readbufjoin(char *tmp, int fd, int readbuf)
{
	char	*text;

	text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!text)
		return (NULL);
	while (readbuf > 0)
	{
		readbuf = read(fd, text, BUFFER_SIZE);
		if (readbuf > 0)
		{
			text[readbuf] = '\0';
			tmp = ft_strjoin(tmp, text);
			if (find_n(tmp) == 1)
				break ;
		}
	}
	free(text);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp[OPEN_MAX];
	char		*text;

	if (fd < 0 || BUFFER_SIZE <= 0
		|| read(fd, NULL, 0) == -1)
		return (NULL);
	if (!tmp[fd])
	{
		tmp[fd] = (char *)malloc(sizeof(char));
		if (!tmp[fd])
			return (NULL);
		tmp[fd][0] = 0;
	}
	tmp[fd] = ft_readbufjoin(tmp[fd], fd, 1);
	text = ft_keeptext(tmp[fd]);
	tmp[fd] = ft_keeptmp(tmp[fd]);
	return (text);
}
