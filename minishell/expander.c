//
//  expander.c
//  minishell
//
//  Created by Teghjyot Singh on 6/8/2024.
//

#include "minishell.h"

void	expand(t_command *cmd) {
	int	i;
	
	i = 0;
	while (i < cmd->arg_count) {
		if (cmd->args[i][0] == '$') {
			char *env = getenv(cmd->args[i] + 1);
			if (env) {
				free(cmd->args[i]);
				cmd->args[i] = strdup(env);
			}
		}
		i++;
	}
}
