/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:15:02 by myokogaw          #+#    #+#             */
/*   Updated: 2024/03/08 18:15:02 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int processing_input(char *input)
{
	int i;
	int fd;

	i = 0;
	fd = open("preprocessing_input", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (1);
	while (input[i])
	{
		if (input[i] == ' ')
		{
			write(fd, "\n", 1);
			while (input[i] == ' ')
				i++;
		}
		if (input[i] == '\'')
		{
			i++;
			while (input[i] != '\'')
				i += write(fd, &input[i], 1);
			write(fd, "\n", 1);
			i++;
		}
		if (input[i] != 0)
			i += write(fd, &input[i], 1);
	}
	return (0);
}

int	main(void)
{
	return (processing_input("echo 'hello world'"));
}