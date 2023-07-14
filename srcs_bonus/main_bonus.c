/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:12:58 by cacarval          #+#    #+#             */
/*   Updated: 2023/07/04 14:32:06 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exit_error(t_game *game, char *msg)
{
	clean_game(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	render_move(t_game *game)
{
	static int	movcounter = -1;

	if (movcounter % 2 == 0)
		monster_position(game);
	if (++movcounter % 3 == 0)
	{
		coin_animation(game);
		ft_put_sprites(game, game->curr.y, game->curr.x, 'P');
	}
	usleep(80000);
	return (0);
}

int	filename_check(char *s)
{
	int	i;

	i = ft_strlen (s);
	if (!ft_strnstr (s + i - 4, ".ber", 4))
		exit_error(NULL, "Wrong map format try .ber");
	return (1);
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
	mlx_loop_hook(game.mlx, render_move, &game);
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
