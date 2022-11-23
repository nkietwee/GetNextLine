/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:32:36 by nkietwee          #+#    #+#             */
/*   Updated: 2022/11/22 22:59:14 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h> 

int		find_n(char *str);
int		ft_strlen(char *str, int mode);
char	*get_next_line(int fd);
char	*ft_keeptmp(char *tmp);
char	*ft_keeptext(char *tmp);
char	*ft_readbufjoin(char *tmp, int fd, int readbuf);
char	*ft_strjoin(char *dst, char *src);

#endif
