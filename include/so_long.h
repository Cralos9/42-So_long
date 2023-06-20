/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:13:32 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/20 16:28:06 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <fcntl.h>

# define WALL "./assets/sprites/WALL.xpm"
# define SPACES "./assets/sprites/SPACES.xpm"
# define MC "./assets/sprites/MC.xpm"
# define MC1 "./assets/sprites/MC1.xpm"
# define EXIT "./assets/sprites/Exit.xpm"
# define COIN "./assets/sprites/coin.xpm"
# define TILES "01CEP"
# define SIZE 45

# define MLX_ERROR "ERROR : mlx failed."
# define MLX_WIN_ERROR "ERROR : win failed."


typedef enum e_index
{
	Wall,
	Spaces,
	Coin,
	Exit,
	Player,
	P1,
}		t_id;

typedef struct s_pos
{
	int x;
	int y;
}			t_pos;

typedef struct s_sprites
{
	void *img;
	int	height;
	int width;
}			t_sprites;

typedef enum e_key
{
	ESC		= 65307,
	W 		= 119,
	A		= 97,
	S		= 115,
	D       = 100,
	UP		= 65362,
	DOWN	= 65364,
	LEFT	= 65361,
	RIGHT	= 65363,
}			t_key;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_sprites *sp;
	t_pos	next;
	t_pos	curr;
	int	fd;
	int	columns;
	int	rows;
	char	**map;
	int coins;
	int count;
	int exit;
	int	player;
}	t_game;

int		ft_cntrows(t_game *game);
int		ft_len(char const *str);
void 	lauch_game(char *file);
void	ft_getsprites(t_game *game);
void	ft_initmap(t_game *game, char *mapname);
void	ft_put_sprites(t_game *game, int i, int j, char sprite);
void	ft_get_map(t_game *game);
int		check_key(int key, t_game *game);
void 	move_player(t_game *game);
int 	check_assets(int key, t_game *game);
void	check_map(t_game *game);
int		exit_error(t_game *game, char *msg);
void	make_map(t_game *game);
int	flood_fill(char **map, t_pos curr, char **path, t_game *game);
void	launch_window(t_game *game);
int quit_game(t_game *game);

#endif