/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:27:17 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:01:01 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	char	*p_dest;
	size_t	i;

	p_dest = (char *)dest;
	i = 0;
	while (i < len)
	{
		p_dest[i] = c;
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char libc_buf[] = "abcde";
// 	char ft_buf[] = "abcde";
// 	int c;
// 	size_t n;

// 	c = '1';
// 	n = 3;

// 	char *libc_result = (char *)memset(libc_buf, c, n);
// 	char *ft_result = (char *)ft_memset(ft_buf, c, n);

// 	printf("libc: %s\n", libc_result);
// 	printf("ft  : %s\n", ft_result);
// 	return (0);
// }
