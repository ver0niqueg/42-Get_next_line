/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:24:41 by vgalmich          #+#    #+#             */
/*   Updated: 2024/07/27 15:52:19 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	strlen;
	char	*substring;

	strlen = gnl_strlen(s);
	i = 0;
	if (!s)
		return (0);
	if (start > strlen)
	{
		substring = malloc(sizeof(char) * (1));
		if (!substring)
			return (NULL);
		substring[0] = '\0';
		return (substring);
	}
	if (strlen - start < len)
		len = strlen - start;
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (start < strlen && i < len && s[start])
		substring[i++] = s[start++];
	substring[i] = '\0';
	return (substring);
}
