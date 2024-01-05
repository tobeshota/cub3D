/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:14:02 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	proc_flag(const char **format, t_flags *flags)
{
	while (is_flag(**format))
	{
		if (**format == '-')
			flags->minus_flag = 1;
		if (**format == '0')
			flags->zero_flag = 1;
		if (**format == '#')
			flags->sharp_flag = 2;
		if (**format == ' ')
			flags->space_flag = 1;
		if (**format == '+')
			flags->plus_flag = 1;
		*format += 1;
	}
	if (flags->minus_flag)
		flags->zero_flag = 0;
	if (flags->plus_flag)
		flags->space_flag = 0;
}
