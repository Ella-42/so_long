/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:35:04 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/18 22:34:25 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//check if argument is of the correct filetype
void	check_filetype(t_map *map)
{
	map->conditional = false;
	map->i = 0;
	while (map->str[map->i])
	{
		if (map->str[map->i] == '.'
			&& map->str[map->i + 1] != '\0' && map->i > 0)
			map->conditional = true;
		map->i++;
	}
	if (map->conditional == true)
	{
		map->suffix = ft_split(map->str, '.');
		if (ft_strncmp(map->suffix[1], "ber", 3)
			|| ft_strlen(map->suffix[1]) != 3)
			map->conditional = false;
		free_arr(map->suffix);
	}
	if (map->conditional == false)
		error_handler(NULL, BER, ERROR, NULL);
}

//calculate the length of a map and allocate memory for it
char	**maparr(t_map *map)
{
	map->fd = open(map->str, O_RDONLY);
	if (map->fd < 0)
		error_handler(NULL, OPEN, ERROR, NULL);
	map->line = get_next_line(map->fd);
	map->count = 0;
	while (map->line != NULL)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
		map->count++;
	}
	if (map->count < 3)
		error_handler(NULL, MAP, ERROR, NULL);
	close(map->fd);
	map->arr = (char **)malloc(sizeof(char *) * (map->count + 1));
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
	map->arr[map->i] = NULL;
	if (map->arr[0][0] == '\0')
		error_handler(NULL, MAP, ERROR, map->arr);
	if (map->conditional == false || ft_strlen(map->arr[0]) < 3)
		error_handler(NULL, MALLOC, ERROR, map->arr);
	return (map->arr);
}

//parse the elements in the map and check if they are correct
void	mapparser(t_map *m)
{
	m->play = 0;
	m->coll = 0;
	m->ext = 0;
	m->i = 0;
	while (m->arr[m->i] != NULL)
	{
		m->j = 0;
		while (m->arr[m->i][m->j] != '\0')
		{
			if (m->arr[m->i][m->j] == '0' || m->arr[m->i][m->j] == '1')
				;
			else if (m->arr[m->i][m->j] == 'P')
				m->play += 1;
			else if (m->arr[m->i][m->j] == 'C')
				m->coll += 1;
			else if (m->arr[m->i][m->j] == 'E')
				m->ext += 1;
			else
				error_handler(NULL, MAP, ERROR, m->arr);
			m->j++;
		}
		m->i++;
	}
	if (m->play != 1 || m->coll < 1 || m->ext != 1)
		error_handler(NULL, MAP, ERROR, m->arr);
}

//check if map is valid
void	checkmap(t_map *map)
{
	check_filetype(map);
	map->arr = maptoarr(map);
	map->j = 0;
	while (map->arr[0][map->j] && map->arr[map->count - 1][map->j])
		if (map->arr[0][map->j] != '1'
			|| map->arr[map->count - 1][map->j++] != '1')
			error_handler(NULL, MAP, ERROR, map->arr);
	map->i = 0;
	while (map->arr[map->i] != NULL)
	{
		if (map->arr[map->i][0] != '1' || map->arr[map->i][map->j - 1] != '1')
			error_handler(NULL, MAP, ERROR, map->arr);
		if (ft_strlen(map->arr[0]) != ft_strlen(map->arr[map->i]))
			error_handler(NULL, MAP, ERROR, map->arr);
		map->i++;
	}
	mapparser(map);
	bt_algo(map);
}
