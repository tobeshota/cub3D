/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_related.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 16:23:31 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	blank_pass(char *str)
{
	int	result;

	result = 0;
	if (str == NULL)
		return (false);
	while (str[result] != '\0'
		&& (str[result] == ' ' || str[result] == '	'))
		result++;
	return (result);
}

char	*str_connect(char *str, char *addstr)
{
	char	*tmp;
	char	*result;

	tmp = NULL;
	result = NULL;
	if (str)
		tmp = ft_strdup(str);
	if (str && !tmp)
		return (perror(""), NULL);
	if (str)
		free(str);
	result = ft_strjoin(tmp, addstr);
	if (!result)
		return (perror(""), NULL);
	free(tmp);
	free(addstr);
	return (result);
}

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t				c1_len;
	size_t				c2_len;

	c1_len = ft_strlen(s1);
	c2_len = ft_strlen(s2);
	if (n == 0)
		return (0);
	while (n-- && s1[--c1_len] != '\0' && s2[--c2_len] != '\0')
	{
		if (s1[c1_len] != s2[c2_len])
			break ;
	}
	return (s1[c1_len] - s2[c2_len]);
}
