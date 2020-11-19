/**
 * Actualmente este fichero lo que hace es un ls
*/

#include "iostream" //Importante para poder imprimir por pantalla entre otras cosas
#include <fstream>  //Manejo de ficheros de entrada y salida
#include <cstring>  //Utilizado para comparar Strings
#include <dirent.h> //Manejo entre directorios

using namespace std;

int operation(char *fichero);

int main(int argc, char *argv[])
{
    //Si el número de argumentos que me pasa el programa es menor que 4 es que está mal
    if (argc != 4)
    {
        perror("El número de parámetros no es correcto");
        return -1;
    }
    //En el caso de que no sea ninguno de estos el tipo pasado por argumento
    if (strcmp(argv[1], "copy") && strcmp(argv[1], "gauss") && strcmp(argv[1], "sobel"))
    {
        perror("No existe ese tipo");
        return -1;
    }
    struct dirent *eDirOrigen;          //Lee los ficheros que hay en el Directorio de origen
    DIR *dirOrigen = opendir(argv[2]);  //Obtengo todos los ficheros del origen
    DIR *dirDestino = opendir(argv[2]); //Obtengo todos los ficheros del destino
    char *origen = argv[2];             //El path origen que me han pasado
    char *destino = argv[3];
    if(origen[strlen(origen)-1] != '/') strcat(origen, "/"); //En el caso de que no exista la barra en dir origen
    if(destino[strlen(destino)-1] != '/') strcat(destino, "/"); //En el caso de que no exista la barra en dir origen
    char *filePath = (char *) malloc (strlen(origen));   //para obtener el path del fichero según cada elemento

    //Debe de existir los dos directorios
    if (dirOrigen == NULL || dirDestino == NULL) 
    {
        perror("No existe uno de los directorios que has pasado por argumento");
        return -1;
    }
        while ((eDirOrigen = readdir(dirOrigen)) != NULL) //Mientras el elemento que me pase el directorio no sea nulo
        {
            memcpy(filePath, argv[2], strlen(argv[2])); //Reconvierto el path origen
            if (strcmp(eDirOrigen->d_name, ".") && strcmp(eDirOrigen->d_name, "..")) //Evito que utilicen como fichero el . y ..
            {
                cout << eDirOrigen->d_name << "\n";      //Hace el ls del directorio que le has pasado sin puntos
                strcat(filePath, eDirOrigen->d_name); //copio el fichero al final del path
                operation(filePath);                  //realizo la operación que me ha pedido
            }
        }
    free(filePath);
    return 0;
}

int operation(char *fichero){
    cout<< fichero<<"\n";
    return 0;
}