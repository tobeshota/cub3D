/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_related.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/15 16:07:55 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

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
