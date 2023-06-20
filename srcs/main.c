/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:12:58 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/20 16:42:42 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int render_move(t_game *game)
// {
//     move_player(game);
// 	usleep(100000);
//     return (0);
// }
int filename_check(char *s)
{
	int i;

	i = ft_strlen(s);
	if(!ft_strnstr(s + i - 4,".ber", 4))
	{	
		ft_printf("Wrong map format try .ber\n");
		return(0);
	}
	return(1);
}

void	launch_game(char *file)
{
	t_game	game;

	bzero(&game, sizeof(t_game));
	ft_initmap(&game, file);
	check_map(&game);
	launch_window(&game);
	ft_getsprites(&game);
	make_map(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, check_key, &game);
	mlx_hook(game.win, DestroyNotify, 0, quit_game, &game);
	// mlx_loop_hook(game.mlx, render_move, &game);
	mlx_loop(game.mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Wrong number of arguments.\nTry again");
		return (0);
	}
	filename_check(argv[1]);
	launch_game(argv[1]);
	return (0);
}
