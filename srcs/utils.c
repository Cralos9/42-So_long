/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:13:12 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/20 14:48:17 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_assets(int key, t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->curr.x;
	next_y = game->curr.y;
	if (key == W || key == UP)
		next_y--;
	else if (key == A || key == LEFT)
		next_x--;
	else if (key == S || key == DOWN)
		next_y++;
	else if (key == D || key == RIGHT)
		next_x++;
	if (game->map[next_y][next_x] != '1')	
	{
		if (game->map[next_y][next_x] == 'C')
		{
			game->count++;
			game->map[next_y][next_x] = '0';
		}
		else if(game->map[next_y][next_x] == 'E' && game->count == game->coins)
		{
			ft_printf("Great Job\n");
			check_key(ESC, game);
		}
		return (1);
	}
	return (0);
}

int	ft_cntrows(t_game *game)
{
	int		i;
	char	*str;

	i = 0;
	while (1)
	{
		str = get_next_line(game->fd);
		if (!str)
			break ;
		free(str);
		i++;
	}
	free(str);
	return (i);
}

int	exit_error(t_game *game, char *msg)
{
	(void)game;
	// clean_game(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

int	flood_fill(char **map, t_pos curr, char **path, t_game *game)
{
	static int	coins = 0;
	static int		exit = 0;

	if (path[curr.y][curr.x] == '1')
		return (0);
	else if (path[curr.y][curr.x] == 'C')
		coins++;
	else if (path[curr.y][curr.x] == 'E')
		exit = 1;
	path[curr.y][curr.x] = '1';
	flood_fill(map, (t_pos){curr.x + 1, curr.y}, path, game);
	flood_fill(map, (t_pos){curr.x - 1, curr.y}, path, game);
	flood_fill(map, (t_pos){curr.x, curr.y + 1}, path, game);
	flood_fill(map, (t_pos){curr.x, curr.y - 1}, path, game);
	return (coins == game->coins && exit == 1);
}