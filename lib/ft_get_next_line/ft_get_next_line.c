/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:48:07 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/23 11:31:03 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

int	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
	return (1);
}

char	*extract_line(char **str)
{
	char	*line_end;
	char	*line;
	char	*tmp;

	line_end = ft_strchr(*str, '\n');
	if (line_end)
	{
		line = ft_substr(*str, 0, line_end - *str + 1);
		if (!line && ft_strdel(str))
			return (NULL);
		tmp = ft_strdup(line_end + 1);
		if (!tmp && ft_strdel(&line) && ft_strdel(str))
			return (NULL);
		ft_strdel(str);
		*str = tmp;
		return (line);
	}
	if (**str)
	{
		line = ft_strdup(*str);
		ft_strdel(str);
		return (line);
	}
	ft_strdel(str);
	return (NULL);
}

int	read_and_accumulate(int fd, char **str, char *buf)
{
	int		ret;
	char	*tmp;

	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(*str, buf);
		if (!tmp)
		{
			ft_strdel(str);
			return (-1);
		}
		ft_strdel(str);
		*str = tmp;
		if (ft_strchr(*str, '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*buf;
	char		*line;
	int			ret;

	line = NULL;
	if ((fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		&& ft_strdel(&str))
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL && ft_strdel(&str))
		return (NULL);
	if (!str)
		str = ft_strdup("");
	if ((!str || !buf) && ft_strdel(&str) && ft_strdel(&buf))
		return (NULL);
	ret = read_and_accumulate(fd, &str, buf);
	free(buf);
	if (ret == -1 && ft_strdel(&str))
		return (NULL);
	line = extract_line(&str);
	return (line);
}
