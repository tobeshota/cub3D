/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:14:23 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	proc_precision(const char **format, va_list args, t_flags *flags)
{
	*format += 1;
	if (!(**format == '*' || ft_isdigit(**format)))
	{
		flags->precision = -1;
		return ;
	}
	if (**format == '*')
	{
		flags->precision = va_arg(args, int);
		*format += 1;
		return ;
	}
	while (ft_isdigit(**format))
	{
		flags->precision = (flags->precision * 10) + (**format - '0');
		*format += 1;
	}
	if (flags->precision == 0)
		flags->precision = -2;
	if (is_number_conversion(**format))
		flags->zero_flag = 0;
}
