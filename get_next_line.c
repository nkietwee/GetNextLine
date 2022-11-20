/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:22:23 by nkietwee          #+#    #+#             */
/*   Updated: 2022/11/06 13:03:15y nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/* open file round1 -> fd = 3 */
/* open file round2 -> fd = 4 */
/* so open file round n -> fd = n + 2 */

// int	BUFFER_SIZE = 5;
 
int	ft_strlen(char *str, int mode)
{
	int	i;

	i = 0;

	if (mode == 0)
	{	
		while (str[i] != '\0') 
			i++; 
	}
	else if (mode == 1) // find '\n'
	{
		while (str[i] != '\n' && str[i] != '\0') // str may't \n
			i++;
		if (str[i] == '\n')
			i++;
	}
	return(i);
}

char	*ft_keeptmp(char *tmp)
{
		char *kept;
		int		count_str;
		int		count_nl;
		int		i;
		

		i = 0;
		count_nl = ft_strlen(tmp, 1); // 5
		count_str = ft_strlen(tmp, 0); // 7
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
		return(kept);
		
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
		str = (char *)malloc(sizeof(char) * (count_nl + 1)); // /0 
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


	while (readbuf > 0 ) // readbuff == 0 is EOF(End of file)		
	{
		text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // why can't sentence outside
		if (!text)
			return (NULL);
		readbuf = read(fd , text, BUFFER_SIZE);

		if (readbuf > 0) // add
		{
			text[readbuf] = '\0';

			tmp = ft_strjoin(tmp, text); 

		}
/* 		else
		{	
			if (tmp)
				free(tmp);
			tmp = NULL;
			if (text)
				free(text);
			break;
			return (NULL);
		} */
		free (text);
	}
	return(tmp); // readbuf == 0 (EOF)
} 

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*text;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd , NULL, 0) == -1)  
		return (NULL);
	if (!tmp)
		tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	tmp = ft_readbufjoin(tmp, fd, 1);
	text = ft_keeptext(tmp);
	tmp = ft_keeptmp(tmp);
	return(text);
}


/* int	main(void)
{
	char	*str;
	int	i;

	i = 0;
	int fd = open("41_with_nl", O_RDWR);
	while (i < 29)
	{
		str = get_next_line(fd);
		printf("%d : |%s|\n", i+1, str);
		printf("-------------------------------------------------------------------------\n");
		free (str);
		i++;
	}
		close(fd);
		str = get_next_line(fd);
		printf("%d : |%s|\n", i+1, str);
		printf("-------------------------------------------------------------------------\n");
		free (str);
}  */