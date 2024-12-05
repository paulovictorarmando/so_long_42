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

static int	get_nums(t_game *game, int index, int sec_index)
{
	while (game->map.map_data[++index])
	{
		sec_index = -1;
		while (game->map.map_data[index][++sec_index])
		{
			if (game->map.map_data[index][sec_index] == 'C')
				game->map.num_food++;
			else if (game->map.map_data[index][sec_index] == 'E')
			{
				game->map.exit_x = index;
				game->map.exit_y = sec_index;
				game->map.num_exit++;
			}
			else if (game->map.map_data[index][sec_index] == 'P')
			{
				game->player.x = index;
				game->player.y = sec_index;
				game->map.num_player++;
			}
			else if ((game->map.map_data[index][sec_index] != '0')
				&& (game->map.map_data[index][sec_index] != '1'))
				return (0);
		}
	}
	return (1);
}

static int	ft_check_walls(t_game *game, int index)
{
	while (index < (int)game->map.width)
	{
		if (game->map.map_data[0][index++] != '1')
			return (0);
	}
	index = 0;
	while (index < game->map.height)
	{
		if (game->map.map_data[index++][0] != '1')
			return (0);
	}
	index = 0;
	while (index < (int)game->map.width)
	{
		if (game->map.map_data[game->map.height - 1][index++] != '1')
			return (0);
	}
	index = 0;
	while (index < game->map.height)
	{
		if (game->map.map_data[index++][game->map.width - 1] != '1')
			return (0);
	}
	return (1);
}

static int	ft_check_width(t_game *game)
{
	int	index;

	index = -1;
	game->map.width = ft_strlen(game->map.map_data[0]);
	while (++index < game->map.height)
	{
		if (ft_strlen(game->map.map_data[index]) != game->map.width)
			return(0);
	}
	
	return (1);
}

static void	new_line(t_game *game, char *new)
{
	char	**tmp;
	int		index;

	tmp = (char **)malloc(sizeof(char *) * (game->map.height + 1));
	tmp[game->map.height] = NULL;
	index = -1;
	while (++index < game->map.height - 1)
		tmp[index] = game->map.map_data[index];
	tmp[index] = new;
	if (game->map.map_data)
		free(game->map.map_data);
	game->map.map_data = tmp;
}

void	get_map(t_game *game, char *argv)
{
	int		fd;
	char	*tmp;
	char	*str;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		str = ft_strchr(tmp, '\n');
		*str = '\0';
		game->map.height++;
		new_line(game, tmp);
	}
	if ((!get_nums(game, -1, -1)) || (!ft_check_width(game))
		|| (!ft_check_walls(game, 0)))
	{
		ft_free(game);
		ft_printf("Error\n<invalid map>\n");
		exit(0);
	}
}
