/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:29:24 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/05 19:26:01 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	test1(t_map *map)
{
	map->y = 0;
	while (map->arr[map->y] != NULL)
	{
		map->x = 0;
		while (map->arr[map->y][map->x])
		{
			if (map->arr[map->y][map->x] == 'P' || map->arr[map->y][map->x]
				== 'C' || map->arr[map->y][map->x] == 'E')
				ft_printf("char:%c, y:%i, x:%i\n",
					map->arr[map->y][map->x], map->y, map->x);
			map->x++;
		}
		map->y++;
	}
}

void	test2(t_map *map)
{
	map->y = 1;
	map->x = 1;
	while (map->y < map->count - 1)
	{
		if (map->arr[map->y][map->x] == '1')
			printf("Error\n");
		map->y++;
	}
}

void	testing(t_map *map)
{
	test1(map);
	test2(map);
}
