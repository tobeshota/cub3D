/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_second.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/06 12:59:23 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_texture(t_texture *texture)
{
	if (texture->north)
		free_img(texture->north);
	if (texture->south)
		free_img(texture->south);
	if (texture->west)
		free_img(texture->west);
	if (texture->east)
		free_img(texture->east);
	return ;
}
