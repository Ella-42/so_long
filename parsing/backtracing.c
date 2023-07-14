/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:02:21 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/14 14:36:40 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//free the memory of a doubly linked list
void	free_dll(t_bt *bt)
{
	t_bt	*curr;
	t_bt	*next;

	curr = bt;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

//initialize doubly linked list
t_bt	*mkdll(int move)
{
	t_bt	*bt;

	bt = (t_bt *)malloc(sizeof(t_bt));
	if (!bt)
		error_handler(NULL, MALLOC, ERROR, NULL);
	bt->mv = move;
	bt->prev = NULL;
	bt->next = NULL;
	return (bt);
}

//add values to the doubly linked list
void	addmv(t_bt **bt, int move)
{
	t_bt	*new;

	new = mkdll(move);
	if (*bt == NULL)
		*bt = new;
	else
	{
		new->next = *bt;
		(*bt)->prev = new;
		*bt = new;
	}
}
