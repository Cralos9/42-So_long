/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:29:39 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/20 12:32:31 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_format(t_game *game)
{
	int i;

	i = 0;
	while(i < game->rows)
	{
		if(ft_strlen(game->map[i]) != ft_strlen(game->map[0]))
			return(0);
		i++;
	}
	return(1);
}

int	check_walls(t_game *game)
{
	int i;

	i = -1;
	while(++i < game->rows)
		if (game->map[i][0] != '1' || game->map[i][game->columns - 1] != '1')
			return(0);
	i = -1;
	while(++i < game->columns)
		if (game->map[0][i] != '1' || game->map[0][game->rows - 1] != '1' )
			return(0);
	return (1);
}

int check_tiles(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->rows)
	{
		j = -1;
		while (++j < game->columns)
		{
			if (game->map[i][j] == 'P')
			{
				game->player++;
				game->curr = (t_pos){j, i};
				game->next = (t_pos){j, i};
			}
			else if(game->map[i][j] == 'E')
				game->exit++;
			else if(game->map[i][j] == 'C')
				game->coins++;
			else if(!ft_strchr(TILES, game->map[i][j]))
				return(0);
		}
	}
	return(game->player == 1 && game->exit == 1 && game->coins >= 1);
}

int	check_paths(t_game *game)
{
	int		i;
	int		reach_exit;
	char	**tiles;

	i = -1;
	reach_exit = 0;
	tiles = ft_calloc(game->rows + 1, sizeof(char *));
	if (!tiles)
		exit_error(game, "Malloc failed.");
	while (++i < game->rows)
	{
		tiles[i] = ft_strdup(game->map[i]);
		{
			if (!tiles[i])
				exit_error(game, "Malloc failed.");
		}
	}
	reach_exit = flood_fill(game->map, game->curr, tiles, game);
	return (reach_exit);
}

void	check_map(t_game *game)
{
	if (!game->rows)
		exit_error(game, "Map is empty.");
	if (!check_format(game))
		exit_error(game,"Map is not a rectangle.");
	if (!check_walls(game))
		exit_error(game, "Map is not surrounded by walls.");
	if (!check_tiles(game))
		exit_error(game, "Map has invalid tiles.");
	if (!check_paths(game))
		exit_error(game, "Map has invalid path.");
}