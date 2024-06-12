/* ************************************************************************** */
/*                                                                            */  
/*                                                        :::      ::::::::   */  
/*   ft_show_tab.c                                      :+:      :+:    :+:   */  
/*                                                    +:+ +:+         +:+     */  
/*   By: nguasca <nguasca@student.42madrid.fr>      +#+  +:+       +#+        */  
/*                                                +#+#+#+#+#+   +#+           */  
/*   Created: 2024/06/11 12:07:37 by nguasca           #+#    #+#             */  
/*   Updated: 2024/06/11 12:07:37 by nguasca          ###   ########.fr       */  
/*                                                                            */  
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
