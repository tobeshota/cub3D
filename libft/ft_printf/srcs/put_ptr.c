/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:11:59 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	put_ptr(void *ptr, t_flags *flags, int *written_len)
{
	get_nbrlen_base((unsigned long long)ptr, "0123456789abcdef", flags);
	flags->args += 2;
	get_space_len_in_str(flags);
	if (flags->minus_flag == 0)
		put_space(flags->min_field_width);
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putnbr_base((unsigned long long)ptr, "0123456789abcdef");
	if (flags->minus_flag == 1)
		put_space(flags->min_field_width);
	*written_len += flags->args + flags->min_field_width;
}
