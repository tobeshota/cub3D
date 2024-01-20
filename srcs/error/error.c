/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 16:06:22 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	print_error_msg(char *errorstr)
{
	if (printf("Error.\n%s\n", errorstr) < 0)
		perror("");
	exit(EXIT_FAILURE);
}
