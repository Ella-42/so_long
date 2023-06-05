/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:41:09 by lpeeters          #+#    #+#             */
/*   Updated: 2023/05/05 17:22:33 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*node;

	len = 0;
	node = lst;
	while (node != NULL)
	{
		len++;
		node = node->next;
	}
	return (len);
}
