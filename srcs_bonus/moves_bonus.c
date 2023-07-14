/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:53:58 by cacarval          #+#    #+#             */
/*   Updated: 2023/07/04 14:32:11 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_player(t_game *game)
{
	static int	i = 0;

	if (i)
	{
		game->map[game->curr.y][game->curr.x] = 'E';
		ft_put_sprites(game, game->curr.y, game->curr.x, 'E');
		i = 0;
	}
	else if (game->map[game->next.y][game->next.x] == 'E')
	{
		game->map[game->curr.y][game->curr.x] = '0';
		ft_put_sprites(game, game->curr.y, game->curr.x, '0');
		i = 1;
	}
	else
	{
		game->map[game->curr.y][game->curr.x] = '0';
		ft_put_sprites(game, game->curr.y, game->curr.x, '0');
	}
	game->curr = game->next;
	game->map[game->curr.y][game->curr.x] = 'P';
	ft_put_sprites(game, game->curr.y, game->curr.x, 'P');
}

int	check_key(int key, t_game *game)
{
	if (key == ESC)
		quit_game(game);
	else if ((key == W || key == A || key == S || key == D || key == UP
			|| key == LEFT || key == RIGHT || key == DOWN) && check_moves(key,
			game) == 1)
	{
		if (key == W || key == UP)
			game->next.y--;
		else if (key == A || key == LEFT)
			game->next.x--;
		else if (key == S || key == DOWN)
			game->next.y++;
		else if (key == D || key == RIGHT)
			game->next.x++;
		moves_counter(game);
		move_player(game);
	}
	return (key);
}

void	moves_counter(t_game *game)
{
	static int	moves = 0;
	char		*movement_text;

	movement_text = ft_itoa (++moves);
	ft_printf ("Moves: %i\n", moves);
	make_map(game);
	mlx_string_put(game->mlx, game->win, (((game->columns - 4) / 2) * 45),
		(game->rows * 45), 0xFFFFFF, "Movements: ");
	mlx_string_put(game->mlx, game->win, (((game->columns - 4) / 2) * 45) + 100,
		(game->rows * 45), 0xFFFFFF, movement_text);
	free(movement_text);
}
