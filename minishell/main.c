//
//  main.c
//  minishell
//
//  Created by Teghjyot Singh on 5/8/2024.
//

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <stdbool.h>

void	handle_signal(int signal) {
	printf("Received signal %d\n", signal);
}

void	ignore_signal(void)
{
	struct sigaction	sa;
	sigset_t			mask;
	
	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGTSTP);
	sigaddset(&mask, SIGQUIT);
	sa.sa_handler = handle_signal;
	sa.sa_mask = mask;
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTSTP, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	handle_exit(void)
{
	char *input;

	input = readline("Type 'exit' to quit: ");
	if (input != NULL && strncmp(input, "exit", 4) == 0) {
		free(input);
		exit(0);
	}
	add_history(input);
	free(input);
}

int	main(int argc, const char * argv[]) {
	ignore_signal();
	while (true)
	{
		handle_exit();
	}
	return (0);
}

// TODO: lexer -> parser -> expander -> executor
