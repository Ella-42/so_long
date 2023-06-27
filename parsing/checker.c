/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:35:04 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/27 19:21:37 by lpeeters         ###   ########.fr       */
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
		error_handler(NULL, BER, ERROR, NULL);
}

//calculate the length of a map
char	**maparr(char *str)
{
	char	*line;
	char	**map;
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
	map = (char **)malloc(sizeof(char *) * (count + 1));
	if (map == NULL)
		error_handler(NULL, MALLOC, ERROR, NULL);
	return (map);
}

//convert map to array
char	**maptoarr(char *str)
{
	char	*line;
	char	**map;
	int		fd;
	int		i;

	map = maparr(str);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_handler(NULL, OPEN, ERROR, map);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (line != NULL)
		{
			line[ft_strlen(line) - 1] = '\0';
			map[i] = ft_strdup(line);
		}
		if (map[i++] == NULL)
			error_handler(NULL, MALLOC, ERROR, map);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

//print the map
void	checkmap(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
	{
		if (ft_strlen(map[1]) != ft_strlen(map[i++]))
			error_handler(NULL, MAP, ERROR, map);
		ft_printf("%s line: %i\n", map[i - 1], i);
	}
}
