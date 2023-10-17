#! /usr/bin/bash

#valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all -s ./minishell
valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all --track-fds=yes  --track-origins=yes -s ./minishell
