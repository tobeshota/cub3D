/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:17:38 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_unsigned_flag(unsigned int *unb, t_flags *flags)
{
	if (*unb == 0 && (flags->precision == -1 || flags->precision == -2))
		flags->zero_flag = 0;
	if (!(*unb == 0 && (flags->precision == -1 || flags->precision == -2)))
		get_nbrlen_base(*unb, "0123456789", flags);
	get_space_len_in_int(flags, *unb);
	get_zero_len(flags);
}
