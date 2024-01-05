/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:58:19 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:00:38 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t len)
{
	void	*dest_ptr;

	if (dest == src || len == 0)
		return (dest);
	dest_ptr = dest;
	if (dest < src)
	{
		while (len--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	}
	else
	{
		dest += len - 1;
		src += len - 1;
		while (len--)
			*(unsigned char *)dest-- = *(unsigned char *)src--;
	}
	return (dest_ptr);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *src = malloc(100);
// 	for (int i = 0; i < 100; i++)
// 		src[i] = i;
// 	char *dst = malloc(100);
// 	/* 1 */ ft_memmove(dst, src, 0);
// 	/* 2 */ ft_memmove(dst, src, 10);
// 	/* 2 */ ft_memmove(dst, src, 100);
// 	/* 3 forward overlap */ ft_memmove(dst + 42, dst, 50);
// 	/* 4 backward overlap*/ ft_memmove(dst, dst + 21, 50);
// 	return (0);
// }
