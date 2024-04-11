#include "files.h"
#include "string.h"

t_files    *append(t_files *files, char *name)
{
    t_files *new;
    t_files *curr;
    printf("1\n");
    curr = files;;
    new = malloc(sizeof(t_files));
    new->name = malloc(sizeof(char *) * (strlen(name) + 1));
    new->next = NULL;
    printf("2\n");
    if (new->name)
        strcpy(new->name, name);
    else
        return NULL;
    printf("3 %s\n", new->name);
    if (!curr)
    {
        files = new;
        printf("4\n");
        return files;
    }
    printf("5\n");
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new;
    return (files);
}

/***************************************************/
/************** append with multi files*************/
/***************************************************/

// int main(void)
// {
//      t_files *files;

//      files = NULL;
//      files = append(files, "file_one");
//      files = append(files, "file_two");
//     ft_append(files);
//     printf("shoul only be in the last fiile....\n");
// }

/***************************************************/
/************** append with multi files*************/
/***************************************************/

// int main(void)
// {
//      t_files *files;

//      files = NULL;
//      files = append(files, "file_one");
//     ft_append(files);
//     printf("one file ....\n");
// }

/***************************************************/
/*rediretion moore than one files  dup2(fd, 1) *****/
/***************************************************/


// int main(void)
// {
//      t_files *files;

//      files = NULL;
//      files = append(files, "redirection_files_test1.txt");
//      files = append(files, "redirection_files_tes2.txt");
//     change_stdout(files);
//     printf("more the one files should be in the last files ....\n");
// }

/***************************************************/
/*********rediretion files  dup2(fd, 1) ************/
/***************************************************/


// int main(void)
// {
//      t_files *files;

//      files = NULL;
//      files = append(files, "redirection_only_one_file.txt");
//     change_stdout(files);
//     printf("only one files ....\n");
// }


/***************************************************/
/********* change the input files  dup2(fd, 0) *****/
/***************************************************/

// can't real tets only the 
int main(int ac, char **av)
{
     t_files *files;

     files = NULL;
     if (ac == 2)
     {
        files = append(files, av[1]);
        change_stdint(files);
     }
     else{
        printf("should have only one argv !!\n");
     }
     return (0);
}

