/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:53:32 by vgalmich          #+#    #+#             */
/*   Updated: 2024/07/17 20:35:20 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

size_t	ft_strlen(const char *str)
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src)
char	*ft_substr(const char *s, unsigned int start, size_t len)
char	*ft_strjoin(char const *s1, char const *s2)
