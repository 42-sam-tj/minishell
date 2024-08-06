//
//  signal.c
//  minishell
//
//  Created by Teghjyot Singh on 6/8/2024.
//

#include "minishell.h"

static void	handle_signal(int signal) {
	printf("Received signal %d\n\n", signal);
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
