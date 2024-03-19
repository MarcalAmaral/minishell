/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:09:51 by myokogaw          #+#    #+#             */
/*   Updated: 2024/03/07 18:09:51 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_dlist(t_dlist **head)
{
	t_dlist	*node;

	if (head == NULL)
		return ;
	if (!*head)
		return ;
	node = *head;
	while (node)
	{
		printf("%s\n", (char *) node->content);
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	return ;
}
