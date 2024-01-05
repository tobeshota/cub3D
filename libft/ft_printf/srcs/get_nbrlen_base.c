/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbrlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:17:57 by tobeshota         #+#    #+#             */
/*   Updated: 2024/01/06 00:37:03 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	get_nbrlen_base(unsigned long long ullnb, char *base,
		t_flags *flags)
{
	unsigned long long	base_len;

	base_len = ft_strlen(base);
	if (ullnb >= base_len)
	{
		get_nbrlen_base(ullnb / base_len, base, flags);
		get_nbrlen_base(ullnb % base_len, base, flags);
	}
	else
		flags->args += 1;
}
