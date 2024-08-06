//
//  lexer.c
//  minishell
//
//  Created by Teghjyot Singh on 6/8/2024.
//

#include "minishell.h"

void	tokenise(char *input, t_tokenlist *tokenlist) {
	char *token;

	token = strtok(input, " ");
	while (token != NULL && tokenlist->count < 100)
	{
		tokenlist->tokens[tokenlist->count] = strdup(token);
		tokenlist->count++;
		token = strtok(NULL, " ");
	}
}
