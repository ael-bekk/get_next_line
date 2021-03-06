/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:26:52 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/11/23 13:47:32 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*read_buff(int fd, char **buff)
{
	int		end;
	int		bol;
	char	*res;

	bol = TRUE;
	while (bol)
	{
		res = (char *)malloc(BUFFER_SIZE + 1);
		if (!res)
			return (ft_free(buff));
		end = read(fd, res, BUFFER_SIZE);
		if (!end || end == -1)
			return (ft_free(&res));
		res[end] = 0;
		bol = (find_new_line(res) == -1);
		*buff = ft_strjoin(*buff, res);
		res = NULL;
	}
	return (*buff);
}

char	*read_line(int fd, char **buff)
{
	int		end;
	char	*line;

	line = NULL;
	end = find_new_line(*buff);
	if (end == -1)
	{
		read_buff(fd, buff);
		end = find_new_line(*buff);
	}
	if (end != -1)
	{
		line = ft_substr(*buff, end);
		ft_new_buff(buff, end + 1);
		return (line);
	}
	line = ft_strjoin(line, *buff);
	if (!line)
		ft_free(buff);
	*buff = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		*line;

	line = NULL;
	if (fd >= 0 && fd < OPEN_MAX && BUFFER_SIZE > 0)
	{
		if (!buff[fd])
			read_buff(fd, &buff[fd]);
		if (buff[fd])
			line = read_line(fd, &buff[fd]);
		if (!line)
			ft_free(&buff[fd]);
	}
	return (line);
}
