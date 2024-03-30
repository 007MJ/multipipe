#ifndef PROTOTYPES_H
# define PROTOTYPES_H




// path
char    *get_cmd_path(char *path, char *cmd);
char    *get_envp_path(char **envp);

// lib
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	 ft_strlen(const char *s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void    free_str(char **str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
t_cmd	*new_cmd();
void	append(t_cmd **head, t_cmd *cmd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

// utils
int		run_command(char **envp, t_cmd **cmds);
int		**init_pipes(int nb);
int		execute_commands(t_cmd *current, char **envp, char *envp_path);
void	change_pipe(t_cmd *current);
void    wait_childs(pid_t *id, int nb);
int		*array_child_ids(int nb_id);
void	close_pipes(t_cmd *current, int nb);


// parsing

char	**pars(t_glob *shell_kai);
// char    *manage_sign(int *i, char *input);
// char    *manage_words(int *i, char *input);
void    remove_quote(char **s1);
int     check_quote(char *input);

// parsing/expan_pars
void    make_cmds(t_glob *shell_kai);
int     type_of_cmd(char *s);
int     remove_first_quote(char *s, t_cmd **cmds);

// parsing/space
void    replace_space(char *s1);
void    put_back_space(char **s1);

// fusion
void    setting_run(t_glob *shell_kai);

// parsing/expan_pars/trie_cmds
t_cmd   *trie_cmd(char **av);
char    **newcmds(char **olds, char *n);
char    **newav(char *av);
char    *allocatecpy(char *src);
int     sizecmds(char **cmds, char *n);
t_cmd   *initcmd(char *name, char *av);
void    ft_cpycmds(char **new, char **olds, const char *n);

#endif
