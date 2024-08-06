//
//  main.c
//  minishell
//
//  Created by Teghjyot Singh on 5/8/2024.
//

#include "minishell.h"

int	main(int argc, const char * argv[]) {
	t_command cmd;
	t_tokenlist tokenlist;

	(void)argc;
	(void)argv;
	ignore_signal();
	while (true)
	{
		char *input = readline("$PROMPT: ");
		if (input != NULL) {
			if (strcmp(input, "exit") == 0) {
				free(input);
				break;
			}
			add_history(input);
			tokenlist.count = 0;
			tokenise(input, &tokenlist);
			cmd.arg_count = 0;
			parse(&tokenlist, &cmd);
			expand(&cmd);
			execute(&cmd);
			for (int i = 0; i < tokenlist.count; i++) {
				free(tokenlist.tokens[i]);
			}
			free(input);
		}
	}
	return (0);
}

// TODO: lexer -> parser -> expander -> executor
