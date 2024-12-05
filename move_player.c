/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                        :+:    :+:   :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: parmando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:16:36 by parmando          #+#    #+#             */
/*   Updated: 2024/09/18 08:16:38 by parmando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_player(t_game *game, int key)
{
	render_game(game);
	render_food(game);
	render_player(game, key);
}

static void	end_game(t_game *game)
{
	ft_printf("%d\n", ++game->player.count_mov);
	close_game(game, "You win!\n");
}

static void	move_player(t_game *game, int x, int y, int key)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + x;
	new_y = game->player.y + y;
	if (new_x >= 0 && new_x < game->map.height && new_y >= 0
		&& new_y < (int)game->map.width)
	{
		if (game->map.map_data[new_x][new_y] == '0'
			|| game->map.map_data[new_x][new_y] == 'C')
		{
			if (game->map.map_data[new_x][new_y] == 'C')
				game->player.items_collected++;
			game->map.map_data[game->player.x][game->player.y] = '0';
			game->player.x = new_x;
			game->player.y = new_y;
			game->map.map_data[new_x][new_y] = 'P';
			draw_player(game, key);
			ft_printf("%d\n", ++game->player.count_mov);
		}
		if (game->map.map_data[new_x][new_y] == 'E'
			&& game->player.items_collected == game->map.num_food)
			end_game(game);
	}
}

int	key_hook(int key, void *game)
{
	if (key == ESC)
		close_game(game, "You ended the game\n");
	if (key == W || key == UP)
		move_player(game, -1, 0, key);
	if (key == S || key == DW)
		move_player(game, 1, 0, key);
	if (key == D || key == RT)
		move_player(game, 0, 1, key);
	if (key == A || key == LF)
		move_player(game, 0, -1, key);
	return (0);
}
