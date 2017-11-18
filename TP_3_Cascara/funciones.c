#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funciones.h"
#include"utn.h"
#include<conio.h>
#include<ctype.h>


/** \brief asigna memoria a una estructura de arrays
 *
 * \param eMovie movie es el array de estructura de datos puntero a la que se asigna memoria
 * \param T es el tamaño del array
 * \return
 *
 */


EMovie* asignarMemoria(EMovie* movie,int T)
{
    movie = (EMovie*)malloc(sizeof(EMovie)*T);

    return movie;

}

/** \brief busca una estructura donde el estado este en cero
 *
 * \param Emovie movie es el array de estructuras
 * \param T es el tamaño del array
 * \return el indice del array vacio, si no encuentra ningun esatdo vacio retorna -1
 *
 */

int buscarEspacios(EMovie* movie,int T)
{
    int i;
    for(i=0; i<T; i++)
    {
        if((movie+i)->estado==0)
        {
            return i;
        }
    }
    return -1;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void abrirArchivo(EMovie* movie,int T)
{
    FILE* bin;
    bin=fopen("bin.dat","r");

    char titulo[50], genero[50],duracion[100], descripcion[2000],puntaje[100],linkImagen[300];
    int contador=0,i;

    if(bin==NULL)
    {
        printf("\nNo se pudo abrir el archivo");
        exit(0);
    }
    //Inicializa los estados en cero
    for(i=0; i<T; i++)
    {
        (movie+i)->estado=0;
    }
    while(!feof(bin))
    {
        if(contador==T)
        {
            break;
        }
        fscanf(bin, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n",linkImagen,titulo,genero,descripcion,duracion,puntaje);
        strcpy((movie+contador)->linkImagen,linkImagen);
        strcpy((movie+contador)->titulo,titulo);
        strcpy((movie+contador)->genero,genero);
        atoi(duracion);
        (movie+contador)->duracion=duracion;
        strcpy((movie+contador)->descripcion,descripcion);
        atoi(puntaje);
        (movie+contador)->puntaje=puntaje;
        (movie+contador)->estado=1;
        contador++;
    }
    fclose(bin);
}

void fprintfmovies(EMovie* movie, int T,FILE* bin)
{
    int i;
    for(i=0; i<T; i++)
    {
        if((movie+i)->estado==1)
        {
            fprintf(bin, "%s \t %s \t %s \t %s \t %d \t %d\n", (movie+i)->linkImagen,(movie+i)->titulo,(movie+i)->genero,(movie+i)->descripcion,(movie+i)->duracion,(movie+i)->puntaje);
        }
    }
}


void imprimirPeliculas(EMovie* movie, int T)
{
    int i;
    for(i=0; i<T; i++)
    {
        if((movie+i)->estado==1)
        {
            printf("\nID: %d\t TITULO: %s\t GENERO: %s\n",i,(movie+i)->titulo,(movie+i)->genero);
        }
    }
}


int agregarPelicula(EMovie* movie,int T)
{
    FILE* bin;

    char titulo[50], genero[50],descripcion[2000],linkImagen[300];
    char rta;
    int estado;
    int duracion,puntaje,auxT;

    estado=buscarEspacios(movie,T);

    if(estado==-1)
    {
        printf("\nNo hay mas espacio");
        return 0;
    }
    fflush(stdin);
    printf("Ingrese el titulo de la pelicula: ");
    gets(titulo);
    strupr(titulo);
    fflush(stdin);
    printf("Ingrese el genero de la pelicula: ");
    gets(genero);
    fflush(stdin);
    DESCRIPCION:
    printf("Ingrese la descripcion de la pelicula");
    gets(descripcion);

    auxT=strlen(descripcion);

    if(auxT>2000)
    {
        printf("\nLa descripcion es demasiado larga. Vuelva a escribirla");
        goto DESCRIPCION;
    }
    printf("\nIngrese la duracion(en minutos): ");
    fflush(stdin);
    scanf("%d",&duracion);
    PUNTAJE:
    printf("Ingrese un puntaje entre 1 y 10\n");
    fflush(stdin);
    scanf("%d", &puntaje);
    if(puntaje<=0||puntaje>10){
        printf("\nEl numero ingresado es incorrecto\n");
        goto PUNTAJE;

    }
    fflush(stdin);
    getStringLetras("Ingrese el link de la imagen",linkImagen);

    printf("\nDesea Ingresar la pelicula s/n:  ");
    rta=toupper(getche());
    if(rta=='S')
    {
        strcpy((movie+estado)->titulo,titulo);
        strcpy((movie+estado)->genero,genero);
        strcpy((movie+estado)->descripcion,descripcion);
        (movie+estado)->duracion=duracion;
        (movie+estado)->puntaje=puntaje;
        strcpy((movie+estado)->linkImagen,linkImagen);
        (movie+estado)->estado=1;
        (movie+estado)->id ++;
        bin=fopen("bin.dat","w");
        if(bin==NULL)
        {
            printf("\nNo se pudo abrir el archivo");
            exit(0);
        }
        fprintfmovies(movie,T,bin);
        fclose(bin);
        return 1;
    }
    else
    {

        printf("\nNo se pudo ingresar la pelicula\n");
    }
    return 0;
}


int borrarPelicula(EMovie* movie,int T)
{

    int i;
    int nro;
    char rta;
    FILE* bin;

    imprimirPeliculas(movie, T);
    printf("\n\nIngrese el nro de la pelicula a eliminar: ");

    scanf("%d",&nro);

    for(i=0; i<T; i++)
    {
        if(nro==i&&(movie+i)->estado==1)
        {
            printf("\nTitulo: %s\n\nGenero: %s\n\nDescripcion: %s\n\nDuracion: %d\n\nPuntaje: %d\n\nLinkImagen: %s",(movie+i)->titulo,(movie+i)->genero,(movie+i)->descripcion,(movie+i)->duracion,(movie+i)->puntaje, (movie+i)->linkImagen);
            printf("\n\nEsta desguro que desea eliminar esta pelicula(s/n):    ");

            rta=tolower(getche());

            if(rta=='s')
            {
                (movie+i)->estado=0;
                bin=fopen("bin.dat","w");
                if(bin==NULL)
                {
                    printf("\nNo se pudo abrir el archivo");

                    exit(0);
                }

                fclose(bin);
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    printf("\n\nEl nro ingresado no existe, por favor vuelva a ingresarlo");

    borrarPelicula(movie, T);
    return 0;

}

int modificarPelicula(EMovie* movie,int T)
{
    int i,opcion,duracion,puntaje, aux;
    int nro;
    char titulo[50], genero[50],descripcion[2000],linkImagen[300];
    char rta;
    aux=2000;
    FILE* bin;

    imprimirPeliculas(movie,T);

    printf("\n\nIngrese el ID de la pelicula que desea modificar: ");

    scanf("%d",&nro);

    for(i=0; i<T; i++)
    {
        if(nro==i&&(movie+i)->estado==1)
        {

            printf("\nTitulo: %s\n\nGenero: %s\n\nDescripcion: %s\n\nDuracion: %d\n\nPuntaje: %d\n\nLinkImagen:%s",(movie+i)->titulo,(movie+i)->genero,(movie+i)->descripcion,(movie+i)->duracion,(movie+i)->puntaje, (movie+i)->linkImagen);
            printf("\n\nEsta seguro que desea modificar esta pelicula(s/n): ");

            rta=tolower(getche());

            if(rta=='s')
            {
                printf("\n\n\nIngrese la opcion a modificar:");
                printf("\n1- Titulo");
                printf("\n2- Genero");
                printf("\n3- Descripcion");
                printf("\n4- Duracion");
                printf("\n5- Puntaje");
                printf("\n6- Link Imagen");
                printf("\n7- Salir\n");

                scanf("%d",&opcion);



                switch(opcion)
                {
                case 1:
                    printf("\nIngrese el nuevo titulo: ");
                    fflush(stdin);
                    gets(titulo);
                    strcpy((movie+i)->titulo,titulo);
                    break;
                case 2:
                    printf("\nIngrese el nuevo genero: ");
                    fflush(stdin);
                    gets( genero);
                    strcpy((movie+i)->genero,genero);
                    break;
                case 3:
                    printf("\nIngrese la nueva descripcion: ");
                    fflush(stdin);
                    gets(descripcion);
                    while(aux>2000)
                    {
                        printf("\nLa descripcion es demasiado larga. Vuelva a Ingresarla");
                        fflush(stdin);
                        gets(descripcion);
                    }
                    strcpy((movie+i)->descripcion,descripcion);

                    break;
                case 4:
                    printf("\nIngrese la nueva duracion: ");
                    scanf("%d",&duracion);
                    (movie+i)->duracion=duracion;
                    break;
                case 5:
                    printf("\nIngrese el nuevo puntaje del 1 al 10: ");
                    scanf("%d",&puntaje);
                    while(puntaje<1 || puntaje>10)
                    {
                        printf("el nro es incorrecto. Ingrese un nro entre 1 y 10");
                        scanf("%d",&puntaje);
                    }
                    (movie+i)->puntaje=puntaje;
                    break;
                case 6:
                    printf("\nIngrese el nuevo link: ");
                    fflush(stdin);
                    gets(linkImagen);
                    strcpy((movie+i)->linkImagen,linkImagen);
                    break;
                case 7:
                    return 0;
                    break;
                default:
                    printf("Opcion incorrecta");
                    return 0;
                }
                bin=fopen("bin.dat","w");
                if(bin==NULL)
                {
                    printf("No se encontro el archivo.");
                    exit(0);
                }
                fprintfmovies(movie,T,bin);
                fclose(bin);
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    printf("\nEl Id ingresado es incorrecto");
    return 0;
}


void generarPagina(EMovie* movie, char nombre[],int T)
{

    FILE* pagina;
    int i;
    pagina=fopen(nombre,"w");
    if(pagina==NULL)
    {
        printf("\nNo se pudo abrir el archivo");
        exit(0);
    }
    fprintf(pagina,"<!DOCTYPE html>");
    fprintf(pagina,"<html lang='en'>");
    fprintf(pagina,"<head>");
    fprintf(pagina,"<title>Listado de peliculas</title>");
    fprintf(pagina,"<meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'>");
    fprintf(pagina,"<meta name='viewport' content='width=device-width, initial-scale=1'>");
    fprintf(pagina,"<link href='css/bootstrap.min.css' rel='stylesheet'>");
    fprintf(pagina,"<link href='css/custom.css' rel='stylesheet'>");
    fprintf(pagina,"</head>");
    fprintf(pagina,"<body>");
    fprintf(pagina,"<div class='container'>");
    fprintf(pagina,"<div class='row'>");

    for(i=0; i<T; i++)
    {
        if((movie+i)->estado==1)
        {
            fprintf(pagina,"<article class='col-md-4 article-intro'>");
            fprintf(pagina,"<a href='#'>");
            fprintf(pagina,"<img class='img-responsive img-rounded' src='%s' alt='%s'></a>\n",(movie+i)->linkImagen,(movie+i)->titulo);
            fprintf(pagina,"<h3 style='color:#2196f3'>%s</h3>\n",(movie+i)->titulo);
            fprintf(pagina,"<ul><li>Genero: %s</li>\n<li>Puntaje: %d</li>\n<li>Duracion: %d mins</li></ul>\n",(movie+i)->genero,(movie+i)->puntaje,(movie+i)->duracion);
            fprintf(pagina,"<p>%s</p></article>",(movie+i)->descripcion);
        }
    }
    fprintf(pagina,"</div></div>");
    fprintf(pagina,"<script src='js/jquery-1.11.3.min.js'></script>");
    fprintf(pagina,"<script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'>");
    fprintf(pagina,"</script><script src='js/holder.min.js'></script>");
    fprintf(pagina,"</body>");
    fprintf(pagina,"</html>");

    printf("\nPagina creada exitosamente\n");
    fclose(pagina);
}



