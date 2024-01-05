/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:22:40 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:00:37 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t src_n)
{
	char	*p_dest;
	char	*p_src;
	size_t	i;

	if ((dest == NULL && src == NULL) || src_n == 0)
		return (dest);
	p_dest = (char *)dest;
	p_src = (char *)src;
	i = 0;
	while (i < src_n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	dest[] = "abcde";
// 	char	src[] = "xyz";
// 	size_t	src_n;
// 	char	*libc_result;
// 	char	*ft_result;

// 	src_n = 2;
// 	libc_result = memcpy(dest, src, src_n);
// 	ft_result = ft_memcpy(dest, src, src_n);
// 	printf("libc: %s\n", libc_result);
// 	printf("ft:   %s\n", ft_result);
// 	return (0);
// }
