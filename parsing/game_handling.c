/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:39:23 by lpeeters          #+#    #+#             */
/*   Updated: 2023/08/07 21:59:13 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//ending handler
void	ending(t_map *map)
{
	ft_printf("You caught ");
	if (map->cccoll == 1)
		ft_printf("a Rattata!\n\n");
	else if (map->cccoll == 2)
		ft_printf("a Pidgey!\n\n");
	else if (map->cccoll == 3)
		ft_printf("a Bidoof!\n\n");
	else if (map->cccoll > 3 && map->cccoll < 6)
		ft_printf("a Bellsprout, nice!\n\n");
	else if (map->cccoll > 5 && map->cccoll < 8)
		ft_printf("a Marill, nice!\n\n");
	else if (map->cccoll > 7 && map->cccoll < 11)
		ft_printf("a Geodude, wow!\n\n");
	else if (map->cccoll > 10 && map->cccoll < 14)
		ft_printf("a Machop, wow!\n\n");
	else if (map->cccoll > 13 && map->cccoll < 19)
		ft_printf("an Abra, fantastic!\n\n");
	else if (map->cccoll > 18 && map->cccoll < 24)
		ft_printf("a Dratini, fantastic!\n\n");
	else if (map->cccoll > 25 && map->cccoll < 51)
		ft_printf("Regirock , damn!!\n\n");
	else if (map->cccoll > 50 && map->cccoll < 101)
		ft_printf("Zapdos , damn!!\n\n");
	else if (map->cccoll > 100)
		ft_printf("Rayquaza, holy shit!!!\n\n");
}

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
			{
				if (map->ccoll < 2)
					ft_printf("You appear to have missed a Pokeball\n\n");
				else
					ft_printf("You will need %i more Pokeballs\n\n", map->ccoll);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

//update an image to the window
void	upd_win(t_mlx *mlx, t_map *map, char c)
{
	if (c == 'C')
	{
		map->arr[map->y][map->x] = '2';
		map->ccoll--;
		if (map->ccoll == 1)
			ft_printf("You need to collect %i more Pokeball\n\n", map->ccoll);
		else if (map->ccoll == 0)
			ft_printf("Let's do this!\n\n");
		else
			ft_printf("You need to collect %i more Pokeballs\n\n", map->ccoll);
	}
	else if (c == 'E')
	{
		map->arr[map->y][map->x] = '3';
		if (checkc(map))
		{
			ending(map);
			ft_printf("Beat map with %i steps taken, good job!\n\n", map->count);
			close_window(mlx, SUCCESS);
		}
		else
			ft_printf("You are not yet ready for battle...\n\n");
	}
}

//STEP: count how many steps were taken and display them
//PRINT_LEGEND: print out all the keymappings
//The norm is to be thanked for this one :)
void	step_or_print_legend(t_map *map, int function)
{
	if (function == STEP)
	{
		map->count++;
		if (map->count == 0)
			ft_printf("You have yet to take a step\n\n");
		else if (map->count == 1)
			ft_printf("You have taken %i step\n\n", map->count);
		else
			ft_printf("You have taken %i steps\n\n", map->count);
	}
	else if (function == PRINT_LEGEND)
	{
		ft_printf("     ==========LEGEND==========     \n\n");
		ft_printf("up = w or up arrow (move the player up)\n");
		ft_printf("left = a or left arrow (move the player left)\n");
		ft_printf("down = s or down arrow (move the player down)\n");
		ft_printf("right = d or right arrow (move the player right)\n");
		ft_printf("map = m (print the map to the terminal)\n");
		ft_printf("close = escape (shut down the game)\n");
		ft_printf("legend = spacebar (print this screen again)\n\n");
	}
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
	step_or_print_legend(map, STEP);
	if (map->arr[map->y][map->x] == 'C')
		upd_win(mlx, map, 'C');
	else if (map->arr[map->y][map->x] == 'E')
		upd_win(mlx, map, 'E');
	else
		map->arr[map->y][map->x] = 'P';
	map2win(mlx, map);
}
