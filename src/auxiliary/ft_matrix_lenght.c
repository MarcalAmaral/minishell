/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_lenght.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:23:40 by myokogaw          #+#    #+#             */
/*   Updated: 2024/03/06 02:23:40 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_matrix_lenght(void **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
