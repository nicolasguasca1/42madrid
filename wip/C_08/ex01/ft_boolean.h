/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguasca <nguasca@student.42madrid.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:07:37 by nguasca           #+#    #+#             */
/*   Updated: 2024/06/11 12:07:37 by nguasca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# define EVEN is_even

# include <unistd.h>

typedef int	t_bool;

# define TRUE		1
# define FALSE		0
# define SUCCESS	0

void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);

# define EVEN_MSG	"I have an even number of arguments.\n"
# define ODD_MSG	"I have an odd number of arguments.\n"

t_bool	is_even(int nbr)
{
	if (nbr % 2 == 0)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

#endif
