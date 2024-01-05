/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:38:45 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:00:45 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *src;
// 	char *lib;
// 	char *ft;
// 	src = "hello";
// 	lib = strdup(src);
// 	ft = ft_strdup(src);
// 	printf("lib: %s\n", lib);
// 	printf("ft : %s\n", ft);
// 	return (0);
// }
