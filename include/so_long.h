/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:13:32 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/14 15:44:12 by cacarval         ###   ########.fr       */
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
# define EXIT "./assets/sprites/Exit.xpm"
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
}		t_id;

typedef struct s_pos
{
	int x;
	int y;
}			t_pos;

typedef struct s_sprites
{
	void *img;
}			t_sprites;

typedef enum e_key
{
	ESC		= 65307,
	W 		= 119,
	A		= 97,
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

}	t_game;

int		ft_cntrows(t_game *game);
int		ft_len(char const *str);
void 	lauch_game(char *file);
void	ft_getsprites(t_game *game);
void	ft_initmap(t_game *game, char *mapname);
void	ft_put_sprites(t_game *game, int i, int j, char sprite);
void	ft_get_map(t_game *game);
int		check_key(int key, t_game *game);
// void 	move_player(t_game *game);


#endif