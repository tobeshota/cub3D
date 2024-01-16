/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/17 04:51:12 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

size_t	ft_array_len(char **array)
{
	size_t	len;

	len = 0;
	if (!array)
		return (len);
	while (array[len])
		len++;
	return (len);
}

size_t	ft_path_len(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0'
		&& str[len] != '\n'
		&& str[len] != ' '
		&& str[len] != '	')
		len++;
	return (len);
}

size_t	ft_line_len(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0'
		&& str[len] != '\n')
		len++;
	return (len);
}
