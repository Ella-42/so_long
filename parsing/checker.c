/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:35:04 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/28 19:02:31 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//check if argument is of the correct filetype
void	check_filetype(t_map *map)
{
	char	**suffix;

	map->conditional = true;
	map->i = 0;
	while (map->str[map->i])
	{
		if (map->str[map->i] == '.'
			&& map->str[map->i + 1] != '\0' && map->i > 0)
			map->conditional = true;
		map->i++;
	}
	if (map->conditional == false)
	{
		suffix = ft_split(map->str, '.');
		if (ft_strncmp(suffix[1], "ber", 3) || ft_strlen(suffix[1]) != 3)
			map->conditional = false;
		free_arr(suffix);
	}
	if (map->conditional == false)
		error_handler(NULL, BER, ERROR, NULL);
}

//calculate the length of a map and allocate memory for it
char	**maparr(t_map *map)
{
	int		count;

	map->fd = open(map->str, O_RDONLY);
	if (map->fd < 0)
		error_handler(NULL, OPEN, ERROR, NULL);
	map->line = get_next_line(map->fd);
	count = 0;
	while (map->line != NULL)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
		count++;
	}
	close(map->fd);
	map->arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (map->arr == NULL)
		error_handler(NULL, MALLOC, ERROR, NULL);
	return (map->arr);
}

//convert map to array
char	**maptoarr(t_map *map)
{
	map->arr = maparr(map);
	map->fd = open(map->str, O_RDONLY);
	if (map->fd < 0)
		error_handler(NULL, OPEN, ERROR, map->arr);
	map->line = get_next_line(map->fd);
	map->conditional = true;
	map->i = 0;
	while (map->line != NULL)
	{
		map->line[ft_strlen(map->line) - 1] = '\0';
		map->arr[map->i] = ft_strdup(map->line);
		free(map->line);
		if (map->arr[map->i++] == NULL)
			map->conditional = false;
		map->line = get_next_line(map->fd);
	}
	close(map->fd);
	if (map->conditional == false)
		error_handler(NULL, MALLOC, ERROR, map->arr);
	map->arr[map->i] = NULL;
	return (map->arr);
}

//print the map
void	checkmap(t_map *map)
{
	map->i = 0;
	while (map->arr[map->i] != NULL)
	{
		if (ft_strlen(map->arr[0]) != ft_strlen(map->arr[map->i++]))
			error_handler(NULL, MAP, ERROR, map->arr);
		ft_printf("%s line: %i\n", map->arr[map->i - 1], map->i);
	}
}
