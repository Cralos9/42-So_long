/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:49:43 by cacarval          #+#    #+#             */
/*   Updated: 2023/07/14 11:33:00 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	coin_animation(t_game *game)
{
	int			y;
	int			x;
	static int	i = 0;
	int			coin[2];

	coin[0] = Coin;
	coin[1] = Coin2;
	if (i == 2)
		i = 0;
	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->columns)
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->sp[coin[i]].img, game->sp[coin[i]].width * x, \
				game->sp[coin[i]].height * y);
	}
	i++;
}

void	pick_move(t_game *game, int y, int x)
{
	int		random;
	t_pos	pos;

	random = rand() % 4;
	pos.x = x;
	pos.y = y;
	game->e = pos;
	if (random == 0 && (game->map[y + 1][x] == '0' \
		|| game->map[y + 1][x] == 'P'))
		game->e.y += 1;
	else if (random == 1 && (game->map[y - 1][x] == '0' \
		|| game->map[y - 1][x] == 'P'))
		game->e.y -= 1;
	else if (random == 2 && (game->map[y][x + 1] == '0' \
		|| game->map[y][x + 1] == 'P'))
		game->e.x += 1;
	else if (random == 3 && (game->map[y][x - 1] == '0' \
		|| game->map[y][x - 1] == 'P'))
		game->e.x -= 1;
}

void	update_enemy_positions(t_game *game, t_pos *enemy_pos, int numenemies)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	while (++i < numenemies)
	{
		x = enemy_pos[i].x;
		y = enemy_pos[i].y;
		pick_move(game, y, x);
		game->map[y][x] = '0';
		if (game->map[game->e.y][game->e.x] == 'P')
		{
			ft_printf("You lost :(\n");
			free(enemy_pos);
			check_key(ESC, game);
		}
		else
		{
			game->map[game->e.y][game->e.x] = 'M';
			ft_put_sprites(game, y, x, '0');
			ft_put_sprites(game, game->e.y, game->e.x, 'M');
		}
	}
}

void	monster_position(t_game *game)
{
	int		y;
	int		x;
	t_pos	*enemy_pos;
	int		numenemies;

	numenemies = 0;
	enemy_pos = malloc(game->num_monsters * sizeof(t_pos));
	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->columns)
		{
			if (game->map[y][x] == 'M')
			{
				enemy_pos[numenemies].x = x;
				enemy_pos[numenemies].y = y;
				numenemies++;
			}
		}
	}
	update_enemy_positions(game, enemy_pos, numenemies);
	free(enemy_pos);
}
