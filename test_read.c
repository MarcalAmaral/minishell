#include "minishell.h"

int main(void)
{
    int fd;
    char *any_word;
    
    any_word = ft_strdup("Bulufas");
    fd = open("any_file", O_RDWR | O_CREAT, 0744);
    perror("Error\n -");
    write(fd, any_word, ft_strlen(any_word));
    perror("Error\n -");
    lseek(fd, 0, SEEK_SET);
    char *input;
    int len = 0;
    input = ft_calloc(1, sizeof(char) * ft_strlen(any_word));
    len = read(fd, input, ft_strlen(any_word));
    perror("Error\n -");
    printf("bytes read = %d\n", len);
    input[len] = 0;
    printf("content of buffer after read: %s\n", input);
    return (0);
}

// int main(void)
// {
//     char *input;
//     char *pipeline;
//     char *temp;
//     int fd;

//     fd = open("_input", O_RDONLY);
//     if (fd == -1)
//         perror("Error\n -");
//     input = get_next_line(fd);
//     pipeline = ft_strdup(NULL);
//     while (input != NULL)
//     {
//         temp = pipeline; 
//         pipeline = ft_strjoin(pipeline, input);
//         free(input);
//         free(temp);
//         input = get_next_line(fd);
//     }
//     close(fd);
//     char **tokens;

//     tokens = ft_split(pipeline, '\n') ;
//     ft_print_matrix((void **) tokens);

//     t_dlist **list_tokens;
//     int i = 0;

//     list_tokens = (t_dlist **) ft_calloc(1, sizeof(t_dlist **)); 
//     while (tokens[i] != NULL)
//         ft_append_dlist(list_tokens, ft_newnode_dlist(tokens[i++]));
//     ft_print_dlist(list_tokens);
//     free(pipeline);
//     ft_free_matrix((void **) tokens);
//     ft_free_dlist(list_tokens);
//     return (0);
// }