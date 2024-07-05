/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianliew <jianliew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:12:00 by jianliew          #+#    #+#             */
/*   Updated: 2024/07/04 20:16:48 by jianliew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

void	*ft_calloc(int cnt, int size)
{
	int		i;
	void	*ptr;

	i = -1;
	if ((cnt * size) == 0)
		return (0);
	ptr = malloc(cnt * size);
	if (!ptr)
		return (NULL);
	while (++i < cnt)
		*(char *)(ptr + i) = '\0';
	return (ptr);
}

static int	verify(int ch, char *remain, char *str)
{
	if (ch < 0 || (ch == 0 && !remain))
	{
		free(str);
		return (1);
	}
	return (0);
}

static char	*no_next_line(char *str, int fd)
{
	int		ch;
	int		pos;
	char	*temp;

	pos = 1;
	ch = ft_strchr(str, '\n');
	while (ch < 0 && pos != 0)
	{
		temp = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!temp)
			return (NULL);
		pos = read(fd, temp, BUFFER_SIZE);
		if (pos == 0)
		{
			free(temp);
			return (str);
		}
		str = ft_strjoin(str, temp);
		ch = ft_strchr(str, '\n');
	}
	return (str);
}

char	*get_next_line(int fd)
{
	int			ch;
	char		*str;
	char		*nstr;
	static char	*remain;

	str = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!str)
		return (NULL);
	ch = read(fd, str, BUFFER_SIZE);
	if (verify(ch, remain, str))
		return (NULL);
	if (remain)
		str = ft_strjoin(remain, str);
	str = no_next_line(str, fd);
	ch = ft_strchr(str, '\n');
	if (ch >= 0)
	{
		nstr = ft_substr(str, 0, ch + 1);
		remain = ft_substr(str, ch + 1, ft_strlen(str) - ch - 1);
		free(str);
		return (nstr);
	}
	remain = NULL;
	return (str);
}

/* int	main(void)
{
	int		fd;
	int		cnt;
	char	*line;

	cnt = 0;
	fd = open("test", O_RDONLY);
	line = get_next_line(fd);
	printf("%d. %s", cnt, line);
	while(line != NULL)
	{
		cnt++;
		line = get_next_line(fd);
		printf("%d. %s", cnt, line);
	}
	printf("%d. %s", cnt, line);	
} */