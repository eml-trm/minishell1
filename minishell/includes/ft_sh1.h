/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 21:49:53 by etermeau          #+#    #+#             */
/*   Updated: 2015/02/26 21:49:57 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include "libft.h"

enum	e_cmd_type
{
	_ERR = 0,
	_EXEC,
	_CD,
	_ENV,
	_SETENV,
	_UNSETENV,
	_EXIT
};

typedef struct		s_lex
{
	char			*word;
	struct s_lex	*next;
}					t_lex;

typedef struct		s_env
{
	char			*name;
	char			*data;
	struct s_env	*next;
}					t_env;

typedef struct		s_glob
{
	t_env			*env;
	t_lex			*lst;
	int				ret;
	char			*pwd;
	struct s_glob	*next;
}					t_glob;

void				ft_signal(void);
int					ft_access(char *path);
void				code_erreur(int code, char *str);

int					ft_strplen(char **str);
void				ft_print_tab(char **tab);
void				ft_new_env(char *name, char *info, int i);
char				*ft_getcwd(void);
char				*ft_getenv(char *name);

char				*recup_dir(t_lex *lst);
void				ft_find_arg(t_lex *list);
int					ft_find_command(t_lex *elem);
void				ft_parser(t_lex *list, char **arg);

t_lex				*ft_new_lex(char *word);
void				ft_add_lex(t_lex **list, char *word);
void				ft_lexer(char *line);

void				ft_print_tab(char **tab);
void				ft_print_lex(t_lex *lex);
void				ft_print_env(t_env *env);

t_glob				*ft_singleton(void);
void				ft_add_elem(t_env **list, char *name);
t_env				*ft_new_elem(char *elem);
void				ft_list(t_env **list, t_env *new, t_env *tmp);

void				ft_free_tab(char **tab);
int					verif_path(t_lex *lst);
char				**init_tab(t_env *list);

int					ft_exit(char **str);
void				ft_del_elem(t_env *elem, t_env *start, int i);
int					ft_unsetenv(char **str);
void				add_env(t_env **temp, char *name, char *data);
void				ft_setenv(char **str);
void				exec_env(char **str, int *i, int isnew_env, char **env);
char				**build_env(t_env *env);
char				**new_env(char **str);
int					is_exec(char **newenv, char *str);
int					search_cmd(char **str);
void				ft_env(char **str);
void				ft_cd(char **cmd);
void				ft_exec_fork(t_lex *list, char **tab, char **arg);
void				ft_exec_cmd(char **arg, int cmd);

#endif
