/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:48:00 by myokogaw          #+#    #+#             */
/*   Updated: 2024/02/26 18:48:00 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**classifying_tokens(char **tokens);

// Remove all whitespaces (any character which separes words) 
// metacharacter: A character that, when unquoted, separates words. A metacharacter is a space, tab, newline, or one of the following characters: ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, or ‘>’.
// operators:  It is a newline or one of the following: ‘||’, ‘&&’, ‘&’, ‘;’, ‘;;’, ‘;&’, ‘;;&’, ‘|’, ‘|&’, ‘(’, or ‘)’. And redirections;

// First scan check if we have an unquoted single ou double quoted;
// void	first_scan(char *input)
// {
// 	int i = 0;

	
// }

void	word_separator(t_dlist **lexemes, char *input)
{
	int i, j;

	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == ' ' || input[i] == '\t')
		{
			ft_append_dlist(lexemes, ft_newnode_dlist((void *) ft_substr(input, 0, i)));
			while (input[i] == ' ' || input[i] == '\t')
				i++;
		}
		if (input[i] == '\'')
		{
			i++;
			j = i;
			while (input[j] != '\'')
				j++;
			ft_append_dlist(lexemes, ft_newnode_dlist((void *) ft_substr(input, i, j - i)));
		}
		i++;
	}
	return ;
}

void    lexer(char *input)
{
	// char	**tokens;
	// char	**classified_tokens;
	t_dlist *lexemes;

	lexemes = (t_dlist *) ft_calloc(1, sizeof(t_dlist));
	word_separator(&lexemes, input);
	ft_print_dlist(&lexemes);


	// classified_tokens = classifying_tokens(tokens);
	// ft_print_matrix((void **) tokens);
	// ft_print_matrix((void **) classified_tokens);
	// ft_free_matrix((void **) tokens);
	// ft_free_matrix((void **) classified_tokens);
}

// First step, separeted all lexemes;

char	**classifying_tokens(char **tokens)
{
	int		i;
	char	**types_tokens;

	types_tokens = (char **) ft_calloc(ft_matrix_lenght((void **) tokens) + 1, sizeof(char *));
	i = 0;
	while (tokens[i])
	{
		if (tokens[i][0] == '-')
			types_tokens[i] = ft_strdup("OPTION");
		else
			types_tokens[i] = ft_strdup("LEXEMES");
		i++;
	}
	return (types_tokens);
}