/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destructor_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:19:17 by myokogaw          #+#    #+#             */
/*   Updated: 2024/03/19 18:19:17 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_destructor_struct(t_dlist **struct_to_clean)
{
	t_dlist	*struct_bit;

	if (!*struct_to_clean)
		return ;
	struct_bit = *struct_to_clean;
	while (struct_bit)
	{
		if (struct_bit->content != NULL)
			free(struct_bit->content);
		if (struct_bit->next == NULL)
			break ;
		struct_bit = struct_bit->next;
	}
	return ;
}
