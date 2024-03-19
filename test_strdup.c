#include "minishell.h"

int main(void)
{
    char *test;

    test = ft_strdup("hello world!");
    free(test);
    return (0);
}