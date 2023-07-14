/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:11:21 by cacarval          #+#    #+#             */
/*   Updated: 2023/07/04 14:32:14 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	launch_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Failed to initialize mlx.");
	game->win = mlx_new_window(game->mlx, \
			game->columns * SIZE, game->rows * SIZE, "so_long");
	if (!game->win)
		exit_error(game, "Failed to create window.");
}

int	animation(t_game *game, char sprite)
{
	static int	i = 0;
	int			anim[2];
	int			win_anim[2];
	int			coin_anim[2];
	int			index;

	index = 0;
	anim[0] = Player;
	anim[1] = Win;
	win_anim[0] = Player;
	win_anim[1] = Win1;
	coin_anim[0] = Coin;
	coin_anim[1] = Coin2;
	if (i == 2)
		i = 0;
	if (sprite == 'P')
	{
		if (game->coins == game->count)
			index = win_anim[i++];
		else
			index = anim[i++];
	}
	else if (sprite == 'C')
		index = coin_anim[i++];
	return (index);
}

void	ft_put_sprites(t_game *game, int y, int x, char sprite)
{
	if (sprite == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->sp[Wall].img, x * SIZE, y * SIZE);
	else if (sprite == 'P' || sprite == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->sp[animation(game, sprite)].img, x * SIZE, y * SIZE);
	else if (sprite == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->sp[Spaces].img, x * SIZE, y * SIZE);
	else if (sprite == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->sp[Exit].img, x * SIZE, y * SIZE);
	else if (sprite == 'M')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->sp[Enemy].img, x * SIZE, y * SIZE);
}

void	ft_getsprites(t_game *game)
{
	game->sp = malloc(SPRITES * sizeof(t_sprites));
	if (!game->sp)
		exit_error(game, "Couldn't load sprites");
	game->sp[Wall].img = mlx_xpm_file_to_image(game->mlx, WALL, \
				&(game->sp[Wall].height), &(game->sp[Wall].width));
	game->sp[Spaces].img = mlx_xpm_file_to_image(game->mlx, SPACES, \
				&(game->sp[Spaces].height), &(game->sp[Spaces].width));
	game->sp[Coin].img = mlx_xpm_file_to_image(game->mlx, COIN, \
				&(game->sp[Coin].height), &(game->sp[Coin].width));
	game->sp[Coin2].img = mlx_xpm_file_to_image(game->mlx, COIN2, \
				&(game->sp[Coin2].height), &(game->sp[Coin2].width));
	game->sp[Exit].img = mlx_xpm_file_to_image(game->mlx, EXIT, \
				&(game->sp[Exit].height), &(game->sp[Exit].width));
	game->sp[Enemy].img = mlx_xpm_file_to_image(game->mlx, ENEMY, \
				&(game->sp[Enemy].height), &(game->sp[Enemy].width));
	game->sp[Win].img = mlx_xpm_file_to_image(game->mlx, WIN, \
				&(game->sp[Player].height), &(game->sp[Player].width));
	game->sp[Win1].img = mlx_xpm_file_to_image(game->mlx, WIN1, \
				&(game->sp[Player].height), &(game->sp[Player].width));
	game->sp[Player].img = mlx_xpm_file_to_image(game->mlx, PLAYER, \
				&(game->sp[Player].height), &(game->sp[Player].width));
}
