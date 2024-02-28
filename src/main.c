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

// Testing readline function
// int main(void)
// {
//     char *str_readline;

//     str_readline = readline(NULL);
//     printf("content of readline: %s\n", str_readline);
//     free(str_readline);
//     return (0);
// }
void    parser_input(char *input);

// First step in Minishell; Read input from the user's terminal
void get_input(void)
{
	char *input;

	while (1)
	{
		input = readline("minishell: ");
		if (input == NULL)
			break ;
		printf("%s\n", input);
		lexer("Feijao doce com mochi");
		free(input);
		// parser_input(input);
	}
}


void	ft_print_matrix_str(char **matrix)
{
	int i = 0;

	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
	return ;
}

// Second step in Minishell; Breaks the input into words and operators;
// The input is parsed obeying the quoting rule and these tokens are separeted by metacharacters;
// metacharacter: A character that, when unquoted, separates words. A metacharacter is a space, tab, newline, or one of the following characters: ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, or ‘>’.
// operators:  It is a newline or one of the following: ‘||’, ‘&&’, ‘&’, ‘;’, ‘;;’, ‘;&’, ‘;;&’, ‘|’, ‘|&’, ‘(’, or ‘)’. And redirections;
void    parser_input(char *input)
{
	char	**matrix;
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')
		{
			if (input[i] == ' ')
				matrix = ft_split(input, ' ');
			else if (input[i] == '\n')
				matrix = ft_split(input, '\n');
			else
				matrix = ft_split(input, '\t');
			break ;
		}
		i++;
	}
	ft_print_matrix_str(matrix);
	return ;
}

// Test getcwd
int main(void)
{
	handle_signal();
	get_input();
	return (0);
}