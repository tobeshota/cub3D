#include "ray.h"

void	ray_firing(t_game *game, t_ray *ray, int x)
{
	double	window_x;

	window_x = 2 * x / (double)DPI_W - 1;
	ray->raydirx = game->dirx + game->camx * window_x;
	ray->raydiry = game->diry + game->camy * window_x;
}

static void	calcu_sidedist(t_game *game, t_ray *ray)
{
	if (ray->raydirx > 0)
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->int_posx + 1 - game->posx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = -1;
		ray->sidedistx = (game->posx - ray->int_posx) * ray->deltadistx;
	}
	if (ray->raydiry > 0)
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->int_posy + 1 - game->posy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = -1;
		ray->sidedisty = (game->posy - ray->int_posy) * ray->deltadisty;
	}
	return ;
}

static void	calcu_dda_variable(t_game *game, t_ray *ray)
{
	ray->int_posx = (int)game->posx;
	ray->int_posy = (int)game->posy;
	if (ray->raydirx == 0)
		ray->deltadistx = __DBL_MAX__;
	else
		ray->deltadistx = (1 / ray->raydirx);
	if (ray->deltadistx < 0)
		ray->deltadistx *= -1;
	if (ray->raydiry == 0)
		ray->deltadisty = __DBL_MAX__;
	else
		ray->deltadisty = (1 / ray->raydiry);
	if (ray->deltadisty < 0)
		ray->deltadisty *= -1;
	calcu_sidedist(game, ray);
	return ;
}

static void	calcu_wall_height(t_ray *ray)
{
	ray->wall_h = (int)(DISPLAY_H / ray->raydist);
	ray->drawstart = - (ray->wall_h / 2) + (DISPLAY_H / 2);
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = (ray->wall_h / 2) + (DISPLAY_H / 2);
	if (ray->drawend >= DISPLAY_H)
		ray->drawend = DISPLAY_H;
	ray->surplus = ray->wall_h / 2 - DISPLAY_H / 2;
	if (ray->surplus < 0)
		ray->surplus = 0;
	return ;
}

void	mlx_put_image_to_window_at_specific_magnification(t_data *data, int x, int y, int magnification)
{
	void *img_ptr;
	int pos_x_to_put_pixel;
	int pos_y_to_put_pixel;
	int i;
	int j;

	if (data->map->map[y][x] == WALL)
		img_ptr = data->game->texture->minimap_wall;
	else if (data->map->map[y][x] == FLOOR || (data->map->map[y][x] == EAST || data->map->map[y][x] == SOUTH || data->map->map[y][x] == WEST || data->map->map[y][x] == NORTH))
		img_ptr = data->game->texture->minimap_floor;
	else
		return ;
	i = 0;
	pos_x_to_put_pixel = (x + data->game->posx) * magnification;
	pos_y_to_put_pixel = (y + data->game->posy) * magnification;
	while (i < magnification)
	{
		j = 0;
		while (j < magnification)
		{
			mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, img_ptr, pos_x_to_put_pixel + i, pos_y_to_put_pixel + j);
			j++;
		}
		i++;
	}
}

// ・プレイヤーの位置を中心として表示されるミニマップを円型にする（xの現在位置^2 + yの現在位置^2 == 円の大きさ（定数）とし，この式を満たす位置であるならばmlx_put_image_to_window()する）
#define CIRCLE_RADIUS 30
#define INIT_CIRCLE_POS_X	DISPLAY_W - CIRCLE_RADIUS * 2
#define INIT_CIRCLE_POS_Y	DISPLAY_H - CIRCLE_RADIUS * 2
void	put_circle(t_data *data)
{
	int y;
	int x;

	y = -MINIMAP_DISPLAY_H;
	while (y < MINIMAP_DISPLAY_H)
	{
		x = -MINIMAP_DISPLAY_W;
		while (x < MINIMAP_DISPLAY_W)
		{
			if (x * x + y * y <= CIRCLE_RADIUS * CIRCLE_RADIUS)
				mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, data->game->texture->minimap_floor, x + INIT_CIRCLE_POS_X, y + INIT_CIRCLE_POS_Y);
			x++;
		}
		y++;
	}
}

// ピクセルを特定の倍率でimgに貼り付ける
void mlx_pixel_put_at_magnification(t_data *data, int x, int y, int magnification)
{
	int pos_x_to_put_pixel;
	int pos_y_to_put_pixel;
	int	color;
	int	i;
	int	j;

	if (data->map->map[y][x] == WALL)
		color = MINIMAP_WALL_COLOR;
	else if (data->map->map[y][x] == FLOOR || (data->map->map[y][x] == EAST || data->map->map[y][x] == SOUTH || data->map->map[y][x] == WEST || data->map->map[y][x] == NORTH))
		color = MINIMAP_FLOOR_COLOR;
	else
		return ;
	pos_x_to_put_pixel = x * magnification;
	pos_y_to_put_pixel = y * magnification;
	i = 0;
	while (i < magnification)
	{
		j = 0;
		while (j < magnification)
		{
			my_mlx_pixel_put(data->game->img, pos_x_to_put_pixel + i, pos_y_to_put_pixel + j, color);
			j++;
		}
		i++;
	}
}

/* ミニマップを表示する

・ミニマップを表示する
・ミニマップをプレイヤーの位置を中心にして表示する
・プレイヤーの位置を中心として表示されるミニマップを円型にする（xの現在位置^2 + yの現在位置^2 == 円の大きさ（定数）とし，この式を満たす位置であるならばmlx_put_image_to_window()する）

*/
void	put_minimap(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			mlx_pixel_put_at_magnification(data, x, y, 5);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, data->game->img->img, 0, 0);
}

int	ray_cast(t_data *data)
{
	int		dot;
	t_map	*map;
	t_game	*game;

	map = data->map;
	game = data->game;
	dot = 0;
	while (dot < DISPLAY_W)
	{
		ray_firing(game, game->ray, dot);
		calcu_dda_variable(game, game->ray);
		game->ray->hit = 0;
		dda_exec(map, game->ray);
		calcu_wall_height(game->ray);
		draw_wall(map, game, game->ray, dot);
		dot++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->img, 0, 0);
	// ミニマップを描写する
	put_minimap(data);
	// put_circle(data);
	return (true);
}
