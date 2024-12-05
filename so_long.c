/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:16:36 by parmando          #+#    #+#             */
/*   Updated: 2024/09/18 08:16:38 by parmando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	arg_check(int i, char **s)
{
	if (i != 2)
	{
		ft_printf("Error\n<use: ./so_long <map_file.ber>>\n");
		return (0);
	}
	if (ft_strncmp(s[1] + ft_strlen(s[1]) - 4, ".ber", 4) != 0
		|| ft_strncmp(s[1], ".ber", 4) == 0)
	{
		ft_printf("Error\n<invalid map format (only .ber allowed)>\n");
		return (0);
	}
	return (1);
}

static int	hook(t_game *game)
{
	close_game(game, "You ended the game\n");
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (!arg_check(argc, argv))
		return (1);
	ft_memset(&game, 0, sizeof(t_game));
	set_datas(&game, argv[1]);
	mlx_hook(game.win, 17, 0, hook, &game);
	mlx_hook(game.win, 2, 1L, key_hook, (&game));
	mlx_loop(game.mlx);
	return (0);
}
