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

char	**generate_tokens(char *file);
t_dlist	**convert_matrix_tokens_in_dlist(char **matrix);

void	handling_single_quote(char *input);
void	handling_double_quote(char *input);

void	handling_single_quote(char *input)
{
	return ;
}

void	handling_double_quote(char *input)
{
	return ;
}

t_dlist	**processing_input(char *input)
{
	char	**tokens_matrix;
	t_dlist	**tokens;
	int		i;
	int		fd;

	i = 0;
	fd = open("_input", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		perror("Error\n -");
	while (input[i])
	{
		if (input[i] == ' ')
		{
			write(fd, "\n", 1);
			while (input[i] == ' ' && input[i] != 0)
				i++;
		}
		if (input[i] == '\'')
		{
			i++;
			while (input[i] != '\'' && input[i] != 0)
				i += write(fd, &input[i], 1);
			write(fd, "\n", 1);
			i++;
		}
		if (input[i] == '\"')
		{
			i++;
			while (input[i] != '\"' && input[i] != 0)
				i += write(fd, &input[i], 1);
			write(fd, "\n", 1);
			i++;
		}
		if (input[i] != 0 && input[i] != '\'' && input[i] != '\"')
			i += write(fd, &input[i], 1);
	}
	close(fd);
	tokens_matrix = generate_tokens("_input");
	tokens = convert_matrix_tokens_in_dlist(tokens_matrix);
	ft_free_matrix((void **) tokens_matrix);
	fd = unlink("_input");
	if (fd == -1)
		perror("Error\n	-");
	if (tokens == NULL)
		return (NULL);
	return (tokens);
}

char	**generate_tokens(char *file)
{
	char	**tokens;
	char	*input;
	char	*pipeline;
	char	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror("Error\n	-");
	input = get_next_line(fd);
	pipeline = ft_strdup(NULL);
	while (input != NULL)
	{
		temp = pipeline;
		pipeline = ft_strjoin(pipeline, input);
		free(input);
		free(temp);
		input = get_next_line(fd);
	}
	tokens = ft_split(pipeline, '\n');
	free(pipeline);
	close(fd);
	return (tokens);
}

t_dlist	**convert_matrix_tokens_in_dlist(char **matrix)
{
	t_dlist	**tokens;
	int		i;

	if (*matrix == NULL)
		return (NULL);
	i = 0;
	tokens = (t_dlist **) ft_calloc(1, sizeof(t_dlist **));
	while (matrix[i] != NULL)
		ft_append_dlist(tokens, ft_newnode_dlist(ft_strdup(matrix[i++])));
	return (tokens);
}

int	main(void)
{
	t_dlist	**tokens;

	tokens = processing_input("echo \"wd\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"");
	ft_print_dlist(tokens);
	ft_destructor_struct(tokens);
	ft_free_dlist(tokens);
	return (0);
}

// int	main(void)
// {
// 	int fd;
// 	int len;
// 	char *token;
// 	char *all_tokens;
// 	char input[BUFFER_SIZE];
// 	char **tokens;

// 	token = ft_calloc(1, sizeof(char *));
// 	processing_input("echo 'hello world'");
// 	fd = open("_input", O_RDONLY);
// 	len = read(fd, input, BUFFER_SIZE);
// 	if (len == -1)
// 		perror("Error\n	-");
// 	input[len] = 0;
// 	while (len != 0)
// 	{
// 		token = ft_strjoin(token, input);
// 		len = read(fd, input, BUFFER_SIZE);
// 		input[len] = 0;
// 	}
// 	tokens = ft_split(token, '\n');
// 	ft_print_matrix((void **) tokens);
// 	ft_free_matrix((void **) tokens);
// 	free(token);
// 	close(fd);
// 	return (0);
// }