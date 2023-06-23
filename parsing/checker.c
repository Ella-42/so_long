/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:35:04 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/23 13:56:48 by lpeeters         ###   ########.fr       */
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

//check if map is correct
void	check_map(char	*str)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(str, O_RDONLY);
	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		ft_printf("test: %s", line);
		free(line);
		i++;
	}
	close(fd);
}
