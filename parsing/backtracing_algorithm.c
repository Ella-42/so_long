/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracing_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:29:24 by lpeeters          #+#    #+#             */
/*   Updated: 2023/08/01 20:05:58 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//fetch the position of a character
int	getcpos(t_map *map, char c)
{
	map->y = 0;
	while (map->arr[map->y++] != NULL)
	{
		map->x = 0;
		while (map->arr[map->y][map->x] != '\0')
		{
			if (map->arr[map->y][map->x] == c)
				return (1);
			map->x++;
		}
	}
	return (0);
}

//move to a given direction and store it in the singly linked list
void	case_handler(t_map *map, t_bt **bt, int arrow)
{
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
	addmv(bt, map->prev);
}

//trace steps back untill point of intrest
void	backtracer(t_bt **bt, t_map *m)
{
	t_bt	*curr;

	curr = *bt;
	while ((m->arr[m->y - 1][m->x] == '1' || m->arr[m->y - 1][m->x] == '2') &&
		(m->arr[m->y][m->x - 1] == '1' || m->arr[m->y][m->x - 1] == '2') &&
		(m->arr[m->y + 1][m->x] == '1' || m->arr[m->y + 1][m->x] == '2') &&
		(m->arr[m->y][m->x + 1] == '1' || m->arr[m->y][m->x + 1] == '2'))
	{
		if (curr->mv == UP)
			m->y++;
		else if (curr->mv == LEFT)
			m->x++;
		else if (curr->mv == DOWN)
			m->y--;
		else if (curr->mv == RIGHT)
			m->x--;
		if (curr->next != NULL)
			free_sll(*bt, &curr, CURR);
		else
		{
			free(curr);
			error_handler(NULL, MAP, ERROR, m);
		}
	}
	*bt = curr;
}

//master algorithm
void	bt_algo(t_map *map)
{
	t_bt	*bt;

	bt = NULL;
	getcpos(map, 'P');
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
	free_sll(bt, NULL, BT);
}
