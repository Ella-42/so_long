/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:02:21 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/26 22:21:48 by lpeeters         ###   ########.fr       */
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

//print a linked list's values
void	print_sll(t_bt *bt)
{
	t_bt	*curr;

	ft_printf("\ncurrent saved moves:");
	curr = bt;
	while (curr != NULL)
	{
		if (curr->mv == UP)
			ft_printf(" UP");
		else if (curr->mv == LEFT)
			ft_printf(" LEFT");
		else if (curr->mv == DOWN)
			ft_printf(" DOWN");
		else if (curr->mv == RIGHT)
			ft_printf(" RIGHT");
		curr = curr->next;
	}
	ft_printf("\n");
}
