/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:09:18 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:01:04 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char *str;
// 	str = "aaaaa";
// 	printf("ft :%zu", ft_strlen(str + 1));
// 	printf("\n");
// 	printf("lib:%zu", strlen(str + 1));
// 	return (0);
// }
