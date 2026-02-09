/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:19:41 by vgalmich          #+#    #+#             */
/*   Updated: 2024/07/27 15:52:14 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_update_stash(char *stash)
{
	char	*new_stash;
	char	*ptr;
	int		len;

	ptr = gnl_strchr(stash, '\n');
	if (!ptr)
	{
		new_stash = NULL;
		return (ft_free(&stash));
	}
	else
		len = (ptr - stash) + 1;
	if (!stash[len])
		return (ft_free(&stash));
	new_stash = gnl_substr(stash, len, gnl_strlen(stash) - len);
	ft_free(&stash);
	if (!new_stash)
		return (NULL);
	return (new_stash);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = gnl_strchr(stash, '\n');
	len = (ptr - stash) + 1;
	line = gnl_substr(stash, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_read_buffer(int fd, char *stash)
{
	int		rid;
	char	*buffer;

	rid = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&stash));
	buffer[0] = '\0';
	while (rid > 0 && !gnl_strchr(buffer, '\n'))
	{
		rid = read (fd, buffer, BUFFER_SIZE);
		if (rid > 0)
		{
			buffer[rid] = '\0';
			stash = gnl_strjoin(stash, buffer);
		}
	}
	free(buffer);
	if (rid == -1)
		return (ft_free(&stash));
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((stash[fd] && !gnl_strchr(stash[fd], '\n')) || !stash[fd])
		stash[fd] = ft_read_buffer (fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_extract_line(stash[fd]);
	if (!line)
		return (ft_free(&stash[fd]));
	stash[fd] = ft_update_stash(stash[fd]);
	return (line);
}
