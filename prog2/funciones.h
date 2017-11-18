
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



typedef struct
{
    long int dni;
    char nombre[50];
    int edad;
    int estado;

} ePersona;


void inicializar(ePersona personas[], int MAX);
int buscaVacios(ePersona personas[], int MAX);
void cargarPersonas(ePersona personas[], int MAX);
void eliminarPersona(ePersona personas[], int MAX);
void ordenarPersona(ePersona personas[], int MAX);
void graficoPersona(ePersona personas[], int MAX);




#endif // FUNCIONES_H_INCLUDED
