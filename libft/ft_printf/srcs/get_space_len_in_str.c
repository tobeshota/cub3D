/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_space_len_in_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:17:45 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_space_len_in_str(t_flags *flags)
{
	if (flags->min_field_width <= flags->args && flags->precision != -1)
	{
		flags->min_field_width = 0;
		return ;
	}
	if (flags->precision != -1)
		flags->min_field_width = flags->min_field_width - flags->args;
}
