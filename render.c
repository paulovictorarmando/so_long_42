/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 07:39:26 by parmando          #+#    #+#             */
/*   Updated: 2024/09/28 07:39:29 by parmando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_game(t_game *game)
{
	int	b;
	int	a;

	a = -1;
	while (++a < game->map.height)
	{
		b = -1;
		while (++b < (int)game->map.width)
		{
			if (game->map.map_data[a][b] == '1')
				mlx_put_image_to_window(game->mlx,
					game->win, game->map.img_wall, b * 32, a * 32);
			else if (game->map.map_data[a][b] == '0')
				mlx_put_image_to_window(game->mlx,
					game->win, game->map.img_path, b * 32, a * 32);
			else if (game->map.map_data[a][b] == 'E')
				mlx_put_image_to_window(game->mlx,
					game->win, game->map.img_exit, b * 32, a * 32);
		}
	}
}

static void	put_img(t_game *game, int a, int b, int key)
{
	if (key == W || key == UP)
		mlx_put_image_to_window(game->mlx,
			game->win, game->player.img_w, b, a);
	if (key == S || key == DW)
		mlx_put_image_to_window(game->mlx,
			game->win, game->player.img_s, b, a);
	if (key == D || key == RT || key == 0)
		mlx_put_image_to_window(game->mlx,
			game->win, game->player.img_d, b, a);
	if (key == A || key == LF)
		mlx_put_image_to_window(game->mlx,
			game->win, game->player.img_a, b, a);
}

void	render_player(t_game *game, int key)
{
	int	b;
	int	a;

	a = -1;
	while (++a < game->map.height)
	{
		b = -1;
		while (++b < (int)game->map.width)
		{
			if (game->map.map_data[a][b] == 'P')
			{
				put_img(game, a * 32, b * 32, key);
			}
		}
	}
}

void	render_food(t_game *game)
{
	int	b;
	int	a;

	a = -1;
	while (++a < game->map.height)
	{
		b = -1;
		while (++b < (int)game->map.width)
		{
			if (game->map.map_data[a][b] == 'C')
				mlx_put_image_to_window(game->mlx,
					game->win, game->map.img_food, b * 32, a * 32);
		}
	}
}
