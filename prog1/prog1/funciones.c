#include <stdio.h>
#include <stdlib.h>

/** \brief toma los valores a y b y devuelve un resultado
 *
 * \param a Es un numero flotante
 * \param b Es un numero flotante
 * \return total Es la suma de a y b
 *
 */
float suma(float a, float b)
{

    float total;
    total= a+b;

    return total;
}
/** \brief toma los valores a y b y devuelve un resultado
 *
 * \param a Es un numero flotante
 * \param b Es un numer flotante
 * \return total Es la resta de a y b
 *
 */
float resta(float a, float b)
{

    float total;
    total= a-b;
    return total;
}
/** \brief toma los valores a y b y devuelve un resultado
 *
 * \param a Es un numero flotante
 * \param b Es numero flotante
 * \return cero si el numero ingresado en la variable a o b es igual a cero
 *  total es la division de a y b
 */
float division(float a, float b)
{

    float total;
    if(a==0||b==0)
    {
        printf("\n\nUno de los numeros ingresados es cero, por favor vuelva a ingresar un numero valido\n\n");
        return 0;
    }
    else
    {
        total= a/b;
        return total;
    }

}
/** \brief toma los valores a y b y devuelve un resultado
 *
 * \param a Es un numero flotante
 * \param b Es numero flotante
 * \return total Es la multiplicacion de a y b
 *
 */
float multiplicacion(float a, float b)
{

    float total;
    total= a*b;
    return total;
}
/** \brief Toma la variable a y devuelve un resultado
 *
 * \param a Es un numero flotante
 * \return Cero Si la variable a es menor a cero o mayor a diez
 *  Total el factorial de la variable a.
 */
float factorial(float a)
{
    float total;
    if(a<=0||a>10)
    {

        printf("Ingrese un nro menor a 11 o mayor a 0\n");
        return 0;


    }
    else
    {

        if(a==1)
            return 1;
        total=a* factorial(a-1);

        return (total);
    }
}
