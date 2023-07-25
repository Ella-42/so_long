/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:56:52 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/26 01:03:34 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// perror
#include <stdio.h>
/*
int	calc_arr_mem(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}
*/
char	**cpy_arr(char **arr)
{
	int		i;
	char	**cpy;

	if (cpy == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (arr[i] != NULL)
	{
		cpy[i] = ft_strdup(arr[i]);
		if (cpy[i] == NULL)
		{
			free_arr(cpy);
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
