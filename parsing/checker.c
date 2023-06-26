/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:35:04 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/26 19:29:39 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//check if argument is of the correct filetype
void	check_filetype(char *str)
{
	char	**suffix;
	int		conditional;
	int		i;

	conditional = FALSE;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] != '\0' && i > 0)
			conditional = TRUE;
		i++;
	}
	if (conditional == TRUE)
	{
		suffix = ft_split(str, '.');
		if (ft_strncmp(suffix[1], "ber", 3) || ft_strlen(suffix[1]) != 3)
			conditional = FALSE;
		free_arr(suffix);
	}
	if (conditional == FALSE)
		error_handler(NULL, BER, ERROR);
}

//calculate the length of a map
int	maplen(char	*str)
{
	char	*line;
	int		fd;
	int		count;

	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	count = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			count ++;
	}
	close(fd);
	return (count);
}

//print the map
void	printmap(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
		ft_printf("test: %s", map[i++]);
}

//convert map to array
char	**maptoarr(char *str)
{
	char	*line;
	char	**map;
	int		fd;
	int		count;
	int		i;

	count = maplen(str);
	map = (char **)malloc(sizeof(char *) * (count + 1));
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (line != NULL)
			map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	printmap(map);
	return (map);
}
