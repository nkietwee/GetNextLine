/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:32:36 by nkietwee          #+#    #+#             */
/*   Updated: 2022/11/19 21:44:00 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include <fcntl.h> // open
# include <stdio.h> // printf
# include <stdlib.h> // exit
# include <unistd.h>  // read,write
# include <string.h> 

int     ft_strlen(char *str, int mode);
char    *get_next_line(int fd);
char	*ft_keeptmp(char *tmp);
char	*ft_keeptext(char *tmp);
char	*ft_readbufjoin(char *tmp, int fd, int readbuf);
char    *ft_strjoin(char *dst,char *src);

#endif



