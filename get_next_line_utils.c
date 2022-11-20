/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:07:18 by nkietwee          #+#    #+#             */
/*   Updated: 2022/11/20 17:12:55 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *ft_strjoin(char *dst,char *src)
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
	free(dst);
	return (ans);
}