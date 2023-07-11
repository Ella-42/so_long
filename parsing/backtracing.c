/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:02:21 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/11 22:51:13 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//print a linked list's values
void	print_dll(t_bt *bt)
{
	t_bt	*curr;

	ft_printf("\ncurrent saved moves:");
	curr = bt;
	while (curr != NULL)
	{
		ft_printf(" %i", curr->mv);
		curr = curr->next;
	}
	ft_printf("\n");
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
