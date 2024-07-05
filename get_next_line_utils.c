/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianliew <jianliew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:13:31 by jianliew          #+#    #+#             */
/*   Updated: 2024/07/04 17:11:59 by jianliew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dest_cnt;
	unsigned int	src_cnt;

	i = -1;
	if ((!dest || !src) && size == 0)
		return (0);
	dest_cnt = ft_strlen(dest);
	src_cnt = ft_strlen(src);
	if (size <= dest_cnt)
		return (src_cnt + size);
	while (src[++i] && (i < (size - dest_cnt - 1)))
		dest[dest_cnt + i] = src[i];
	dest[dest_cnt + i] = '\0';
	return (src_cnt + dest_cnt);
}

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	size_src;

	i = -1;
	size_src = ft_strlen(src);
	if (size == 0 || size_src == 0)
	{
		if (size_src == 0)
			dest[0] = '\0';
		return (size_src);
	}
	while (++i < (size - 1))
	{
		if (i < size_src)
			dest[i] = src [i];
		else
		{
			dest[i] = '\0';
			return (size_src);
		}
	}
	dest[i] = '\0';
	return (size_src);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub_s;

	i = -1;
	if (!s || len == 0)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub_s = (char *)malloc(len + 1);
	if (!sub_s)
		return (NULL);
	while (++i < (int)len)
		sub_s[i] = s[start + i];
	sub_s[i] = '\0';
	return (sub_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		ls1;
	int		ls2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	str = (char *)malloc(ls1 + ls2 + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ls1 + 1);
	ft_strlcat(str, s2, (ls1 + ls2 + 1));
	free((char *)s1);
	free((char *)s2);
	return (str);
}

int	ft_strchr(const char	*str, int ch)
{
	int	i;

	i = -1;
	if (ch > 256)
		ch -= 256;
	while (str[++i])
	{
		if (str[i] == ch)
			return (i);
	}
	if (!ch)
		return (0);
	return (-1);
}
