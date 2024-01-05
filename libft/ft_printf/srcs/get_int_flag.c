/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:45:55 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_int_flag(long *lnb, t_flags *flags)
{
	if (*lnb == 0 && (flags->precision == -1 || flags->precision == -2))
		flags->zero_flag = 0;
	get_sign(*lnb, flags);
	ft_abs_address(lnb);
	if (!(*lnb == 0 && (flags->precision == -1 || flags->precision == -2)))
		get_nbrlen_base(*lnb, "0123456789", flags);
	if (flags->precision == -2 && *lnb == 0)
		flags->args = 0;
	get_space_len_in_int(flags, *lnb);
	get_zero_len(flags);
}
