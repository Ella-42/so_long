/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:29:24 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/13 18:22:26 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//fetch the position of a character
void	getpos(t_map *map, char c)
{
	ft_printf("\n");
	map->y = 0;
	while (map->arr[map->y++] != NULL)
	{
		map->x = 0;
		while (map->arr[map->y][map->x] != '\0')
		{
			if (map->arr[map->y][map->x] == c)
				return ;
			map->x++;
		}
	}
}

//case handling
void	case_handler(t_map *map, t_bt **bt, int arrow)
{
	ft_printf("\n\n----------START OF CASE_HANDLER----------\n\n");
	if (arrow == UP)
	{
		map->y--;
		ft_printf("\nGOING UP\n");
		map->prev = UP;
	}
	else if (arrow == LEFT)
	{
		map->x--;
		ft_printf("\nGOING LEFT\n");
		map->prev = LEFT;
	}
	else if (arrow == DOWN)
	{
		map->y++;
		ft_printf("\nGOING DOWN\n");
		map->prev = DOWN;
	}
	else if (arrow == RIGHT)
	{
		map->x++;
		ft_printf("\nGOING RIGHT\n");
		map->prev = RIGHT;
	}
	if (map->arr[map->y][map->x] == 'C')
		map->coll -= 1;
	else if (map->arr[map->y][map->x] == 'E')
		map->ext -= 1;
	addmv(bt, map->prev);
	print_dll(*bt);
	print_map(map);
	ft_printf("c:%c, y:%i, x:%i\n", map->arr[map->y][map->x],
		map->y, map->x);
	ft_printf("\n\n----------START OF CASE_HANDLER----------\n\n");
}

//logic handler
void	cases(t_map *map, t_bt *bt)
{
	map->prev = 0;
	addmv(&bt, map->prev);
	while (map->coll > 0 || map->ext > 0)
	{
		map->arr[map->y][map->x] = '2';
		if (map->arr[map->y - 1][map->x] != '1' && bt->mv != DOWN
			&& map->arr[map->y - 1][map->x] != '2')
			case_handler(map, &bt, UP);
		else if (map->arr[map->y][map->x - 1] != '1' && bt->mv != RIGHT
			&& map->arr[map->y][map->x - 1] != '2')
			case_handler(map, &bt, LEFT);
		else if (map->arr[map->y + 1][map->x] != '1' && bt->mv != UP
			&& map->arr[map->y + 1][map->x] != '2')
			case_handler(map, &bt, DOWN);
		else if (map->arr[map->y][map->x + 1] != '1' && bt->mv != LEFT
			&& map->arr[map->y][map->x + 1] != '2')
			case_handler(map, &bt, RIGHT);
		else
			backtracer(&bt, map);
	}
	ft_printf("\n\nYOU FUCKING DID IT, YOU CRAZY SON OF A BITCH!!!\n\n");
	free_dll(bt);
}

//testing
void	testing(t_map *map)
{
	t_bt	*bt;

	bt = NULL;
	getpos(map, 'P');
	ft_printf("c:%c, y:%i, x:%i\n", map->arr[map->y][map->x],
		map->y, map->x);
	cases(map, bt);
}
