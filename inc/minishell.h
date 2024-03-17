/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:42:43 by myokogaw          #+#    #+#             */
/*   Updated: 2024/02/23 16:42:43 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#ifdef __cplusplus
extern "C" {
#endif

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_dlist {
    void 			*content;
    struct s_dlist	*next;
    struct s_dlist	*prev;
}   t_dlist;

enum	e_token
{
	ARGUMENT = 1,
	PIPE,
	DOLLAR,
	AND,
	OR,
	L_PAREN,
	R_PAREN,
	QUOTE,
	DOUBLE_QUOTE,
	L_REDIR,
	HEREDOC,
	R_REDIR,
	APPEND,
	TOKEN_NULL,
	BLOCK,
	EXEC
};


// Auxiliary functions
void	ft_free_matrix(void **matrix);
void	ft_print_matrix(void **matrix);
void    ft_print_dlist(t_dlist **head);
int		ft_matrix_lenght(void **matrix);

// dlist procedures
void	ft_free_dlist(t_dlist **head);
void	ft_append_dlist(t_dlist **head, t_dlist *new_node);
t_dlist	*ft_dlstlast(t_dlist *init);
t_dlist	*ft_newnode_dlist(void *content);

// Builtins
void    pwd(void);

// Handle signal
void	handle_signal(void);

// Lexer
void    lexer(char *input);

#ifdef __cplusplus
} // extern "C"
#endif

# endif