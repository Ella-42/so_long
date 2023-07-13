/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:02:21 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/13 18:22:34 by lpeeters         ###   ########.fr       */
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

//trace steps back untill point of intrest
void	backtracer(t_bt **bt, t_map *m)
{
	t_bt	*curr;

	ft_printf("\n\n----------START OF BACKTRACER----------\n\n");
	curr = *bt;
	while ((m->arr[m->y - 1][m->x] == '1' || m->arr[m->y - 1][m->x] == '2') &&
		(m->arr[m->y][m->x - 1] == '1' || m->arr[m->y][m->x - 1] == '2') &&
		(m->arr[m->y + 1][m->x] == '1' || m->arr[m->y + 1][m->x] == '2') &&
		(m->arr[m->y][m->x + 1] == '1' || m->arr[m->y][m->x + 1] == '2'))
	{
		if (curr->mv == UP)
		{
			ft_printf("\nGOING DOWN\n");
			m->y++;
		}
		else if (curr->mv == LEFT)
		{
			ft_printf("\nGOING RIGHT\n");
			m->x++;
		}
		else if (curr->mv == DOWN)
		{
			ft_printf("\nGOING UP\n");
			m->y--;
		}
		else if (curr->mv == RIGHT)
		{
			ft_printf("\nGOING LEFT\n");
			m->x--;
		}
		if (curr->next != NULL)
			curr = curr->next;
		print_dll(curr);
		print_map(m);
		ft_printf("c:%c, y:%i, x:%i\n", m->arr[m->y][m->x],
			m->y, m->x);
	}
	*bt = curr;
	ft_printf("\n\n----------END OF BACKTRACER----------\n\n");
}
