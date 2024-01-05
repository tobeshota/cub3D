/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:35:53 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:00:25 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int	c;

// 	c = '3';
// 	printf("ft:   %d\n", ft_isdigit(c));
// 	printf("libc: %d\n", isdigit(c));
// 	return (0);
// }
