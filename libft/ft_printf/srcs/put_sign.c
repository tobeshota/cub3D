/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:02:30 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	put_sign(t_flags *flags)
{
	if (flags->sign == -1)
		ft_putchar_fd('-', STDOUT_FILENO);
	else if (flags->plus_flag == 1)
		ft_putchar_fd('+', STDOUT_FILENO);
	else if (flags->space_flag == 1)
		ft_putchar_fd(' ', STDOUT_FILENO);
	return (1);
}
