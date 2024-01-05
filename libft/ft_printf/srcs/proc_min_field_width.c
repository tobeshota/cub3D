/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_min_field_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:14:11 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	proc_min_field_width(const char **format, va_list args,
		t_flags *flags)
{
	if (**format == '*')
	{
		flags->min_field_width = va_arg(args, int);
		*format += 1;
		return ;
	}
	while (ft_isdigit(**format))
	{
		flags->min_field_width = (flags->min_field_width * 10) + (**format
				- '0');
		*format += 1;
	}
}
