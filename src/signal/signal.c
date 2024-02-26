/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:10:15 by myokogaw          #+#    #+#             */
/*   Updated: 2024/02/24 03:10:15 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sighandler(int);

void	receive_sig_int(int sig)
{
	(void) sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_signal(void)
{
	signal(SIGINT, receive_sig_int);
	signal(SIGQUIT, SIG_IGN);
}
