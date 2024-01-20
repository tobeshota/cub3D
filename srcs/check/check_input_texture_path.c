/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_texture_path.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 16:23:21 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

bool	check_path_line(char *str, size_t position, size_t len)
{
	size_t	index;

	index = position + len;
	if (str[index] != '\n' && str[index] != '\0')
		index += blank_pass(str);
	if (str[index] != '\n' && str[index] != '\0')
		return (print_error_msg("Do not include extraneous text."), false);
	return (true);
}
