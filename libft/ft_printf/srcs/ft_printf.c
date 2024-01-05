/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:41:35 by toshota           #+#    #+#             */
/*   Updated: 2023/10/13 00:32:57 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		written_len;
	va_list	args;
	t_flags	flags;

	if (format == NULL)
		return (-1);
	written_len = 0;
	va_start(args, format);
	while (written_len >= 0 && *format != '\0')
	{
		ft_bzero(&flags, sizeof(t_flags));
		if (*format == '%')
			proc_output_conversions(&format, args, &flags, &written_len);
		else
			printf_str(&format, &written_len);
	}
	va_end(args);
	return (written_len);
}
