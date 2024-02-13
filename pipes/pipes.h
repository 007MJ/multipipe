#ifndef PIPES_H
# define PIPES_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


/// @brief index : iteration in the node, id : for child , pipes : for each node has pipes, cmds: cmd for node, first_cmd: cmd berfore space, nd_piped : numbers of pipe in argv;
typedef struct  s_cmd {
	int		index;
	pid_t	id;
	int		**pipes;
	char	**cmds;
	char	*first_cmd;
	int		nb_pipes;
	struct s_cmd *next;
} t_cmd;

char    *get_cmd_path(char *path, char *cmd);
char    *get_envp_path(char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	 ft_strlen(const char *s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void    free_str(char **str);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
