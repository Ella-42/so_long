/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:29:24 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/07 15:11:50 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	getpos(t_map *map, t_pos *pos, char c)
{
	ft_printf("\n");
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
	t_pos	ppos;
	t_pos	epos;

	getpos(map, &ppos, 'P');
	test(map, &ppos);
	getpos(map, &epos, 'E');
	ft_printf("c:%c, y:%i, x:%i\n", map->arr[epos.y][epos.x],
		epos.y, epos.x);
}
