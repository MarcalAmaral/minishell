/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:25 by myokogaw          #+#    #+#             */
/*   Updated: 2024/02/23 16:43:25 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    parser_input(char *input);

// First step in Minishell; Read input from the user's terminal
void get_input(void)
{
	// char *input;

	lexer("echo 'feijao com arroz'");
	// while (1)
	// {
	 	// input = readline("minishell: ");
		// add_history(input);
		// if (input == NULL)
		// 	break ;
		// printf("%s\n", input);
		// free(input);
		// parser_input(input);
	// }
}

// Second step in Minishell; Breaks the input into words and operators;
// The input is parsed obeying the quoting rule and these tokens are separeted by metacharacters;
// metacharacter: A character that, when unquoted, separates words. A metacharacter is a space, tab, newline, or one of the following characters: ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, or ‘>’.
// operators:  It is a newline or one of the following: ‘||’, ‘&&’, ‘&’, ‘;’, ‘;;’, ‘;&’, ‘;;&’, ‘|’, ‘|&’, ‘(’, or ‘)’. And redirections;
// void    parser_input(char *input)
// {
// 	char	**matrix;
// 	int		i;

// 	i = 0;
// 	while (input[i])
// 	{
// 		if (input[i] == ' ' || input[i] == '|' || input[i] == '\t' || input[i] == '<' || input[i] == '>' || input[i] == '\'' || input[i] == '\"')
// 		{
// 			if (input[i] == ' ')
// 		}
// 		i++;
// 	}
// 	ft_print_matrix_str(matrix);
// 	return ;
// }

int main(void)
{
	handle_signal();
	get_input();
	return (0);
}