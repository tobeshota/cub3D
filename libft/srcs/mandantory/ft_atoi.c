/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:38:59 by toshota           #+#    #+#             */
/*   Updated: 2023/09/24 15:00:20 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	is_overflow(long *lnb, const char *str, int sign)
{
	int		addend;
	long	lmax_div;
	int		lmax_mod;
	long	lmin_div;
	int		lmin_mod;

	lmax_div = LONG_MAX / 10;
	lmax_mod = LONG_MAX % 10;
	lmin_div = LONG_MIN / 10 * -1;
	lmin_mod = LONG_MIN % 10 * -1;
	addend = *str - '0';
	if (sign == 1 && (*lnb > lmax_div || (*lnb == lmax_div
				&& addend > lmax_mod)))
	{
		*lnb = LONG_MAX;
		return (1);
	}
	if (sign == -1 && (*lnb > lmin_div || (*lnb == lmin_div
				&& addend > lmin_mod)))
	{
		*lnb = LONG_MIN;
		return (1);
	}
	return (0);
}

static int	is_space(const char *str)
{
	if (*str == 32 || (*str >= 9 && *str <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	lnb;
	int		result;

	sign = 1;
	lnb = 0;
	while (is_space(str))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		if (is_overflow(&lnb, str, sign))
			break ;
		lnb = (lnb * 10) + (*str - '0');
		str++;
	}
	result = (int)(lnb * sign);
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*str;
// 	int			lib;
// 	int			ft;

// 	str = "-1";
// 	lib = atoi(str);
// 	ft = ft_atoi(str);
// 	printf("lib: %d\n", lib);
// 	printf("ft : %d\n", ft);

// 	printf("%d\n", ft_atoi("+-42"));
// 	printf("%d\n", atoi("+-42"));
// 	return (0);
// }
