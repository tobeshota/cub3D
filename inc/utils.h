/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 17:56:16 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include "libft.h"
# include "define.h"

bool	judge_map_chara(const char chara);
size_t	blank_pass(char *str);
char	*str_connect(char *str, char *addstr);
size_t	ft_array_len(char **array);
size_t	ft_path_len(char *str);
size_t	ft_line_len(char *str);
int		ft_strrncmp(const char *s1, const char *s2, size_t n);
void	free_data(t_data *data);
void	free_map(t_map *map);
void	free_str_array(char **array);

#endif
