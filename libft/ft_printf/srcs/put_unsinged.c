/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsinged.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:05:16 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_unsinged(unsigned int unb, t_flags *flags, int *written_len)
{
	get_unsigned_flag(&unb, flags);
	if (flags->minus_flag == 1)
		put_zero(flags->precision);
	else if (flags->zero_flag == 1 && flags->precision != -1)
		put_zero(flags->min_field_width);
	if (flags->minus_flag == 0)
	{
		if (flags->zero_flag != 1)
			put_space(flags->min_field_width);
		put_zero(flags->precision);
	}
	if (!(unb == 0 && (flags->precision == -1 || flags->precision == -2)))
		ft_putnbr_base((uintptr_t)unb, "0123456789");
	if (flags->minus_flag == 1)
		put_space(flags->min_field_width);
	reassign_flags_precision(flags);
	*written_len += flags->args + flags->min_field_width + flags->precision;
}
