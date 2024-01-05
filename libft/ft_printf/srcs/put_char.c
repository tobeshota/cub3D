/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:35:24 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	put_char(char c, t_flags *flags, int *written_len)
{
	flags->args = 1;
	get_space_len_in_str(flags);
	if (flags->minus_flag == 0)
		put_space(flags->min_field_width);
	ft_putchar_fd(c, STDOUT_FILENO);
	if (flags->minus_flag == 1)
		put_space(flags->min_field_width);
	*written_len += 1 + flags->min_field_width;
}
