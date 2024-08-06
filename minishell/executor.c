//
//  executor.c
//  minishell
//
//  Created by Teghjyot Singh on 6/8/2024.
//

#include "minishell.h"

static void	child_process(t_command *cmd) {
	char	*argv[100 + 1];
	
	argv[0] = cmd->command;
	for (int i = 0; i < cmd->arg_count; i++) {
		argv[i + 1] = cmd->args[i];
	}
	argv[cmd->arg_count + 1] = NULL;
	execvp(cmd->command, argv);
	perror("execvp");
	exit(1);
}

void	execute(t_command *cmd) {
	pid_t	pid;
	
	pid = fork();
	if (pid == 0)
		child_process(cmd);
	else if (pid > 0)
		wait(NULL);
	else
		perror("fork");
}
