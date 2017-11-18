#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    char opcion;
    float x;
    float y;
    float z;


    while(seguir=='s')
    {
        system("color F1");
        printf("1- Ingresar 1er operando (A=%.2f)\n",x);
        printf("2- Ingresar 2do operando (B=%.2f)\n", y);
        printf("3- Calcular la suma (%.2f + %.2f)\n", x,y);
        printf("4- Calcular la resta (%.2f - %.2f)\n", x,y);
        printf("5- Calcular la division (%.3f/%.3f)\n", x,y);
        printf("6- Calcular la multiplicacion (%.2f*%.2f)\n",x,y);
        printf("7- Calcular el factorial (%2.f!)\n",x);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        fflush(stdin);
        opcion=getchar();


        switch(opcion)
        {
        case '1':
            printf("1- Ingresar 1er operando\n");
            scanf("%f",&x);
            break;
        case '2':
            printf("2- Ingresar 2do operando\n");
            scanf("%f", &y);
            break;
        case '3':
            z=suma(x,y);
            printf("\n\n\nEl resultado de la suma es %.2f\n", z);
            system("pause");
            system("cls");
            break;
        case '4':
            z=resta(x,y);
            printf("\n\n\nEl resultado de la resta es %.2f \n", z);
            system("pause");
            system("cls");
            break;
        case '5':

            if((z=division(x,y))!=0)
            {
                printf("\n\n\nEl resultado de la division es %.4f \n",z);
            }
            system("pause");
            system("cls");
            break;
        case '6':
            z=multiplicacion(x,y);
            printf("\n\n\nEl resultado de la multiplicacion es %.2f \n", z);
            system("pause");
            system("cls");
            break;

        case '7':
            if((z=factorial(x))!=0)

            {
                printf("\n\n\nEl factorial de %1.f es %1.f\n",x,z);
            }
            else{
                printf("No se pudo calcular factorial\n");
            }
            system("pause");
            system("cls");
            break;
        case '8':
            z=suma(x,y);
            printf("\n\n\nEl resultado de la suma es: %.2f \n", z);
            z=resta(x,y);
            printf("\n\n\nEl resultado de la resta es: %.2f \n", z);
            if((z=division(x,y))!=0)
            {
                printf("\n\n\nEl resultado de la division es %.4f \n",z);
            }
            z=multiplicacion(x,y);
            printf("\n\n\nEl resultado de la multiplicacion es: %.2f \n", z);
            if((z=factorial(x))!=0)

            {
                printf("\n\n\nEl factorial de %1.f es %1.f\n",x,z);
            }
            else{
                printf("No se pudo calcular factorial\n");
            }
            system("pause");
            system("cls");

            break;
        case '9':
            seguir = 'n';
            break;
        default:
            printf("Ingrese una opcion valida\n");
            break;

        }
        }
    return 0;
}




