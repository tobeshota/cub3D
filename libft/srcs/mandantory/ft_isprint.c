/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:32:37 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:00:26 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// #include <stdio.h>
// #include <ctype.h>

// int main(void)
// {
// 	for(int i = -256; i < 256; i++)
// 		printf("%d: %d %d\n", i, isprint(i), ft_isprint(i));
// 	// for(int i = -256; i < 256; i++)
// 	// 	printf("%d: %d\n", i, ft_isprint(i));
// }
