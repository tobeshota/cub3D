/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:12:11 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	put_percent(int *written_len, t_flags *flags)
{
	flags->args = 1;
	get_space_len_in_str(flags);
	if (flags->zero_flag == 1)
		put_zero(flags->min_field_width);
	else if (flags->minus_flag == 0)
		put_space(flags->min_field_width);
	ft_putchar_fd('%', STDOUT_FILENO);
	if (flags->minus_flag == 1)
		put_space(flags->min_field_width);
	*written_len += flags->args + flags->min_field_width;
}
