/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:26:39 by mmita             #+#    #+#             */
/*   Updated: 2023/08/24 15:05:06 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*gnl_read_memo(int fd, char *memo);
char	*gnl_return_line(char *memo);
char	*gnl_update_memo(char *memo);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(const char *str);
char	*gnl_strchr(const char *s, int c);
void	*gnl_calloc(size_t count, size_t size);
void	gnl_bzero(void *s, size_t n);

#endif