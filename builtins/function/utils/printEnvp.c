#include "../../test/include.h"


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] != s2[i])
        {
            if (s1[i] > s2[i])
                return (2);
            return (1);
        }
		i++;
	}
	if (s2[i] == '\0' || i == n)
		return (1);
	else
		return (-s2[i]);
}

void    swap(char **s1, char **s2)
{
    char *tmp;

    tmp = NULL;
    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;

}

void ft_sort(char **envp)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (envp[i] != NULL)
    {
        j = i + 1;
        while (envp[j] != NULL)
        {
            if (ft_strncmp(envp[i], envp[j], ft_strlen(envp[j])) == 2)
                swap(&envp[i], &envp[j]);
            j++;
        }
        i++;
    }
}
 
void    printEnvp(char **envp)
{
    int i;

    i = 0;
    ft_sort(envp);
    while (envp[i]!= NULL){
        printf("declare -x %s\n", envp[i]);
        i++;
    }
}