/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_datas.c                                          :+:      :+:  :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:16:36 by parmando          #+#    #+#             */
/*   Updated: 2024/09/18 08:16:38 by parmando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_imag(t_game *game)
{
	int	w_l;
	int	w_a;

	game->mlx = mlx_init();
	w_l = game->map.width * 32;
	w_a = game->map.height * 32;
	game->win = mlx_new_window(game->mlx, w_l, w_a, "so_long");
	game->map.img_wall = mlx_xpm_file_to_image(game->mlx,
			"./img/wall.xpm", &w_l, &w_a);
	game->player.img_a = mlx_xpm_file_to_image(game->mlx,
			"./img/a.xpm", &w_l, &w_a);
	game->player.img_s = mlx_xpm_file_to_image(game->mlx,
			"./img/s.xpm", &w_l, &w_a);
	game->player.img_w = mlx_xpm_file_to_image(game->mlx,
			"./img/w.xpm", &w_l, &w_a);
	game->player.img_d = mlx_xpm_file_to_image(game->mlx,
			"./img/d.xpm", &w_l, &w_a);
	game->map.img_exit = mlx_xpm_file_to_image(game->mlx,
			"./img/portal.xpm", &w_l, &w_a);
	game->map.img_food = mlx_xpm_file_to_image(game->mlx,
			"./img/pacdot_powerup.xpm", &w_l, &w_a);
	game->map.img_path = mlx_xpm_file_to_image(game->mlx,
			"./img/black.xpm", &w_l, &w_a);
}

void	set_datas(t_game *game, char *argv)
{
	set_map(game, argv);
	set_imag(game);
	render_game(game);
	render_food(game);
	render_player(game, 0);
}
