/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/10/20 10:45:08 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdbool.h>

enum e_type
{
	WORD = 1,
	SPACES,
	PIPE,
	LESS,
	GREAT,
	LESS_LESS,
	GREAT_GREAT,
	INPUT,
	OUTPUT,
	HEREDOC,
	END,
};

enum e_quote
{
	N_QUOTE,
	S_QUOTE,
	D_QUOTES,
};

typedef struct s_token
{
	enum e_type		type;
	char			*str;
	struct s_token	*next;
	struct s_token	*prev;
}		t_token;

typedef struct s_env
{
	char			*name;
	char			*var;
	struct s_env	*next;
}					t_env;

typedef struct s_cmd
{
	int			index;
	int			append;
	char		*builtins;
	char		*cmd;
	char		*eof;
	char		*heredoc_path;
	char		*input_redirec;
	char		*output_redirec;
}	t_cmd;

typedef struct s_data
{
	int				**pipes;
	char			**builtins_tab;
	char			*readline;
	char			*path;
	char			**paths;
	int				cmds_nb;
	char			*cmds_exec;
	pid_t			*pid;
	struct s_token	*token;
	struct s_cmd	**cmds;
	struct s_env	*env;
	struct s_env	*export;
}					t_data;

// Utils
void			ft_error_msn(char *str, t_data *data);
int				ft_error_msn_separator(char *str, int err_sep);
void			ft_free_tab(char **tab);
void			ft_free_token(t_token **token);
void			ft_free_list_lexer(t_token **list);
void			ft_free_parsing(t_data *data);
char			*ft_strstr(char *str, char *to_find);
int				ft_strcmp(const char *s1, const char *s2);
long int		ft_atol(const char *nptr);
long long int	ft_atoll(const char *nptr);

// Init
void			ft_init(t_data *data, char **envp);
void			ft_init_pipe(t_data *data);
void			ft_pid_init(t_data *data);

// Pipex Fonctions
pid_t			ft_fork(t_data *data, int cmd_index);
void 			ft_dup2(t_data *data, int cmd_index);
void			ft_dup2_first(t_data *data, int cmd_index, int fd_stdin, int fd_stdout);
void			ft_dup2_n(t_data *data, int cmd_index, int fd_stdin, int fd_stdout);
void 			ft_exec(t_data *data, int cmd_index);
int				ft_open_stdin(t_data *data, int cmd_index);
int				ft_open_stdout(t_data *data, int cmd_index);
void			ft_waitpid(t_data *data);
void			ft_close_pipes(t_data *data);
void			ft_close_and_free(t_data *data);
char			*ft_env_path(t_data *data);
char			*ft_find_cmd(t_data *data, char *cmd);

// Builtins
void			ft_builtins(t_data *data, char *str);
void			ft_pwd();
void			ft_echo(t_data *data, char **argv);
int				ft_echo_option(char *str);
void			ft_exit(t_data *data, char **argv);
void			ft_exit_arg(char *str);
int				ft_above_lli(char *str, int sign);
void			ft_env(t_env *env, char **argv);
int				ft_check_arg_env(char *str, int export);
void			ft_unset(t_env **env, t_env **export, char **argv);
void			ft_export(t_data *data, char **argv);
void			ft_export_for_norm(t_data *data, char **argv, int i);
void			ft_erase_list_node(t_env **env, char **argv);
void			ft_update_list_node(t_data *data, int i, char *name, char *var);
void			ft_env_alpha_order(t_env **env);
void			ft_cd(t_data *data, char **argv);
void			ft_cd_home(t_data *data, char *pwd, char *oldpwd, t_env *current);
void			ft_cd_directory(t_data *data, char *pwd, char *oldpwd, char *str);
void			ft_update_pwd(t_env **env, char *pwd, char *oldpwd, t_env *current);

// Environnment
void			ft_get_env(t_data *data, char **envp);
void			ft_add_env_node(t_data *data, char *name, char *var);
void			ft_add_export_node(t_data *data, char *name, char *var);
void			ft_free_list_env(t_env	*env);
t_env			*ft_last_env_node(t_env *env);
void			ft_sort_env_list(t_env **env);
void			ft_insert_sorted(t_env **env, t_env *new_node);

// Here_doc
void			ft_heredoc_path(t_data *data);
void			ft_heredoc_create(t_data *data, int i, char *file_name);

// Execution
void			ft_minishell(t_data *data);
void			ft_execute_minishell(t_data *data, char *line);
void			ft_execute(t_data *data);
void			ft_execute_init(t_data *data);
void			ft_free_cmds(t_data *data);
void			ft_free_unlink_cmds(t_data *data);
char			**ft_env_exec(t_data *data);
int				ft_cmd_count(t_data *data);

// Status
void			ft_set_last_status(int status);
int				ft_get_last_status(void);
void			ft_return_status(t_data *data, int status);

// Signal
void			signal_handler(int signal);

// Link
void			ft_link_cmd(t_data *data);

//	Lexer
int				ft_lexer(t_data *data, char *line);
int				ft_set_status_quote(int quote, char *line, int i);
void			ft_add_sep(t_token **token, char *line, int i, int len, int type);
void			ft_add_word(t_token **token, char *line, int i, int start);

// Parser
int				ft_parser(t_data *data);
int				ft_parser_error(t_token *token);

//	Expansion_var
void			ft_expansion_var(t_data *data);
int				ft_update_quote(char c, int qoute);
bool			ft_next_sep(char c);
bool			ft_between_quotes(char *str, int i);



void			ft_clear_quote(t_data *data);
char			*ft_clear_str(t_data *data, char *str);
int				ft_quote_inside(char *str);
char			*ft_remove_quotes(char *str);
char			*ft_merge_quotes(t_data *data, char **tab);
int				ft_skip_quotes(char *quote, int *j, char *str);
char			*ft_add_char(char *str, char c);
int				ft_rm_quotes(char c, char c2, int i);
char			**ft_clear_tab(char **tab);
int				ft_nb_quotes(char *str);
char			*ft_clear_word(char *str);
void			ft_add_word_space(char **s, char **final, int i);
int				ft_strlen_tab(char **tab);
void			ft_modif_var_env(t_data *data, char **tab);
char			*ft_var_env(t_data *data, char *str);



void print_lexer(t_token **list);




#endif
