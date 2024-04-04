#ifndef STRUCT_H
#define STRUCT_H

// global struct
typedef struct s_cmd t_cmd; 
typedef struct s_built t_built; 
typedef struct s_files	t_files; 

typedef struct s_glob
{
	char    **envp;
    char    *input;
	int     **pipes;
	int		_return;
    int     on;

	t_cmd	**cmds;
	t_built	**buily;
	t_files **files;

}t_glob;


// struc cmd
/// @brief index : iteration in the node, id : for child , pipes : for each node has pipes, cmds: cmd for node, first_cmd: cmd berfore space, nd_piped : numbers of pipe in argv;
typedef struct  s_cmd {
	int		type;
	pid_t	id;
	int		**pipes;
	char	**av_cmd;
	char	*cmd_name;
	int		index;
	int		nb_pipes;
    
	// should be a void next stuck
	struct s_cmd *next;
} t_cmd;


typedef struct s_built
{
	int	type;
	char **argv;
	struct s_built *next;

} t_built;

typedef	struct	s_files 
{
	char	*name;
	char	**agrv;
	struct	s_file *next;
}t_files;


#endif