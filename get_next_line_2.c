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
int	BUFFER_SIZE = 5;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return(i);
}

int	check_backend(char *name)
{
	int	i;

	i = 0;
	while (name[i] != '\0')
	{
		if (name[i] == '\n')
			return (1);
		i++;
	}
	return(0);

}

/* int ft_countfind(char *str,char find)
{

	int	i;

	i = 0;
	while(str[i] != '\0')
	{	
        while (str[i] != find)
            i++;
    }
    return(i);
}

int	main(void)
{
	printf("%d", ft_countfind("HELLO", '\n'));

} */

char *ft_strjoin(char *dst,char *src)
{
	int	i;
	int	dstlen;
	int	srclen;
	char *ans;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
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
	return (ans);
}

/* int	main(void)
{
	char dst[] = "Hello";
	char src[] = "";
	printf("%s", ft_strjoin(dst,src));
} */


/* char *ft_printword(char *name, int BUFFER_SIZE)
{
	char *dst;
	char *tmp;
	int	i;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (check_backend(name) == 1 && i < BUFFER_SIZE)
	{
		while (name[i] != '\n')
		//while (i < n && name[i] != '\n')
		{
			dst[i] = name[i];
			i++;
		}
	}
	dst[i] = '\n';
		//tmp[i] = name[i];
	return (dst);
} */


char	*ft_readbufjoin(char *text, int fd, int readbuf)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	while (readbuf != 0 ) // readbuff == 0 is EOF(End of file)		
	{
		readbuf = read(fd , text, BUFFER_SIZE);
		if (readbuf < 0) 
			return (NULL);
		text[readbuf] = '\0';	// it will use strjoin f(n)
		if (readbuf > 0)
		{
			tmp = ft_strjoin(tmp, text);
			tmp[readbuf] = '\0'; 
			return(tmp);
			/* if (check_backend(tmp) == 1) // string have \n 
				return(tmp); */							
		}	
	}
	return(tmp); // readbuf == 0 (EOF)
} 
/* char	*create_tmp(char *text,int fd, int readbuf)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if(!tmp)
		return(NULL);
	text = (char *)malloc(sizeof())
	tmp = ft_readbuf()
}  */

/* char	*ft_keeptext(char *tmp)
{
		int		i;
		int		count;

		i = 0;
		count = 0;
		tmp = ft_readbufjoin()		

} */

char	*get_next_line(int fd)
{
	static char *text; // keep value
	int		readbuf;
	
	readbuf = 1;	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));	
	if (!text)
		return (NULL);
	// ft_create_tmp(text, fd, 1);
	ft_readbufjoin(text, fd, readbuf);
	// ft_keeptext(,)
	
	return(text); //tmp
}


int	main(void)
{
	int fd = open("foo.txt", O_RDONLY);
	// printf ("%d\n",fd);

	// printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

}





/*
char *get_next_line(int fd)
{
		//char text[BUFFER_SIZE + 1];
		static char *text; // keeep value
		int readbuf;
		int	index;
		
		index = 0;
		if (fd < 0 || BUFFER_SIZE < 1) // First time
		{
			return (NULL);
			// printf ("Error");
			// exit(1);
		}
		text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));	
		if (fd < 0) // It not create.
		{
			if (!text)
				return (NULL);
		}
		readbuf = read(fd , text, BUFFER_SIZE);
		while (readbuf > 0 ) // readbuff == 0 is EOF(End of file)??
		{
			if (check_backend(text) == 1)
			{
				ft_printword ();	
			}
		}
		text[index] = '\0';
}
*/





/*
int	main(void)
{
	char *str;
	int	fd = 0;
	fd = open("../collect/text.txt", O_RDONLY);
	printf("fd :%d\n", fd);
	str = get_next_line(fd);
	printf("len :%d\n", ft_strlen(str));
	printf("first :%s\n", str);
	free (str);
	// char c = 0;
	// read(fd, &c, 1);
	// printf ("printf :%c\n", c);
	str = get_next_line(fd);
	printf("second:%s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("third :%s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("fourth :%s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("fifth :%s\n", str);
	free (str);
	fd = close (fd);
}

*/




/* int	main(void)
{
	
	int fd1 = open("foo.txt", O_RDONLY);
	printf("fd1 = % d\n", fd1);

} */
