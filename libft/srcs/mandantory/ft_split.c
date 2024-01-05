/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:43:31 by toshota           #+#    #+#             */
/*   Updated: 2023/09/24 15:00:42 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	get_word_count(char const *str, char c)
{
	int	word_count;

	word_count = 0;
	if (str[ft_strlen(str) - 1] != c || str[0] == '\0')
		word_count++;
	while (*str && *str == c)
		str++;
	while (*str)
	{
		while (*str && *str != c)
			str++;
		if (*str)
			word_count++;
		while (*str && *str == c)
			str++;
	}
	return (word_count);
}

static int	get_word_len(char const *str, char c)
{
	int	word_len;

	word_len = 0;
	while (str[word_len] && str[word_len] != c)
		word_len++;
	return (word_len);
}

static int	assign_words(char const *str, char c, char **array, int i)
{
	int	word_len;

	word_len = get_word_len(str, c);
	array[i] = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!array[i])
	{
		while (i >= 0)
			free(array[i--]);
		free(array);
		return (0);
	}
	ft_strncpy(array[i], str, word_len);
	return (1);
}

char	**ft_split(char const *str, char c)
{
	int		word_count;
	char	**array;
	int		i;

	if (str == NULL)
		return (NULL);
	word_count = get_word_count(str, c);
	array = (char **)(malloc(sizeof(char *) * (word_count + 1)));
	if (!array)
		return (NULL);
	i = 0;
	if (str[0] == '\0')
		array[0] = NULL;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && assign_words(str, c, array, i++) == 0)
			return (NULL);
		while (*str && *str != c)
			str++;
	}
	array[i] = NULL;
	return (array);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	char	c;
// 	char	**ans;
// 	int		i;

// 	str = " Tripouille";
// 	c = ' ';
// 	ans = ft_split(str, c);
// 	if (ans)
// 	{
// 		i = 0;
// 		while (ans[i])
// 		{
// 			printf("%d: %s\n", i, ans[i]);
// 			i++;
// 		}
// 		printf("%d: %s\n", i, ans[i]);
// 		i = 0;
// 		while (ans[i])
// 			free(ans[i++]);
// 		free(ans);
// 	}
// 	return (0);
// }

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }
