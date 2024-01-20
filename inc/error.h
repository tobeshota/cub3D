/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 17:54:35 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define INVALID_ARGC "Invalid number of argument."
# define NOT_CUB_MAP "The extension is not .cub."
# define MALLOC_ERROR "malloc error."

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

void	print_error_msg(char *errorstr);

#endif
