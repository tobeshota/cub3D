/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:18:52 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:00:27 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digits(int n)
{
	size_t	i;

	i = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	lnb;
	size_t	digits;

	if (n == 0)
		return (ft_strdup("0"));
	lnb = n;
	digits = get_digits(lnb);
	if (lnb < 0 && digits++)
		lnb *= -1;
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (NULL);
	result[digits] = '\0';
	while (lnb)
	{
		digits--;
		result[digits] = lnb % 10 + '0';
		lnb /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// int		n = 500;
// 	// int n = -2147483648;
// 	// char	*str = ft_itoa(n);
// 	char	*str = ft_itoa(-1);
// 	// write(1, str, 11);
// 	printf("%s\n", str);
// 	return (0);
// }
