/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:13:52 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	proc_conversion(const char **format, va_list args, t_flags *flags,
		int *written_len)
{
	if (**format == 'c')
		put_char(va_arg(args, int), flags, written_len);
	else if (**format == 's')
		put_str(va_arg(args, char *), flags, written_len);
	else if (**format == 'p')
		put_ptr(va_arg(args, void *), flags, written_len);
	else if (**format == 'd' || **format == 'i')
		put_int(va_arg(args, int), flags, written_len);
	else if (**format == 'u')
		put_unsinged(va_arg(args, unsigned int), flags, written_len);
	else if (**format == 'x')
		put_hexnum_lowercase(va_arg(args, unsigned int), flags, written_len);
	else if (**format == 'X')
		put_hexnum_uppercase(va_arg(args, unsigned int), flags, written_len);
	else if (**format == '%')
		put_percent(written_len, flags);
	*format += 1;
}
