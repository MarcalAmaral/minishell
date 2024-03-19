/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_dlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:04:44 by myokogaw          #+#    #+#             */
/*   Updated: 2024/02/23 18:04:44 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_append_dlist(t_dlist **head, t_dlist *new_node)
{
	t_dlist	*node;

	if (!new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	node = ft_dlstlast(*head);
	node->next = new_node;
	new_node->prev = node;
	return ;
}
