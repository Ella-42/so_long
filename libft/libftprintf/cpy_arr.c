/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:56:52 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/31 14:40:06 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// perror
#include <stdio.h>

#include "../libft.h"

char	**cpy_arr(char **arr)
{
	int		i;
	char	**cpy;

	i = 0;
	while (arr[i] != NULL)
		i++;
	cpy = (char **)malloc(sizeof(char *) * (i + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		cpy[i] = ft_strdup(arr[i]);
		if (cpy[i++] == NULL)
		{
			free_arr(cpy);
			return (NULL);
		}
	}
	cpy[i] = NULL;
	return (cpy);
}
