/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:09:12 by mmita             #+#    #+#             */
/*   Updated: 2023/08/24 15:05:52 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_read_memory(int fd, char *memo)
{
	char	*store;
	int		byte_nbr;

	byte_nbr = 1;
	store = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (store == NULL)
		return (NULL);
	while (byte_nbr > 0 && !gnl_strchr(memo, '\n'))
	{
		byte_nbr = read(fd, store, BUFFER_SIZE);
		if (byte_nbr == -1)
		{
			free(memo);
			free(store);
			return (NULL);
		}
		if (byte_nbr == 0)
			break ;
		store[byte_nbr] = '\0';
		memo = gnl_strjoin(memo, store);
	}
	free(store);
	return (memo);
}

char	*gnl_return_line(char *memo)
{
	int		i;
	char	*str;

	i = 0;
	if (!memo || *memo == '\0')
		return (NULL);
	while (memo[i] != '\0' && memo[i] != '\n')
		i++;
	str = gnl_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (memo[i] && memo[i] != '\n')
	{
		str[i] = memo[i];
		i++;
	}
	if (memo[i] == '\n')
		str[i] = '\n';
	return (str);
}

char	*gnl_update_memo(char *memo)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (memo[i] != '\0' && memo[i] != '\n')
		i++;
	if (!memo[i])
	{
		free(memo);
		return (0);
	}
	str = gnl_calloc(gnl_strlen(memo) - i + 1, sizeof(char));
	if (!str)
	{
		return (0);
	}
	i++;
	while (memo[i] != '\0')
		str[j++] = memo[i++];
	free(memo);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*return_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	memory = gnl_read_memory (fd, memory);
	if (!memory)
		return (0);
	return_line = gnl_return_line (memory);
	memory = gnl_update_memo (memory);
	return (return_line);
}
