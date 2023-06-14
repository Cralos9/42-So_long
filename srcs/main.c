/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:12:58 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/14 15:40:18 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// int	render_move(t_game *game)
// {
// 	(void)game;
// 	move_player(game);
// 	return(0);
// }

void launch_game(char *file)
{
	t_game game;

	bzero(&game, sizeof(t_game));
	game.mlx = mlx_init();
	ft_getsprites(&game);
	ft_initmap(&game, file);
	mlx_hook(game.win, KeyPress, KeyPressMask, check_key, &game);
	// mlx_loop_hook(game.mlx, render_move, &game);
	mlx_loop(game.mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Wrong number of arguments.\nTry again ex: ./so_long assets/maps/map1.ber");
		return (0);
	}
	launch_game(argv[1]);
	return (0);
}