/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode_dlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:02:51 by myokogaw          #+#    #+#             */
/*   Updated: 2024/02/23 18:02:51 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist *ft_newnode_dlist(void *content)
{
    t_dlist *new_node;

    new_node = (t_dlist *) ft_calloc(1, sizeof(t_dlist));
    new_node->content = content;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}