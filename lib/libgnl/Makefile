# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arincon <arincon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 14:30:36 by arincon           #+#    #+#              #
#    Updated: 2023/10/20 13:12:38 by arincon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:= libgnl.a

#---------------------------------------------------#
#	INGREDIENTS										#
#---------------------------------------------------#
# SRC_DIR	source directory
# SRCS		source files
#
# BUILD_DIR	object directory
# OBJS		object files
# DEPS		dependency files
#
# CC		compiler
# CFLAGS	compiler flags
# CPPFLAGS	preprocessor flags

SRC_DIR		:= src
SRCS		:=		\
	get_next_line.c \
	get_next_line_utils.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -MMD -MP -I include
# -I <include_dir> allows you to no longer have to write the full path of a header
# -MP prevents errors if a header file has been deleted or renamed.
# -MDD automatically generate a list of dependencies

AR			:= ar
# creates a static library
ARFLAGS		:= -r -c -s
# r replace old object with new one
# c create the library if it doesnt exist
# s write an index into the archive or update an existing one

#---------------------------------------------------#
#	UTENSILS										#
#---------------------------------------------------#
# RM		force remove
# DIR_DUP	duplicate directory tree

RM			:= rm -f

MAKEFLAGS   += --no-print-directory
# clearer output

DIR_DUP		= mkdir -p $(@D)
# $(@D) directory part of the file name of the target

#---------------------------------------------------#
#	RECIPES											#
#---------------------------------------------------#
# all		default goal
# $(NAME)	link .o -> library
# %.o		compilation .c -> .o
# clean		remove .o
# fclean	remove .o + binary
# re		remake default goal

# target: prerequisite
#	recipe line 1
#	recipe line 2
#	…

#COLORS______________________________________________________________

GREEN	=	\033[0;32m
RED		=	\033[0;31m
WHITE	=	\033[0;97m
RESET	=	\033[0m
YELLOW 	=	\033[0;93m

all: $(NAME)

$(NAME): $(OBJS)
	@echo -n "$(YELLOW)Compiling	${WHITE}→	$(YELLOW)$(NAME)$(RESET) "
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(GREEN)[ok]✓$(RESET)"
#	$(info CREATED $(NAME))
# info is like echo, echo works only inside a recipe, info anywhere

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
#	$(info CREATED $@)
# $@ = current target | $^ = all prerequisites | $< leftmost prerequisites

-include $(DEPS)

clean:
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) object$(RESET) "
	$(RM) $(OBJS) $(DEPS)
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"
# mostlyclean: (More GNU conventional)

fclean:
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) executable$(RESET) "
	$(RM) $(NAME)
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"
# clean: (More GNU conventional)

re:
	$(MAKE) clean
	$(MAKE) fclean
	$(MAKE) all
# external call, don't rely on re: fclean all

#---------------------------------------------------#
#	SPEC											#
#---------------------------------------------------#

.PHONY: clean fclean re

.SILENT:
#silences the rules output specified as prerequisites
