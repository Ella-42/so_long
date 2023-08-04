/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:39:23 by lpeeters          #+#    #+#             */
/*   Updated: 2023/08/04 22:48:54 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//fetch the position of a character
int	checkc(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->arr[i] != NULL)
	{
		j = 0;
		while (map->arr[i][j] != '\0')
		{
			if (map->arr[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//print out all the keymappings
void	print_legend(void)
{
	ft_printf("\n     ==========LEGEND==========     \n\n");
	ft_printf("up = w or up arrow (move the player up)\n");
	ft_printf("left = a or left arrow (move the player left)\n");
	ft_printf("down = s or down arrow (move the player down)\n");
	ft_printf("right = d or right arrow (move the player right)\n");
	ft_printf("map = m (print the map to the terminal)\n");
	ft_printf("close = escape (shut down the game)\n");
	ft_printf("legend = spacebar (print this screen again)\n\n");
}

//update an image to the window
void	upd_win(t_mlx *mlx, t_map *map, char c)
{
	if (c == 'C')
	{
		map->arr[map->y][map->x] = '2';
		map->ccoll--;
		if (map->ccoll == 1)
			ft_printf("You need to collect %i more Pokeball\n", map->ccoll);
		else if (map->ccoll == 0)
			ft_printf("Let's do this!\n");
		else
			ft_printf("You need to collect %i more Pokeballs\n", map->ccoll);
	}
	else if (c == 'E')
	{
		map->arr[map->y][map->x] = '3';
		if (checkc(map))
		{
			ft_printf("Beat map with %i steps taken, good job!\n",
				map->count);
			close_window(mlx, SUCCESS);
		}
		else
			ft_printf("You are not yet ready for battle...\n");
	}
}

//count how many steps were taken and display them
void	step(t_map *map)
{
	map->count++;
	if (map->count == 0)
		ft_printf("You have yet to take a step\n");
	else if (map->count == 1)
		ft_printf("You have taken %i step\n", map->count);
	else
		ft_printf("You have taken %i steps\n", map->count);
}

//move the player
void	move(t_mlx *mlx, t_map *map, int keycode)
{
	if (map->arr[map->y][map->x] == '3')
		map->arr[map->y][map->x] = 'E';
	else if (map->arr[map->y][map->x] != 'E')
		map->arr[map->y][map->x] = '0';
	if (keycode == UP && map->arr[map->y - 1][map->x] != '1')
		map->y--;
	else if (keycode == DOWN && map->arr[map->y + 1][map->x] != '1')
		map->y++;
	else if (keycode == LEFT && map->arr[map->y][map->x - 1] != '1')
		map->x--;
	else if (keycode == RIGHT && map->arr[map->y][map->x + 1] != '1')
		map->x++;
	else
		map->count--;
	step(map);
	if (map->arr[map->y][map->x] == 'C')
		upd_win(mlx, map, 'C');
	else if (map->arr[map->y][map->x] == 'E')
		upd_win(mlx, map, 'E');
	else
		map->arr[map->y][map->x] = 'P';
	map2win(mlx, map);
}
