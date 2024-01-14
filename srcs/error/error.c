/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/14 15:53:00 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/error.h"

void	print_error_msg(char *errorstr)
{
	if (printf("Error.\n%s\n", errorstr) < 0)
		perror("");
	exit(EXIT_FAILURE);
}
