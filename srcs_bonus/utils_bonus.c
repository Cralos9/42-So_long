/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:13:12 by cacarval          #+#    #+#             */
/*   Updated: 2023/07/04 14:32:17 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	check_assets(int y, int x, t_game *game)
{
	if (game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'C')
		{
			game->count++;
			game->map[y][x] = '0';
		}
		else if (game->map[y][x] == 'E' && game->count == game->coins)
		{
			ft_printf("Great Job! :D\n");
			check_key(ESC, game);
		}
		else if (game->map[y][x] == 'M')
		{
			ft_printf("You lost :(\n");
			check_key(ESC, game);
		}
		return (1);
	}
	return (0);
}

int	check_moves(int key, t_game *game)
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
	return (check_assets(next_y, next_x, game));
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

int	flood_fill(char **map, t_pos curr, char **path, t_game *game)
{
	static int	coins = 0;
	static int	exit = 0;

	if (path[curr.y][curr.x] == '1')
		return (0);
	else if (path[curr.y][curr.x] == 'C')
		coins++;
	else if (path[curr.y][curr.x] == 'E')
		exit = 1;
	else if (path[curr.y][curr.x] == 'M')
		game->num_monsters++;
	path[curr.y][curr.x] = '1';
	flood_fill(map, (t_pos){curr.x + 1, curr.y}, path, game);
	flood_fill(map, (t_pos){curr.x - 1, curr.y}, path, game);
	flood_fill(map, (t_pos){curr.x, curr.y + 1}, path, game);
	flood_fill(map, (t_pos){curr.x, curr.y - 1}, path, game);
	return (coins == game->coins && exit == 1);
}
