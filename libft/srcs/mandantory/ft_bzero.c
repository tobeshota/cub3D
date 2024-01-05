/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:09:42 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:00:21 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t len)
{
	ft_memset(dest, 0, len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char libc_buf[] = "abcde";
// 	char ft_buf[] = "abcde";
// 	size_t n;

// 	n = 3;
// 	bzero(libc_buf, n);
// 	ft_bzero(ft_buf, n);
// 	printf("libc: %s\n", libc_buf);
// 	printf("ft  : %s\n", ft_buf);
// 	return (0);
// }
