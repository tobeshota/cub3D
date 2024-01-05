/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reassign_flags_precision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:10:42 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reassign_flags_precision(t_flags *flags)
{
	if (flags->precision == -1 || flags->precision == -2)
		flags->precision = 0;
}
