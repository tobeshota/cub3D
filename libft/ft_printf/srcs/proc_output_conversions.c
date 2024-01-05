/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_output_conversions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:42:17 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	proc_output_conversions(const char **format, va_list args,
		t_flags *flags, int *written_len)
{
	*format += 1;
	if (is_flag(**format))
		proc_flag(format, flags);
	if (is_min_field_width(**format))
		proc_min_field_width(format, args, flags);
	if (is_precision(*format))
		proc_precision(format, args, flags);
	if (is_conversion(**format))
		proc_conversion(format, args, flags, written_len);
}
