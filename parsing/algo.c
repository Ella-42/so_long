/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:29:24 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/06 13:30:06 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	getpos(t_map *map, t_pos *pos, char c)
{
	map->y = 0;
	while (map->arr[map->y] != NULL)
	{
		map->x = 0;
		while (map->arr[map->y][map->x])
		{
			if (map->arr[map->y][map->x] == c)
			{
				pos->c = map->arr[map->y][map->x];
				pos->y = map->y;
				pos->x = map->x;
			}
			map->x++;
		}
		map->y++;
	}
}

void	test(t_map *map, t_pos *pos)
{
	while (pos->y < map->count - 1)
	{
		ft_printf("c:%c, y:%i, x:%i\n", map->arr[pos->y][pos->x],
			pos->y, pos->x);
		pos->y++;
	}
}

void	testing(t_map *map)
{
	t_pos	pos;

	getpos(map, &pos, 'P');
	test(map, &pos);
}
