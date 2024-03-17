/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:22:58 by myokogaw          #+#    #+#             */
/*   Updated: 2024/03/06 02:22:58 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_matrix(void **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		printf("%s\n", (char *) matrix[i]);
		i++;
	}
	printf("\n");
	return ;
}
