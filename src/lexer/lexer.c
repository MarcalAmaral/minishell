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

void	ft_printf_matrix(char **matrix);
void	ft_free_matrix(char **matrix);
char	**classifying_tokens(char **tokens);

void    lexer(char *input)
{
	char **tokens;
	char **classified_tokens;

	tokens = ft_split(input, ' ');
	classified_tokens = classifying_tokens(tokens);
	ft_printf_matrix(classified_tokens);
	ft_free_matrix(tokens);
	ft_free_matrix(classified_tokens);
}

void	ft_free_matrix(char **matrix)
{
	int i = 0;

	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return ;
}

void	ft_printf_matrix(char **matrix)
{
	int i = 0;

	while (matrix[i])
	{
		printf("%s	", matrix[i]);
		i++;
	}
	printf("\n");
	return ;
}

int		ft_matrix_lenght(char **matrix)
{
	int i = 0;

	while (matrix[i])
		i++;
	return (i);
}

char	**classifying_tokens(char **tokens)
{
	int i = 0;
	char **types_tokens = (char **) ft_calloc(ft_matrix_lenght(tokens) + 1, sizeof(char *));

	while (tokens[i])
	{
		if (tokens[i][0] == '-')
			types_tokens[i] = ft_strdup("OPTION");
		else
			types_tokens[i] = ft_strdup("WORD");
		i++;
	}
	return (types_tokens);
}