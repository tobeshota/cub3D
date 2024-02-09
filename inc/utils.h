/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/07 13:48:58 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include "libft.h"
# include "define.h"

void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_color_number(int alpha, int red, int green, int blue);
unsigned int	*texture_bit_shift(t_img *img, size_t x, size_t y);
bool			judge_directon_chara(char chara);
bool			judge_map_chara(const char chara);
size_t			blank_pass(char *str);
char			*str_connect(char *str, char *addstr);
int				round_number(double number);
double			my_abs(double number);
double			get_radian(int angle);
size_t			ft_array_len(char **array);
size_t			ft_path_len(char *str);
size_t			ft_line_len(char *str);
int				ft_strrncmp(const char *s1, const char *s2, size_t n);
void			free_data(t_data *data);
void			free_game(t_game *game);
void			free_map(t_map *map);
void			free_img(t_img *img);
void			free_texture(t_texture *texture);
void			free_str_array(char **array);

#endif
