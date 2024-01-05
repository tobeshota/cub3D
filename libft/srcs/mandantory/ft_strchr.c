/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:50:54 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:00:44 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != ch)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*s;
// 	int			c;
// 	char		*libc_result;
// 	char		*ft_result;

// 	s = "abcde";
// 	c = 129;
// 	libc_result = strchr(s, c);
// 	ft_result = ft_strchr(s, c);
// 	printf("libc: %s\n", libc_result);
// 	printf("ft:   %s\n", ft_result);
// 	return (0);
// }
