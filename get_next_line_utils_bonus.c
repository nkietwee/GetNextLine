/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:48:19 by nkietwee          #+#    #+#             */
/*   Updated: 2022/11/23 01:52:43 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *dst, char *src)
{
	int		i;
	int		dstlen;
	int		srclen;
	char	*ans;

	i = 0;
	dstlen = ft_strlen(dst, 0);
	srclen = ft_strlen(src, 0);
	ans = (char *)malloc(sizeof(char) * (dstlen + srclen + 1));
	while (dst[i] != '\0')
	{
		ans[i] = dst[i];
		i++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		ans[dstlen + i] = src[i];
		i++;
	}
	ans[dstlen + i] = '\0';
	free(dst);
	return (ans);
}
