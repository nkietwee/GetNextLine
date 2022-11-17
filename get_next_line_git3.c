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

// int	BUFFER_SIZE = 7;
 
int	ft_strlen(char *str, int mode)
{
	int	i;

	i = 0;

	if (mode == 0)
	{	
		while (str[i] != '\0')
			i++;
	}
	else if (mode == 1)
	{
		while (str[i] != '\n' && str[i] != '\0') // str may't \n
			i++;
		if (str[i] == '\n')
			i++;
	}
	return(i);
}

/* char *ft_strjoin(char *dst,char *src)
{
	int	i;
	int	j;
	int	dstlen;
	int	srclen;
	char *ans;

	// printf ("tmp = %s", src);
	i = 0;
	j = 0;
	dstlen = ft_strlen(dst, 0);
	srclen = ft_strlen(src, 0);
	ans = (char *)malloc(sizeof(char) * (dstlen + srclen + 1));	
	while(dst[i] != '\0')
	{
		ans[i] = dst[i];
		i++;
	}
	while(src[j] != '\0')
	{
		ans[i] = src[j];
		i++;
		j++;
	}
	ans[i] = '\0';
	// free(src);
	return (ans);
} */

char	*ft_keeptmp(char *tmp)
{
		char *kept;
		int		count_str;
		int		count_nl;
		int		i;
		
	/* 	printf("tmp = %s",tmp);
		exit(0); */
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
		// printf("kept = %s\n",kept);
		// exit(0);
		free (tmp);
		return (kept);
}
/* ft_keeptext -> return str(\n)*/
char	*ft_keeptext(char *tmp)
{
		char	*str;
		int		i;
		int		count_nl;	

		// printf("tmp in return = %s",tmp);
		// exit(0);
		i = 0;
		count_nl = ft_strlen(tmp, 1);
		// printf("count_nl = %d\n",count_nl);
		str = (char *)malloc(sizeof(char) * (count_nl + 1)); // /0 /n
		if (!str)
			return (NULL);
		while (i < count_nl)
		{
			str[i] = tmp[i];
			i++;
		}
		if (tmp[i] == '\n')
			str[i++] = '\n';
		str[i] = '\0';
		// free (tmp);
		return (str);
}

char	*ft_readbufjoin(char *tmp, int fd, int readbuf)
{
	char	*text;

	text = (char *)malloc(sizeof(char) * (1));
	if (!text)
		return (NULL);
	text[0] = '\0';
	while (readbuf != 0 ) // readbuff == 0 is EOF(End of file)		
	{
		readbuf = read(fd , text, BUFFER_SIZE);
		if (readbuf < 0) 
			return (NULL);
		// printf("readbuf = %d\n",readbuf);
		if (readbuf != 0) // add
		{
			text[readbuf] = '\0';	// it will use strjoin f(n)
		// printf ("tmp ---%s---", tmp);
			tmp = ft_strjoin(tmp, text); // readbuf > 0
			if (ft_strlen(tmp, 1) != 0)
				break;
			//if (find_ch(str, '\n') != -1)
			// 	break ;
		// printf ("text ===%s====", text);
		}
		// printf("tmp1 = %s\n", tmp);
		//printf("readbuff : %d text1 = %s\n", readbuf, text);		
		// exit(0);
	}
	free (text);
	return(tmp); // readbuf == 0 (EOF)
} 

char	*get_next_line(int fd)
{
	static char	*tmp; // keep value
	char		*text;
	
	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1026) // max of open file equal 1024 so fd equal = 1024 + 2   
		return (NULL);
	if (!tmp)
		tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	tmp = ft_readbufjoin(tmp, fd, 1); // read and join
	// printf ("tmp ===%s====\n", tmp);
	text = ft_keeptext(tmp); // keep text until \n
	tmp = ft_keeptmp(tmp); // keep text until \0 && BUFFER_SIZE
	//printf("tmp = %s\n",tmp);
	// printf("text = %s\n", text);
	//exit(0);

	return(text);

}


/* int	main(void)
{
	char *str;

	int fd = open("foo.txt", O_RDWR);
	printf("first : %s",get_next_line(fd));

	str = get_next_line(fd);
	printf("second : %s", str);
	free (str);

	str = get_next_line(fd);
	printf("third : %s", str);
	free (str);

	str = get_next_line(fd);
	printf("fourth : %s", str);
	free (str);

	str = get_next_line(fd);
	printf("five : %s", str);
	free (str);

	str = get_next_line(fd);
	printf("six : %s", str);
	free (str);
	
	str = get_next_line(fd);
	printf("seven :%s", str);
	free (str);

	str = get_next_line(fd);
	printf("eight :%s", str);
	free (str);

	str = get_next_line(fd);
	printf("nine :%s", str);
	free (str);

	// str = get_next_line(fd);
	// printf("ten :%s", str);
	// free (str);

} */




