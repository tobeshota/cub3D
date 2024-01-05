/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:50:54 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:00:51 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*s;
// 	int			c;
// 	char		*libc_result;
// 	char		*ft_result;

// 	s = "abcde";
// 	c = 'd';
// 	libc_result = strrchr(s, c);
// 	ft_result = ft_strrchr(s, c);
// 	printf("libc: %s\n", libc_result);
// 	printf("ft:   %s\n", ft_result);
// 	return (0);
// }
