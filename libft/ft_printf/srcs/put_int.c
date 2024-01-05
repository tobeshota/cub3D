/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:04:48 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_int(int n, t_flags *flags, int *written_len)
{
	long	lnb;

	lnb = n;
	get_int_flag(&lnb, flags);
	if (flags->minus_flag == 1 && put_sign(flags))
		put_zero(flags->precision);
	if (flags->zero_flag == 1 && put_sign(flags))
		if (flags->precision != -1)
			put_zero(flags->min_field_width);
	if (flags->minus_flag == 0)
	{
		if (flags->zero_flag != 1 && put_space(flags->min_field_width))
			put_sign(flags);
		put_zero(flags->precision);
	}
	if (flags->args != 0)
		ft_putlnb_fd(lnb, STDOUT_FILENO);
	if (flags->minus_flag == 1)
		put_space(flags->min_field_width);
	reassign_flags_precision(flags);
	*written_len += flags->args + flags->min_field_width + flags->precision
		+ ft_abs_value(flags->sign);
}
