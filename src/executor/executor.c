/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:47:39 by myokogaw          #+#    #+#             */
/*   Updated: 2024/03/06 02:47:39 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    executor(char **args)
{

}


int	execute(char *path, char **cmds, char **envp)
{
	if (execve(path, cmds, envp) == -1)
	{
		free(path);
		ft_free_matrix((void **) cmds);
		perror("Error\n- Execve: ");
		return (1);
	}
	else
		return (0);
}
