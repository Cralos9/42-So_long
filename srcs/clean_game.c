/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:05:39 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/26 14:25:46 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_tiles(char **map)
{
	size_t	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free (map[i++]);
}

void	clean_map(t_game *game)
{
	if (!game->map)
		return ;
	clean_tiles(game->map);
	free (game->map);
}

void	clean_sprites(t_game *game)
{
	int	i;

	i = -1;
	while (++i < SPRITES)
		mlx_destroy_image(game->mlx, game->sp[i].img);
	free (game->sp);
}

void	clean_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		clean_map(game);
	if (game->sp)
		clean_sprites(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	quit_game(t_game *game)
{
	clean_game(game);
	exit(EXIT_SUCCESS);
}
