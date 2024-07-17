/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:24:41 by vgalmich          #+#    #+#             */
/*   Updated: 2024/07/16 19:13:42 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

/* Cette fonction se charge de remplir le buffer line.
Elle va lancer une boucle pour lire BUFFER_SIZE caracteres jusqu'a ce
qu'on trouve un \n.
A chaque iteration elle check si il y a quelque chose dans left_data, si
c'est le cas elle va lui joindre les nouveaux caracteres lus. S'il y a rien
elle va juste dupliquer le contenu de read_buffer dans left_data.
Si un \n est trouve, elle sort de la boucle et retourne left_data apres
avoir joint tous les nouveaux caracteres lus.
*/

static char	*fill_line_buffer(int fd, char *left_data, char *read_buffer)
{
	ssize_t	nb_read_bytes;
	char	*temp_buffer;

	nb_read_bytes = 1; // pour rentrer dans la boucle
	while (fd > 0)
	{
		fd = read(fd, read_buffer, BUFFER_SIZE);
		if (nb_read_bytes == -1)
		{
			free(left);
			return (NULL);
		}
		else if (nb_read_bytes == 0)
			break;
		buffer[nb_read_bytes] = 0;
		if(!left_data)
			left_data = ft_strdup("");
		temp_buffer = left_data;
		left_data = ft_strjoin(temp_buffer, read_buffer);
		free(temp_buffer);
		temp_buffer = NULL;
		if (ft_strchr(read_buffer, '\n'))
			break;
	}
	return (left_data);
}
/*
Cette fonction prends en parametre le buffer line et va la lire jusqu'a
trouver un \n ou un \0 (fin d'une ligne ou du fichier).
Elle va ajouter un \0 a la fin de la ligne a l'interieur du buffer line,
puis va retourner une sous chaine (left_data) a partir de la fin de la
ligne trouvee jusqu'a la fin du buffer.
*/

static char	*get_line(char	*line_buffer)
{
	char	*left_data;
	ssize_t		i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
	i++;
	if (line_buffer[0] == 0 || line_buffer[1] == 0)
	return (NULL);
	left_data = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer - i));
	if (!left_data)
	{
		free(left_data);
		return (NULL);
	}
	line_buffer[i + 1] = 0;
	return (left_data);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd < 0 | BUFFER_SIZE <= 0 | read(fd, 0, 0) < 0)
	return (NULL);
}
