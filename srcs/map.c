/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:12:44 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/14 15:41:42 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map(t_game *game)
{
	int		i;
	char	*str;

	i = 0;
	while (i < game->rows)
	{
		str = get_next_line(game->fd);
		if (!str)
		{
			free(str);
			break ;
		}
		game->map[i] = ft_strtrim(str, "\n");
		free(str);
		i++;
	}
	game->columns = ft_strlen(game->map[0]);
}

void	ft_initmap(t_game *game, char *mapname)
{
	int	x;
	int	y;


	x = 0;
	y = 0;
	game->fd = open(mapname, O_RDONLY);
	game->rows = ft_cntrows(game);
	close(game->fd);
	game->fd = open(mapname, O_RDONLY);
	game->map = ft_calloc(game->rows + 1, sizeof(char *));
	ft_get_map(game);
	game->win = mlx_new_window(game->mlx, ft_len(game->map[0]) * SIZE, game->rows * SIZE, "so_long");
	if (game->win == NULL)
	{
		free(game->win);
		ft_printf("%s\n", MLX_WIN_ERROR);
		return ;
	}
	while (x < game->rows)
	{ 
		y = 0;
		while (game->map[x][y] != '\n' && game->map[x][y] != '\0')
		{
			ft_put_sprites(game, x, y, game->map[x][y]);
			y++;
		}
		x++;
	}
	close(game->fd);
}
