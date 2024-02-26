/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:06:39 by myokogaw          #+#    #+#             */
/*   Updated: 2024/02/23 18:06:39 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*ft_dlstlast(t_dlist *init)
{
	t_dlist *temp;

	temp = init;
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	return (temp);
}