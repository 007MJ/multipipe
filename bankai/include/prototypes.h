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
t_cmd	*new_node();
void	append(t_cmd **head, int i, int **pipes, char **cmds, char *fcmd, int nb_pipes);
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
int     check_quote(char *input);

// parsing/expan_pars
void    make_cmd(t_glob *shell_kai);

// parsing/space
void    replace_space(char *s1);
void    put_back_space(char **s1);
#endif
