/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:22:23 by nkietwee          #+#    #+#             */
/*   Updated: 2022/11/16 00:09:44 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int	BUFFER_SIZE = 7;

int	ft_strlen(char *str, int mode)
{
	int	i;

	i = 0;

	if (mode == 0)
	{	
		while(str[i] != '\0')
			i++;
	}
	else if (mode == 1)
	{
		while(str[i] != '\n')
			i++;
	}
	return(i);

}

char *ft_strjoin(char *dst,char *src)
{
	int	i;
	int	dstlen;
	int	srclen;
	char *ans;

	i = 0;
	dstlen = ft_strlen(dst, 0);
	srclen = ft_strlen(src, 0);
	ans = (char *)malloc(sizeof(char) * (dstlen + srclen + 1));	
	while(dst[i] != '\0')
	{
		ans[i] = dst[i];
		i++;
	}
	i = 0;
	while(src[i] != '\0')
	{
		ans[dstlen + i] = src[i];
		i++;
	}
	ans[dstlen + i] = '\0';
	return (ans);
}

char	*ft_readbufjoin(char *tmp, int fd, int readbuf)
{
	char	*text;

	text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!text)
		return (NULL);
	text[0] = '\0';
	while (readbuf != 0 ) // readbuff == 0 is EOF(End of file)		
	{
		readbuf = read(fd , tmp, BUFFER_SIZE);
		if (readbuf < 0) 
			return (NULL);
		tmp[readbuf] = '\0';	// it will use strjoin f(n)
		// printf("text = %s ,tmp = %s",text,tmp);
		text = ft_strjoin(text, tmp); // readbuf > 0
		// printf("text = %s",text);
			return(text);							
			// return(tmp);							
	}
	return(text); // readbuf == 0 (EOF)
} 

char	*ft_keeptmp(char *tmp)
{
		char *kept;
		int		countbackendstr;
		int		countnewline;
		int		i;
		
		i = 0;
		countnewline = ft_strlen(tmp, 1); // 2
		countbackendstr = ft_strlen(tmp, 0); // 7
		kept = (char *)malloc(sizeof(char) * (countbackendstr - countnewline + 1));
		if (!kept)
			return (NULL);
		while (i < countbackendstr - countnewline)
		{
			kept[i] = tmp[i + countnewline];
			i++;
		}
		kept[i] = '\0';

		return (kept);
}
/* ft_keeptext -> return str(\n)*/
char	*ft_keeptext(char *text)
{
		char	*str;
		int		i;
		int		countnewline;	

		i = 0;
		countnewline = ft_strlen(text, 1);
		str = (char *)malloc(sizeof(char) * (countnewline + 1));
		if (!str)
			return (NULL);
		while (i < countnewline)
		{
			str[i] = text[i];
			i++;
		}
		str[i] = '\0';

		return (str);
}

char	*get_next_line(int fd)
{
	static char	*tmp; // keep value
	char		*text;
	
	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1026)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	tmp = ft_readbufjoin(tmp, fd, 1); // read and join
	text = ft_keeptext(tmp); // keep text until \n
	tmp = ft_keeptmp(tmp); // keep text until \0 && BUFFER_SIZE

	return(text);
	// return(tmp);
}

int	main(void)
{
	char *str;

	int fd = open("foo.txt", O_RDWR);
	printf("first : %s\n",get_next_line(fd));

	str = get_next_line(fd);
	printf("second : %s\n", str);
	free (str);

	str = get_next_line(fd);
	printf("third : %s\n", str);
	free (str);

	str = get_next_line(fd);
	printf("fourth : %s\n", str);
	free (str);

	str = get_next_line(fd);
	printf("five : %s\n", str);
	free (str);

	str = get_next_line(fd);
	printf("five : %s\n", str);
	free (str);
	
	str = get_next_line(fd);
	printf("five :%s\n", str);
	free (str);

	str = get_next_line(fd);
	printf("five :%s\n", str);
	free (str);

}




