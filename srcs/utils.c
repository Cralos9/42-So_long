/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:13:12 by cacarval          #+#    #+#             */
/*   Updated: 2023/06/13 13:59:13 by cacarval         ###   ########.fr       */
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