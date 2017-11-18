#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


/**
 * Obtiene el indice de estados
 * @param personas el array se pasa como parametro.
 * @param estado carga un cero en todos los estados
 * @return devuelve todos los estados del array en cero
 **/
void inicializar(ePersona personas[], int MAX)
{

    int i;
    for(i=0; i<MAX; i++)
    {
        personas[i].estado=0;
    }

}
/**
* Obtiene el primer indice libre del array.
* @param personas el array se pasa como parametro.
* @return el primer indice disponible, si no lo encuentra devuelve un printf
**/

int buscaVacios(ePersona personas[], int MAX)
{
    int i;
    for(i=0; i<MAX; i++)
    {
        if(personas[i].estado==0)
        {
            return i;
            break;
        }
        else
        {
            printf("\nNo hay espacios vacios\n\n");
            break;
        }

    }
}
/**
* Obtiene el primer indice libre del array a través de la funcion buscaVacios y carga los datos del array persona
* @param personas el array se pasa como parametro.
* @return los datos de todos los campos del array personas y cambia estado a uno
**/

void cargarPersonas(ePersona personas[], int MAX)
{
    int i;
    i=buscaVacios(personas, MAX);
    for(i=0; i<MAX; i++)
    {
        if(personas[i].estado==0)
        {

            printf("\nCarga de personas\n");
            printf("\nIngrese dni\n");
            scanf("%ld", &personas[i].dni);
            printf("\nIngrese nombre\n");
            fflush(stdin);
            gets(personas[i].nombre);
            printf("\nIngrese edad\n");
            scanf("%d", &personas[i].edad);
            personas[i].estado=1;

            break;

        }


    }


}

/**
 * Obtiene el indice que coincide con el dni pasado por parametro
 * si no encuentra el indice vuelve a iniciarse la función
 * pregunta al usuario si quiere eliminar el dato, si responde que "no" sale del bucle, si no dice que si cambia el estado a cero.
 * si ingresa una letra mayuscula la pasa a minuscula
 * si pasa una letra incorrecta vuelve a iniciarse la funcion
 * @param personas el array se pasa como parametro.
 * @param sdni es una variable auxiliar que guarda el parámetro que va a ser buscado dentro del índice
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni y lo cambia a cero en la variable estado
 **/

void eliminarPersona(ePersona personas[], int MAX)
{
    char rta;
    long int sdni;
    int i;
    printf("\nIngrese dni: \n");
    scanf("%ld", &sdni);
    for(i=0; i<MAX; i++)
    {
        if(personas[i].estado==1)
        {
            if(sdni == personas[i].dni)
            {

                printf("\n%ld\t%s\t%d\n", personas[i].dni, personas[i].nombre, personas[i].edad);

                printf("\nEsta seguro de eliminar el dato? s/n: \n");
                fflush(stdin);
                scanf("%c",&rta);
                rta = tolower(rta);
                if(rta=='s')
                {
                    personas[i].estado= 0;
                    printf("\nDato eliminado\n");
                    break;
                }
                if(rta=='n')
                {
                    printf("\nAccion cancelada\n");
                    break;
                }
                else
                {
                    printf("\nNo es una opcion correcta\n");
                    eliminarPersona(personas, MAX);
                }

            }
            else
            {
                printf("\nEl numero ingresado es incorrecto\n");
                eliminarPersona(personas, MAX);

            }

        }
    }
}
/**
 * Obtiene el indice I y crea uno llamado J.
 * copia la primera información que hay en nombre de I al indice J de nombre
 * Si son mayores va copiando la informacion de I a auxpersona
 * luego la informacion de J a I
 * Finalmente copia la informacion de auxPersona a J
 * El indice de nombre es igual en J que en I, realiza la misma accion con el indice de Dni.
 * crea un array llamado auxPersona
 * @param i indice del array personas
 * @param j indice del array personas
 * @param auxPersona es el array auxiliar donde se copia la informacion que luego va a ser transportada a J o a I
 * @return devuelva los datos cargados ordenados alfabéticamente, si los nombres son iguales los imprime ordenados de menor a mayor por dni
 */
void ordenarPersona(ePersona personas[], int MAX)
{
    ePersona auxPersona;
    int i;
    int j;
    for(j=0; j<MAX-1; j++)
    {
        for(i=j+1; i<MAX; i++)
        {
            if(strcmp(personas[i].nombre, personas[j].nombre)>0)
            {
                auxPersona=personas[i];
                personas[i]= personas[j];
                personas[j]=auxPersona;
            }
            else
            {
                if(strcmp(personas[i].nombre, personas[j].nombre)==0)
                {
                    if(personas[i].dni>personas[j].dni)
                    {
                        auxPersona=personas[i];
                        personas[i]= personas[j];
                        personas[j]=auxPersona;

                    }
                }
            }
        }
        break;
    }

    printf("DNI\t\tNOMBRE\t\t\tEDAD\t\t\n");
    for(i=0; i<MAX; i++)
    {
        if(personas[i].estado!=0)
        {
            printf("%ld\t\t%s\t\t\t%d\t\t\n\n", personas[i].dni,personas[i].nombre,personas[i].edad);
        }
    }


}

/**
 * imprime un grafico de las edades
 * @param personas el array se pasa como parametro.
 * @param hasta18a son las edades hasta 18 años
 * @param hasta35a son las edades hasta 35 años
 * @param desde35a son las edades desde 36 en adelante
 * @return el grafico con los asteriscos ordenados.
 **/

void graficoPersona(ePersona personas[], int MAX)
{

    int i;
    int hasta18a=0;
    int hasta35a=0;
    int desde35a=0;
    int mayor;
    int flag;
    flag=0;
    int flag2=0;

    for(i=0; i<MAX; i++)
    {

        if(personas[i].estado ==1)
        {
            if (personas[i].edad < 19)
            {
                hasta18a ++;
            }
            else
            {
                if(personas[i].edad> 18 && personas[i].edad <36)
                {
                    hasta35a ++;
                }
                else
                {
                    desde35a++;
                }
            }
            flag2=1;
        }
    }
    if(flag2==0)
    {

        printf("No hay datos cargados hasta el momento\n");
        return;
    }


    if(hasta18a >= desde35a && hasta18a >=hasta35a)
    {
        mayor = hasta18a;
    }
    else
    {
        if(desde35a>=hasta18a &&desde35a >=hasta35a)
        {
            mayor = hasta35a;
        }
        else
        {
            mayor=hasta35a;
        }
    }


    for(i=mayor; i>0; i--)
    {
        if(i<10)
        {
            printf("%02d|", i);
        }
        else
        {
            printf("%02d|", i);
        }
        if(i<= hasta18a)
        {
            printf("*");
        }
        if(i<= hasta35a)
        {
            flag=1;
            printf("\t*");
        }
        if(i<=desde35a)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)

                printf("\t*");
        }

        printf("\n");



    }

    printf("  <18\t19-35\t>35\n");



}

