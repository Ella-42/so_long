/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:02:21 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/15 01:27:57 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//free the memory of a singly linked list
void	free_sll(t_bt *bt, t_bt **current, int structure)
{
	t_bt	*curr;
	t_bt	*next;

	if (structure == BT)
	{
		curr = bt;
		while (curr != NULL)
		{
			next = curr->next;
			free(curr);
			curr = next;
		}
	}
	else if (structure == CURR)
	{
		next = (*current)->next;
		free(*current);
		*current = next;
	}
}

//initialize singly linked list
t_bt	*mksll(int move)
{
	t_bt	*bt;

	bt = (t_bt *)malloc(sizeof(t_bt));
	if (!bt)
		error_handler(NULL, MALLOC, ERROR, NULL);
	bt->mv = move;
	bt->next = NULL;
	return (bt);
}

//add values to the singly linked list
void	addmv(t_bt **bt, int move)
{
	t_bt	*new;

	new = mksll(move);
	if (*bt == NULL)
		*bt = new;
	else
	{
		new->next = *bt;
		*bt = new;
	}
}
