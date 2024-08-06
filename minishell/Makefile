S = ./
O = obj/
I = ./
D = dep/

CFLAGS += -I$I

# ------------------------------------------------------------------------------
NAME = minishell
SRC = $Smain.c \
      $Slexer.c \
      $Sparser.c \
      $Sexpander.c \
      $Sexecutor.c \
      $Ssignal.c \

CC = gcc
CFLAGS += -Wall -Wextra -Werror
LDFLAGS += -lreadline
# ------------------------------------------------------------------------------

OBJ = $(SRC:$S%=$O%.o)
DEP = $(SRC:$S%=$D%.d)

RM = /bin/rm -f
RMDIR = /bin/rmdir

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%
	$(CC) $(CFLAGS) -c $< -o $@

$D:
	@mkdir $@

$(DEP): | $D

$(DEP): $D%.d: $S%
	$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

cleanobj:
	$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	$(RMDIR) $O

cleandep:
	$(RM) $(wildcard $(DEP))

cleandepdir: cleandep
	$(RMDIR) $D

clean: cleanobjdir cleandepdir

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEP)

$(OBJ): | $O
