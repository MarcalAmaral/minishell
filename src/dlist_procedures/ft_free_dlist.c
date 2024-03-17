/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:13:12 by myokogaw          #+#    #+#             */
/*   Updated: 2024/03/07 18:13:12 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_dlist(t_dlist **head)
{
	t_dlist	*temp;
	t_dlist	*temp1;

	if (!*head)
	{
		free(head);
		return ;
	}
	temp = *head;
	while (temp)
	{
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
	free(head);
	return ;
}
