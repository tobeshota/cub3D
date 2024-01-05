/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:43:35 by toshota           #+#    #+#             */
/*   Updated: 2023/09/24 15:00:53 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start_len(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			return (i);
		i++;
	}
	return (ft_strlen(s1));
}

static size_t	get_end_len(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			return (i + 1);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_len;
	size_t	end_len;
	size_t	result_len;
	char	*result;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start_len = get_start_len(s1, set);
	end_len = get_end_len(s1, set);
	if (start_len > end_len)
		return (ft_strdup(""));
	result_len = end_len - start_len + 1;
	result = (char *)malloc(sizeof(char) * result_len);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < result_len - 1)
	{
		result[i] = s1[start_len + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

// #include <stdio.h>

// int main(void)
// {
//     // char *s1 = "    hello world     ";
// 	char *s1 = "       ";
//     char *s2 = " ";
//     char *s3 = ft_strtrim(s1, s2);
//     printf("%s\n", s3);
//     return (0);
// }
