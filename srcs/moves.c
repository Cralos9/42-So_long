/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:53:58 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/20 16:28:02 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int quit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sp[Spaces].img);
	mlx_destroy_image(game->mlx, game->sp[Player].img);
	mlx_destroy_image(game->mlx, game->sp[Exit].img);
	mlx_destroy_image(game->mlx, game->sp[Wall].img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	exit(EXIT_SUCCESS);
}

void move_player(t_game *game)
{
    int previous_x = game->curr.x;
    int previous_y = game->curr.y;

   	game->curr.x = game->next.x;
    game->curr.y = game->next.y;
   	if (game->map[previous_y][previous_x] == 'E')
        ft_put_sprites(game, previous_y, previous_x, 'E');
    else
        ft_put_sprites(game, previous_y, previous_x, '0');
    ft_put_sprites(game, game->curr.y, game->curr.x, 'P');
}

int	check_key(int key, t_game *game)
{
	static int moves = 0;
	if(key == ESC)
		quit_game(game);
	else if ((key == W || key == A || key == S || key == D ||\
			key == UP || key == LEFT || key == RIGHT || key == DOWN) && check_assets(key, game) == 1)
	{
		if (key == W || key == UP)
			game->next.y--;
		else if (key == A || key == LEFT)
			game->next.x--;
		else if (key == S || key == DOWN)
			game->next.y++;
		else if (key == D || key == RIGHT)
			game->next.x++;
		ft_printf("Moves = %i\n", ++moves);
		move_player(game);
	}
    return (key);
}