/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:18:45 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:00:24 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <stdio.h>
// #include <ctype.h>

// int main(void)
// {
//     for (int i = 0; i < UCHAR_MAX; ++i) {
//         if (ft_isascii(i)) {
//             // printf("%c (%x)\n", i, i);
// 			printf("%d ", i);
//         }
//     }
// }
