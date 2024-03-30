#include "mulit.h"

// > redirige le flux de sortie de la commande pour la placer dans un fichier. Par défaut, si rien n'est précisé, le flux redirigé est la sortie standard, 
// < redirige le flux d'entrée de la commande pour la prendre dans un fichier,
// >> redirige le flux de sortie de la commande pour l’ajouter à la fin d’un fichier existant.

//pour la programme printf > file
int main(int ac, char **av)
{
    if (ac == 2)
    {
        int file = open(av[1], O_WRONLY | O_CREAT,  07777);
        dup2(file, 1);
        if (file < -1)
            printf("Error file\n");
        else
        {
            printf("Yes we can do it 😘");  
        }
    }
    return (0);
}