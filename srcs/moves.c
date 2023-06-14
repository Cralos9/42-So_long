/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:53:58 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/14 15:44:07 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void move_player(t_game *game, t_map)

// int render_move(t_game *game)
// {
// 	static int i = 0;

// 	if (!check_move(game))
// 		return(0);
// 	ft_printf("Moves: %i\n", i);
// 	move_player(game, game->map)
// }


// void move_player(t_game *game)
// {
//     int previous_x = game->curr.x;
//     int previous_y = game->curr.y;

//     game->curr.x = game->next.x;
//     game->curr.y = game->next.y;

//     game->map[previous_x][previous_y] = '0';
//     game->map[game->curr.x][game->curr.y] = 'P';
// }

int	check_key(int key, t_game *game)
{
	static unsigned int i = 0;
	
	if(key == ESC)
	{
		mlx_destroy_image(game->mlx, game->sp[Spaces].img);
		mlx_destroy_image(game->mlx, game->sp[Player].img);
		mlx_destroy_image(game->mlx, game->sp[Exit].img);
		mlx_destroy_image(game->mlx, game->sp[Wall].img);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		exit(0);
	}
	else if(key == W)
	{
		printf("Moves = %i\n",i);
		// printf("Pos = %i, %i\n", game->curr.x, game->curr.y);
		game->next = (t_pos){game->curr.x, game->curr.y - 1};
		i++;
	}
	else if(key == A)
	{
		printf("Moves = %i\n",i);
		game->next = (t_pos){game->curr.x - 1, game->curr.y};
		i++;
	}
	// move_player(game);
	return (key);
}