/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:11:21 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/20 16:19:43 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void ft_put_sprites(t_game *game, int y, int x, char sprite)
{
		if (sprite == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->sp[Wall].img, x * SIZE, y * SIZE);
		else if (sprite == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->sp[Player].img, x * SIZE, y * SIZE);
		else if (sprite == '0')
			mlx_put_image_to_window(game->mlx, game->win, game->sp[Spaces].img, x * SIZE, y * SIZE);
		else if (sprite == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->sp[Exit].img, x * SIZE, y * SIZE);
		else if (sprite == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->sp[Coin].img, x * SIZE, y * SIZE);
}

void	ft_getsprites(t_game *game)
{
	game->sp = malloc(5 * sizeof(t_sprites));
	game->sp[Wall].img = mlx_xpm_file_to_image(game->mlx, WALL, &(game->sp[Wall].height), &(game->sp[Wall].width));
	game->sp[Spaces].img= mlx_xpm_file_to_image(game->mlx, SPACES, &(game->sp[Spaces].height), &(game->sp[Spaces].width));
	game->sp[Player].img = mlx_xpm_file_to_image(game->mlx, MC, &(game->sp[Player].height), &(game->sp[Player].width));
	// game->sp[P1].img = mlx_xpm_file_to_image(game->mlx, MC1, &(game->sp[P1].height), &(game->sp[P1].width));
	game->sp[Exit].img = mlx_xpm_file_to_image(game->mlx, EXIT, &(game->sp[Exit].height), &(game->sp[Exit].width));
	game->sp[Coin].img = mlx_xpm_file_to_image(game->mlx, COIN, &(game->sp[Coin].height), &(game->sp[Coin].width));
}