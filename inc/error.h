/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/14 15:52:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define INVALID_ARGC "Invalid number of argument."
# define NOT_CUB_MAP "The extension is not .ber."
# define MALLOC_ERROR "malloc error."

# include <stdlib.h>
# include <stdio.h>

void	print_error_msg(char *errorstr);

#endif