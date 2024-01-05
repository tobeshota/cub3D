/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnb_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:05:05 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putlnb_fd(long lnb, int fd)

{
	if (lnb < 0)
	{
		ft_putchar_fd('-', fd);
		lnb *= -1;
	}
	if (lnb >= 10)
	{
		ft_putnbr_fd(lnb / 10, fd);
		ft_putnbr_fd(lnb % 10, fd);
	}
	else
		ft_putchar_fd(lnb + '0', fd);
}
