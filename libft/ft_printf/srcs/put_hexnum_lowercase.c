/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexnum_lowercase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:05:29 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	put_hexnum_lowercase(unsigned int unb, t_flags *flags,
		int *written_len)
{
	get_hexnum_lowercase_flag(&unb, flags);
	if (flags->minus_flag == 1 && flags->sharp_flag)
		ft_putstr_fd("0x", STDOUT_FILENO);
	if (flags->minus_flag == 1)
		put_zero(flags->precision);
	if (flags->zero_flag == 1 && flags->sharp_flag)
		ft_putstr_fd("0x", STDOUT_FILENO);
	if (flags->zero_flag == 1 && flags->precision != -1)
		put_zero(flags->min_field_width);
	if (flags->zero_flag != 1 && flags->minus_flag == 0
		&& put_space(flags->min_field_width))
	{
		if (flags->sharp_flag)
			ft_putstr_fd("0x", STDOUT_FILENO);
		put_zero(flags->precision);
	}
	if (!((flags->precision == -2 && unb == 0) || (flags->precision == -1
				&& unb == 0)))
		ft_putnbr_base((uintptr_t)unb, "0123456789abcdef");
	if (flags->minus_flag == 1)
		put_space(flags->min_field_width);
	reassign_flags_precision(flags);
	*written_len += flags->args + flags->min_field_width + flags->precision
		+ flags->sharp_flag;
}
