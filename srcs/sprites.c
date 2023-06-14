/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:11:21 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/14 13:38:47 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_put_sprites(t_game *game, int x, int y, char sprite)
{
		if (sprite == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->sp[Wall].img, y * SIZE, x * SIZE);
		else if (sprite == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->sp[Player].img, y * SIZE, x * SIZE);
		else if (sprite == '0')
			mlx_put_image_to_window(game->mlx, game->win, game->sp[Spaces].img, y * SIZE, x * SIZE);
		else if (sprite == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->sp[Exit].img, y * SIZE, x * SIZE);
}

void	ft_getsprites(t_game *game)
{
	game->sp = malloc(5 * sizeof(t_sprites));
	game->sp[Wall].img = mlx_xpm_file_to_image(game->mlx, WALL, &game->curr.x, &game->curr.y);
	game->sp[Spaces].img= mlx_xpm_file_to_image(game->mlx, SPACES, &game->curr.x, &game->curr.y);
	game->sp[Player].img = mlx_xpm_file_to_image(game->mlx, MC, &game->curr.x, &game->curr.y);
	game->sp[Exit].img = mlx_xpm_file_to_image(game->mlx, EXIT, &game->curr.x, &game->curr.y);
}