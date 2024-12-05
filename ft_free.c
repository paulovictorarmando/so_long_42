/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:16:36 by parmando          #+#    #+#             */
/*   Updated: 2024/09/18 08:16:38 by parmando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_s(char **s, int i)
{
	while (--i >= 0)
		free(s[i]);
	free(s);
}

void	ft_free(t_game *game)
{
	int	index;

	index = -1;
	while (++index < game->map.height)
		free(game->map.map_data[index]);
	free(game->map.map_data);
}

void	close_game(t_game *game, char *s)
{
	ft_printf("%s", s);
	ft_free(game);
	mlx_destroy_image(game->mlx, game->player.img_a);
	mlx_destroy_image(game->mlx, game->player.img_s);
	mlx_destroy_image(game->mlx, game->player.img_d);
	mlx_destroy_image(game->mlx, game->player.img_w);
	mlx_destroy_image(game->mlx, game->map.img_path);
	mlx_destroy_image(game->mlx, game->map.img_exit);
	mlx_destroy_image(game->mlx, game->map.img_food);
	mlx_destroy_image(game->mlx, game->map.img_wall);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
