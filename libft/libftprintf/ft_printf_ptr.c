/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:31:03 by lpeeters          #+#    #+#             */
/*   Updated: 2023/05/05 17:22:38 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	len_ptr(uintptr_t nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_put_ptr(nb / 16);
		ft_put_ptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar((nb + '0'));
		else
			ft_putchar((nb - 10 + 'a'));
	}
}

int	ft_putptr(uintptr_t ptr)
{
	int	char_printed;

	char_printed = 0;
	if (ptr == 0)
		char_printed += write(1, "(nil)", 5);
	else
	{
		char_printed += write(1, "0x", 2);
		ft_put_ptr(ptr);
		char_printed += len_ptr(ptr);
	}
	return (char_printed);
}
