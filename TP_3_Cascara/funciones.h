#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[2000];
    int puntaje;
    int estado;
    char linkImagen[300];
    int id;
}EMovie;



void abrirArchivo(EMovie* movie,int T);
/**
 *  abre un archivo de tipo binario
 *  @param movie a la cual se le va a asignar mas espacio
 *
 */


EMovie* asignarMemoria(EMovie* movie,int T);

/**
 *  asigna un espacio de memoria al tipo de dato Emovie
 *  @param movie estructura a la cual se le va a asignar mas espacio
 *  @return movie un nuevo espacio en memoria
 */


 int buscarEspacios(EMovie* movie,int T);

/**
 *  busca espacios vacios en memoria
 *  @param lista a la cual se le van a cargar los datos
 *  @return i si encontro un lugar vacios o -1 si no hay espacio disponible
 */

int agregarPelicula(EMovie* movie,int T);
/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */

int borrarPelicula(EMovie* movie,int T);
/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int modificarPelicula(EMovie* movie,int T);
/**
 * Modifica una pelicula del archivo binario
 *  @param movie la estructura a ser modficada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
 void generarPagina(EMovie* movie, char nombre[],int T);
/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param movie la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void fprintfmovies(EMovie* movie, int T,FILE* bin);

/**
 *  Permite guardar los datos en el archivo binario
 *  @param movie la lista de peliculas a ser agregadas en el archivo.
 *  @param FILE el puntero hacia el archivo binario
 */
void imprimirPeliculas(EMovie* movie, int T);

/**
 *  Imprime un listado por pantalla
 *  @param movie la lista de peliculas a ser agregadas en el archivo.
 */

#endif // FUNCIONES_H_INCLUDED
