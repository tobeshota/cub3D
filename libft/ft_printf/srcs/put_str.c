/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:11:39 by tobeshota         #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	put_str(char *str, t_flags *flags, int *written_len)
{
	if (str == NULL)
		str = "(null)";
	flags->args = ft_strlen(str);
	get_args_output_len(flags);
	get_space_len_in_str(flags);
	if (flags->minus_flag == 0)
		put_space(flags->min_field_width);
	if (flags->precision == -1)
		flags->args = 0;
	put(STDOUT_FILENO, str, flags->args);
	if (flags->minus_flag == 1)
		put_space(flags->min_field_width);
	*written_len += flags->args + flags->min_field_width;
}
