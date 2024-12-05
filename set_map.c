/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:16:36 by parmando          #+#    #+#             */
/*   Updated: 2024/09/18 08:16:38 by parmando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_valid_path(char **map, t_point lim, t_point pos, char to_fill)
{
	if (pos.y < 0 || pos.x < 0 || pos.y >= lim.y || pos.x >= lim.x
		|| (map[pos.x][pos.y] != to_fill && map[pos.x][pos.y] != 'C'
			&& map[pos.x][pos.y] != 'E' && map[pos.x][pos.y] != '0'))
		return ;
	map[pos.x][pos.y] = 'X';
	is_valid_path(map, lim, (t_point){pos.x + 1, pos.y}, to_fill);
	is_valid_path(map, lim, (t_point){pos.x - 1, pos.y}, to_fill);
	is_valid_path(map, lim, (t_point){pos.x, pos.y + 1}, to_fill);
	is_valid_path(map, lim, (t_point){pos.x, pos.y - 1}, to_fill);
}

int	verif(char **map, t_game *game)
{
	int	a;
	int	b;

	a = -1;
	while (++a < game->map.height)
	{
		b = -1;
		while (++b < (int)game->map.width)
		{
			if (map[a][b] != '0' && map[a][b] != 'X' && map[a][b] != '1' )
			{
				ft_free_s(map, game->map.height);
				return (0);
			}
		}
	}
	ft_free_s(map, game->map.height);
	return (1);
}

static int	check_path(t_game *game, int tim)
{
	char	**map;
	int		i;

	i = -1;
	map = (char **)malloc(sizeof(char *) * game->map.height);
	while (++i < game->map.height)
		map[i] = ft_strdup(game->map.map_data[i]);
	if (tim)
	{
		is_valid_path(map, (t_point){game->map.height, game->map.width},
			(t_point){game->player.x, game->player.y},
			map[game->player.x][game->player.y]);
		return (verif(map, game));
	}
	else
	{
		map[game->map.exit_x][game->map.exit_y] = 'X';
		is_valid_path(map, (t_point){game->map.height, game->map.width},
			(t_point){game->player.x, game->player.y},
			map[game->player.x][game->player.y]);
		return (verif(map, game));
	}
}

static int	map_verify(t_game *game)
{
	if (game->map.num_player != 1)
		return (0);
	if (game->map.num_exit != 1)
		return (0);
	if (game->map.num_food == 0)
		return (0);
	return (1);
}

void	set_map(t_game *game, char *argv)
{
	get_map(game, argv);
	if ((((game->map.width + 1) * 32) > 1920)
		|| (((game->map.height + 2) * 32) > 1080))
	{
		ft_free(game);
		ft_printf("Error\n<map too big!>\n");
		exit(0);
	}
	if (!map_verify(game) || !check_path(game, 1) || !check_path(game, 0))
	{
		ft_free(game);
		ft_printf("Error\n<invalid map, please check the map informations>\n");
		exit(0);
	}
}
