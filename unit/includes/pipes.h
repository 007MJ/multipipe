#ifndef PIPES_H
#define PIPES_H

#include "global.h"
typedef struct s_glob t_glob;
typedef struct s_files t_files;

// struc cmd
/// @brief index : iteration in the node, id : for child , pipes : for each node has pipes, cmds: cmd for node, first_cmd: cmd berfore space, nd_piped : numbers of pipe in argv;
typedef struct  s_cmd {
	int		type;
	pid_t	id;
	int		**pipes;
	char	**av_cmd;
	char	*cmd_name;
	char	**envp;
	int		index;
	bool	is_vars;
	int		nb_cmds;
	int 	nb_pipes;
	// should be a void next stuck
	struct s_cmd *next;
	t_files *files;
} t_cmd;


int     *array_child_ids(int nb_id);
void    change_pipe(t_cmd *current);
void    close_pipes(t_cmd *current, int nb);
int     execute_command(t_cmd *current, char **envp, char *envp_path);
int     **init_pipes(int nb);
char    *get_cmd_path(char *path, char *cmd);
int     run_commands(t_cmd *cmds);
void    wait_childs(t_cmd *cmds);
char    *get_cmd_path(char *path, char *cmd);
char    *get_envp_path(char **envp);

// single command
int    single_command(t_cmd *cmd, char **envp, char *envp_path);

// commands 
int    commands(t_cmd *cmds, char *envp_path);


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
char    *ft_strdup(char *s);


#endif