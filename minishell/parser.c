//
//  parser.c
//  minishell
//
//  Created by Teghjyot Singh on 6/8/2024.
//

#include "minishell.h"

void	parse(t_tokenlist *tokenlist, t_command *cmd) {
	int	i;
	
	if (tokenlist->count > 0) {
		cmd->command = tokenlist->tokens[0];
		i = 0;
		while (i < tokenlist->count) {
			cmd->args[i - 1] = tokenlist->tokens[i];
			i++;
		}
		cmd->arg_count = tokenlist->count - 1;
	}
}
