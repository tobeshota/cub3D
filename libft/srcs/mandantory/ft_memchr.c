/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:05:25 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:00:35 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	char		ch;
	size_t		i;

	i = 0;
	ch = (char)c;
	str = (const char *)s;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*s = "abcde";
// 	int			c = 'd';
// 	size_t		n;
// 	char		*str_result;
// 	char		*libc_result;
// 	char		*ft_result;

// 	n = 3;
// 	str_result = strchr(s, c);
// 	libc_result = memchr(s, c, n);
// 	ft_result = ft_memchr(s, c, n);
// 	printf("str:  %s\n", str_result);
// 	printf("libc: %s\n", libc_result);
// 	printf("ft:   %s\n", ft_result);
// 	return (0);
// }
