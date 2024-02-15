#ifndef STRUCT_H
#define STRUCT_H

// global struct
typedef struct s_glob
{
	char    **envp;
    char    *input;
	int     **pipes;
    int     on;

}t_glob;


// struc cmd
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



#endif