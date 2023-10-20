# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arincon <arincon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2023/10/20 13:17:42 by arincon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:= minishell

#DIRECTORIES_________________________________________________________

LIBS		:=	ft gnl
LIBS_TARGET	:=							\
				lib/libft/libft.a		\
				lib/libgnl/libgnl.a

INCS		:=	include					\
				lib/libft/include		\
				lib/libgnl/include

#SOURCES______________________________________________________________

SRC_DIR		:= src
SRCS		:=	main.c							\
				builtins/builtins_cd.c			\
				builtins/builtins_echo.c		\
				builtins/builtins_env.c			\
				builtins/builtins_exit.c		\
				builtins/builtins_export.c		\
				builtins/builtins_pwd.c			\
				builtins/builtins_unset.c		\
				builtins/builtins.c				\
				env/env_exec.c					\
				env/env_utils.c					\
				env/env.c						\
				execute/execute_utils.c			\
				execute/execute.c				\
				execute/pipex.c					\
				execute/pipex_open.c			\
				execute/pipex_utils.c			\
				execute/here_doc.c				\
				execute/link.c					\
				parser/expansion_utils.c		\
				parser/expansion_var.c			\
				parser/parser_error.c			\
				parser/parser_quote.c			\
				parser/parser_var.c				\
				parser/parser_var_utils.c		\
				parser/parser.c					\
				lexer/lexer.c					\
				lexer/lexer_utils.c				\
				utils/free.c					\
				utils/init.c					\
				utils/signal.c					\
				utils/status.c					\
				utils/utils.c					\
				utils/utils2.c					\

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

#OBJECT______________________________________________________________

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

#FLAGS_______________________________________________________________

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l,$(LIBS))
READ		:= -lreadline
RM			:= rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP		= mkdir -p $(@D)

#COLORS______________________________________________________________

GREEN	=	\033[0;32m
RED		=	\033[0;31m
WHITE	=	\033[0;97m
RESET	=	\033[0m
YELLOW 	=	\033[0;93m

#MAIN_RULE___________________________________________________________

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	@echo -n "$(YELLOW)Compiling	${WHITE}→	$(YELLOW)$(NAME)$(RESET) "
	@echo "$(GREEN)[ok]✓$(RESET)"
	@$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) $(READ) -o $(NAME)
#	$(info CREATED $(NAME))

#OBJECT_RULE_________________________________________________________

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
#	$(info CREATED $@)

#LIBFT_RULE__________________________________________________________

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

#CLEAN_RULE__________________________________________________________

clean:
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) object$(RESET) "
	$(RM) $(OBJS)
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done

fclean: clean
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) executable$(RESET) "
	$(RM) $(NAME)
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done

re: fclean all

#SPEC_______________________________________________________________

.PHONY: clean fclean re
.SILENT:

