/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:29:24 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/11 21:27:40 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//testing
void	print_map(t_map *map)
{
	int	x;

	ft_printf("\n");
	ft_printf("X ");
	x = 0;
	while (x <= map->count)
		ft_printf("%i", x++);
	ft_printf(" Y\n\n");
	map->i = 0;
	while (map->arr[map->i] != NULL)
	{
		ft_printf("  %s %i\n", map->arr[map->i], map->i);
		map->i++;
	}
	ft_printf("\n");
}

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
void	case_handler(t_map *map, int arrow)
{
	map->arr[map->y][map->x] = '2';
	if (arrow == UP)
	{
		map->y--;
		map->prev = UP;
	}
	else if (arrow == LEFT)
	{
		map->x--;
		map->prev = LEFT;
	}
	else if (arrow == DOWN)
	{
		map->y++;
		map->prev = DOWN;
	}
	else if (arrow == RIGHT)
	{
		map->x++;
		map->prev = RIGHT;
	}
	if (map->arr[map->y][map->x] == 'C')
		map->coll -= 1;
	else if (map->arr[map->y][map->x] == 'E')
		map->ext -= 1;
}

//logic handler
void	cases(t_map *map)
{
	map->prev = 0;
	while (map->coll > 0 || map->ext > 0)
	{
		if (map->arr[map->y - 1][map->x] != '1' && map->prev != DOWN
			&& map->arr[map->y - 1][map->x] != '2')
			case_handler(map, UP);
		else if (map->arr[map->y][map->x - 1] != '1' && map->prev != RIGHT
			&& map->arr[map->y][map->x - 1] != '2')
			case_handler(map, LEFT);
		else if (map->arr[map->y + 1][map->x] != '1' && map->prev != UP
			&& map->arr[map->y + 1][map->x] != '2')
			case_handler(map, DOWN);
		else if (map->arr[map->y][map->x + 1] != '1' && map->prev != LEFT
			&& map->arr[map->y][map->x + 1] != '2')
			case_handler(map, RIGHT);
		else
			ft_printf("test\n");
		mkdll(map->prev);
		print_map(map);
		ft_printf("c:%c, y:%i, x:%i\n", map->arr[map->y][map->x],
			map->y, map->x);
	}
}

//testing
void	testing(t_map *map)
{
	getpos(map, 'P');
	ft_printf("c:%c, y:%i, x:%i\n", map->arr[map->y][map->x],
		map->y, map->x);
	cases(map);
	print_map(map);
}
