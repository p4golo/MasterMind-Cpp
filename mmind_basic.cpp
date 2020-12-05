#include <iostream>
#include <math.h>
using namespace std;
#include "mmind_basic.h"

bool comprobarDigitosRepetidos(const unsigned int numero[], const int num_elem)
{
    // inicializamos la variable digito repetido a false para que en el caso de que no haya repetidos, el valor sea false
    bool repeatdigit = false;
    // bucle con el que recorremos el array
    for(int i = 0; i < num_elem;i++)
    {
        // inicializamos un contador que usaremos para comprobar que el numero de veces que se repite un digito
        int cont = 0;
        int digit1 = numero[i]; // asignamos a una variable el valor de la posicion del array de esta pasada
        for (int j = 0; j < num_elem;j++) // bucle anidado con el que analizaremos de nuevo el array para comprobar si se repite un digito
        {
            int digit2 = numero[j]; // guardamos la el valor de esta pasada en un variable
            if (digit2 == digit1) // comprobamos que el valor de ambas variables es igual
            {   cont++; // aumentamos el contador si el valor es igual
                if(cont == 2) // si contador vale 2, repeatdigit igual a true, ya que si no se repitiera valdria 1
                    repeatdigit = true;
            }
        }
    }
    return repeatdigit;
}

void rellenarIntento(unsigned int intento, unsigned int intentoDigitos[], const int num_elem)
{   // bucle con el que recorreremos el array, en este caso lo haremos desde la ultima posicion del array hasta la primera, ya que asi nos sera mas facil separar los digitos
    for(int i = num_elem - 1; i >= 0; i--)
    {
        intentoDigitos[i] = intento%10; //la posicion del array sera el modulo del numero introducido por 10, lo que nos ira separando los digitos
        intento = intento / 10; //dividimos el numero entre 10 para que en la siguiente vuelta se coja la siguiente cifra
    }
}

unsigned int calcularAciertos(const unsigned int numSecreto[],const unsigned int intentoDigitos[],const int num_elem)
{
    int correct = 0; // inicializamos una variable para contar los numeros correctos que hay
    for(int i = 0; i < num_elem;i++) // recorremos el array numSecreto[]
    {
        int digit1 = numSecreto[i]; //para cada valor de cada posicion del array lo guardamos en esta variable que usaremos posteriormente para compararla
        for (int j = 0; j < num_elem;j++) //recorremos el array intentoDigitos[]
        {
            int digit2 = intentoDigitos[j]; // guardamos cada valor de cada posicion para luego compararlos
            if ((digit2 == digit1) && (i == j)) // comparamos los valores que tenemos en digit1 y digit2 y si se encuentran en la misma posicion
                correct++; // si se cumplen ambas cosas aumentamos en 1 la variable correct
        }
    }
    return correct;
}


unsigned int calcularSemiaciertos(const unsigned int numSecreto[],const unsigned int intentoDigitos[],const int num_elem)
{
    int semicorrect = 0; // inicializamos una variable para contar los numeros semi-correctos que hay
    for(int i = 0; i < num_elem;i++) // recorremos el array numSecreto[]
    {
        int digit1 = numSecreto[i]; //para cada valor de cada posicion del array lo guardamos en esta variable que usaremos posteriormente para compararla
        for (int j = 0; j < num_elem;j++)//recorremos el array intentoDigitos[]
        {
            int digit2 = intentoDigitos[j];// guardamos cada valor de cada posicion para luego compararlos
            if ((digit2 == digit1) && (i != j)) // comparamos los valores que tenemos en digit1 y digit2 y si se encuentran en distinta posicion
                semicorrect++; //si se cumplen ambas cosas aumentamos en 1 la variable correct
        }
    }
    return semicorrect;
}
