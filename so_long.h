/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:18:00 by parmando          #+#    #+#             */
/*   Updated: 2024/09/18 08:20:59 by parmando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define LF 65361
# define RT 65363
# define UP 65362
# define DW 65364

# include "libft/libft.h"
# include "./mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	void	*img_a;
	void	*img_d;
	void	*img_w;
	void	*img_s;
	int		x;
	int		y;
	int		current_state;
	int		items_collected;
	int		count_mov;
}	t_player;

typedef struct s_map
{
	size_t		width;
	char		**map_data;
	void		*img_wall;
	void		*img_food;
	void		*img_exit;
	void		*img_path;
	int			height;
	int			num_food;
	int			num_exit;
	int			num_player;
	int			exit_x;
	int			exit_y;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
}	t_game;

void	ft_free(t_game *game);
void	set_map(t_game *game, char *argv);
void	get_map(t_game *game, char *argv);
void	close_game(t_game *game, char *s);
void	render_game(t_game *game);
void	render_player(t_game *game, int key);
void	render_food(t_game *game);
void	set_datas(t_game *game, char *argv);
void	render_game(t_game *game);
void	render_player(t_game *game, int key);
void	render_food(t_game *game);
void	ft_free_s(char **s, int i);
int		key_hook(int key, void *game);

#endif
