/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:15:07 by toshota           #+#    #+#             */
/*   Updated: 2023/09/24 15:00:22 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (size > 0 && SIZE_MAX / size < count)
		return (NULL);
	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("lib: %p\n", calloc(0, 0));
// 	printf("ft : %p\n", ft_calloc(0, 0));
// 	printf("lib: %p\n", calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10));
// 	printf("ft : %p\n", ft_calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10));
// 	printf("%llu\n", (unsigned long long)((SIZE_MAX / 10 + 1) * 10));
// 	printf("%lu\n", SIZE_MAX);
// }

// int	main(void)
// {
// 	char	*ft;
// 	char	*lib;
// 	size_t	count;
// 	size_t	size;

// 	count = 0;
// 	size = 0;
// 	ft = (char *)calloc(count, size);
// 	lib = (char *)ft_calloc(count, size);
// 	printf("ft: %s\n", ft);
// 	printf("lib: %s\n", lib);
// 	return (0);
// }
