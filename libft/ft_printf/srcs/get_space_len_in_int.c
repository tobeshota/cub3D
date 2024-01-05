/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_space_len_in_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:16:14 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_space_len_in_int(t_flags *flags, long lnb)
{
	int	precision;

	if (lnb == 0 && (flags->precision == -1 || flags->precision == -2))
		return ;
	if (flags->precision > 0)
		precision = flags->precision;
	else
		precision = 0;
	if (precision <= flags->args)
		flags->min_field_width = flags->min_field_width - flags->args
			- ft_abs_value(flags->sign) - flags->sharp_flag;
	else
		flags->min_field_width = flags->min_field_width - precision
			- ft_abs_value(flags->sign) - flags->sharp_flag;
	if (flags->min_field_width <= 0)
		flags->min_field_width = 0;
}
