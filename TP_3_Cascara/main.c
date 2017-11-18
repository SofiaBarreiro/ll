#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funciones.h"
#include<conio.h>
#include<ctype.h>
#define T 10


int main()
{
    char seguir='s';
    int opcion=0;
    EMovie* movies;

    movies=asignarMemoria(movies,T);
    movies->id=0;


    if(movies==NULL)
    {

        printf("\nNo hay espacio disponible");
        exit(0);
    }
    //abrirArchivo(movies,T);

    while(seguir=='s')
    {
        printf("\n\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPelicula(movies,T);
                break;
            case 2:
                system("cls");
                borrarPelicula(movies,T);
                break;
            case 3:
                modificarPelicula(movies,T);
               break;
            case 4:
            generarPagina(movies,"MovieList.html",T);
               break;
            case 5:
                free(movies);
                seguir = 'n';
                break;
            default:
                 printf("\nLa opcion ingresada es incorrecta\n");
        }
    }

    return 0;
}
