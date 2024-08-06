//
//  minishell.h
//  minishell
//
//  Created by Teghjyot Singh on 6/8/2024.
//

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <stdbool.h>

typedef struct s_tokenlist {
	char	*tokens[100];
	int		count;
}	t_tokenlist;

typedef struct s_command {
	char	*command;
	char	*args[100];
	int		arg_count;
}	t_command;

void	tokenise(char *input, t_tokenlist *tokenlist);
void	parse(t_tokenlist *tokenlist, t_command *cmd);
void	expand(t_command *cmd);
void	execute(t_command *cmd);
void	ignore_signal(void);

#endif /* MINISHELL_H */
