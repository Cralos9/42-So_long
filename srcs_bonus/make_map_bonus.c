/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:12:44 by cacarval          #+#    #+#             */
/*   Updated: 2023/07/04 14:32:09 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_get_map(t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	while (i < game->rows)
	{
		line = get_next_line(game->fd);
		if (!line)
		{
			free(line);
			break ;
		}
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
}

void	make_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->rows)
	{
		x = 0;
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			ft_put_sprites(game, y, x, game->map[y][x]);
			x++;
		}
	}
}

void	ft_initmap(t_game *game, char *mapname)
{
	game->fd = open(mapname, O_RDONLY);
	game->rows = ft_cntrows(game);
	close(game->fd);
	game->fd = open(mapname, O_RDONLY);
	game->map = ft_calloc(game->rows + 1, sizeof(char *));
	if (!game->map)
	{
		free(game->map);
		exit_error(game, "Couldn't open map");
	}
	ft_get_map(game);
	close(game->fd);
}
