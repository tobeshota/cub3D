/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:45:02 by toshota           #+#    #+#             */
/*   Updated: 2023/09/24 15:00:56 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strjoin(char const *tmp, char const *buf, int read_size)
{
	char	*result;

	if (tmp == NULL && read_size == 0)
		return (NULL);
	if (tmp == NULL)
		return (ft_strdup(buf));
	result = (char *)malloc((ft_strlen(tmp) + ft_strlen(buf) + 1)
			* sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, tmp, ft_strlen(tmp) + 1);
	ft_strlcpy(result + ft_strlen(tmp), buf, ft_strlen(buf) + 1);
	return (result);
}

char	*get_new_line(char **save, int fd)
{
	int		read_size;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_size] = '\0';
		tmp = *save;
		*save = gnl_strjoin(tmp, buf, read_size);
		free(tmp);
		if (*save == NULL || read_size != BUFFER_SIZE || ft_strchr(*save,
				'\n') != NULL)
			break ;
	}
	free(buf);
	return (*save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*ret;
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (get_new_line(&save[fd], fd) == NULL)
		return (NULL);
	if (ft_strchr(save[fd], '\n') != NULL)
	{
		ret = ft_substr(save[fd], 0, ft_strchr(save[fd], '\n') - save[fd] + 1);
		tmp = save[fd];
		save[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1);
		free(tmp);
	}
	else
	{
		if (*save[fd] == '\0')
			ret = NULL;
		else
			ret = ft_strdup(save[fd]);
		free(save[fd]);
		save[fd] = NULL;
	}
	return (ret);
}
