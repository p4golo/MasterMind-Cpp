#include <iostream>
using namespace std;
#include "mmind_basic.h"
#include "modulo1.h"
#include <ctime>
#include <cstdlib>

void print_if(void)
{   //con esta funcion printeamos en pantalla los distintos niveles para jugar
    cout << "Estas son las dificultades disponibles: " << endl;
    cout << "1.Nivel basico(3 digitos,0-4,6 intentos)" << endl;
    cout << "2.Nivel intermedio(4 digitos,0-5,8 intentos)" << endl;
    cout << "3.Nivel dificil(5 digitos,0-9,10 intentos)" << endl;

}

int level(void)
{ // en esta funcion preguntamos al usuario el nivel en el que quiere jugar
    int level; //declaramos una variable para almacenar el nivel
    do //preguntamos la dificultad hasta obtener un numero entre 0 y 3
    {
        cout << "Introduce la dificultad en la que quieres jugar:" << endl;
        cin >> level;
    }while ((level<=0)|| (level > 3));
    return level;
}

bool repeats(void)
{ // en esta funcion preguntamos al usuario si quiere que el codigo pueda tener numeros repetidod
    bool repeat; // declaramos una variable para guardar la decision
    int decision; // declaramos otra variable para guardar la respuesta introducida
    do //preguntamos hasta que se introduzca un numero valido(0-1)
    {
        cout << "El numero a adivinar puede tener numeros repetidos? " << endl;
        cout << "1-Si"<< endl;
        cout << "0-No"<< endl;
        cin >> decision;
    }while ((decision < 0)|| (decision > 1));
// comparamos la decision introducida
    if (decision == 0) // si es 0 el usuario no quiere que haya numeros repetidos
        repeat = false;
    else // si no es 0 solo queda 1 y en ese caso el usuario si quiere que pueda haber numeros repetidos
        repeat = true;
    return repeat;
}

void random_code(unsigned int code[],bool repeat,int lenght,int values)
{
    srand(time(NULL)); // anulamos el tiempo de la funcion rand() para que los numeros que salgan sean 100% aleatorios
    switch(repeat) // para los dos posibles valores, creamos la contraseña con digitos repetidos o no
    {
        case true: // en el caso de true al usuario no le importa que haya numeros repetidos
            for(int i = 0; i < lenght; i++) //recorremos el array code[]
                code[i]= rand() % values; // y para cada posicion del array introducimos un valor aleatorio segun el nivel especificado
            break;
        case false: // en el caso de false, el usuario no quiere numeros repetidos
            do //le damos valores a cada posicion del array
            {
                for(int i = 0; i < lenght; i++) // recorremos el array code[]
                    code[i]= rand() % values; // para cada posicion del array asignamos un numero aleatorio segun el nivel especificado

            }while (comprobarDigitosRepetidos(code,lenght)); // hasta que la funcion comprobarDigitosRepetidos() sea false
            break;
    }
}

int lenghtCode(int level) // esta funcion devuelve la longitud del codigo
    {
        int length = 0; //inicializamos la variable longitud a 0
        switch (level) // segun el nivel introducido se asigna el valor de la longitud
        {
            case 1:
                length = 3;
                break;
            case 2:
                length = 4;
                break;
            case 3:
                length = 5;
                break;
        }
        return length;
    }

int values(int level) // esta funcion devuelve los valores posibles de los digitos del codigo
    {
        int values = 0; //inicializamos la variable values a 0
        switch (level) // segun el nivel introducido se asigna el valor de los posibles valores
        {
            case 1:
                values = 5;
                break;
            case 2:
                values = 6;
                break;
            case 3:
                values = 10;
                break;
        }
        return values;
    }

int opportunities(int level) // esta funcion devuelve las oportunidades que tiene el usuario para adivinar el codigo
    {
        int opportunities = 0; //inicializamos la variable opportunities a 0
        switch (level) // segun el nivel asignamos la cantidad de oportunidades
        {
            case 1:
                opportunities = 6;
                break;
            case 2:
                opportunities = 8;
                break;
            case 3:
                opportunities = 10;
                break;
        }
        return opportunities;
    }

 void game(unsigned int code[],unsigned int digitTries[],int length,int opportunities) // esta funcion ejecuta el juego hasta que se gane o se acaben las oportunidades
 {
     bool finish = false; // inicializamos la variable finish que usaremos para salir del bucle cuando se gana y para saber si se gana o pierde
     unsigned int number; // inicializamos la variable donde almacenaremos el valor del numero introducido
     int trynumber = 0; // contador para guardar las veces que se ha intentado introducir la clave
     while((trynumber <= opportunities) && !(finish)) // se ejecuta el bucle hasta que se hayan consumido las oportunidades o se gane
    {
        cout << "Introduce un numero dentro de los rangos de la dificultad elegida: "<<endl;
        cin >> number; // solicitud del numero del intento
        rellenarIntento( number,digitTries, length); // rellena el array digitTries[] con el numero introducido
        int corrects = calcularAciertos(code,digitTries,length); //calcula los aciertos
        int semicorrects = calcularSemiaciertos(code,digitTries,length); //calcula los semi-aciertes
        cout << "Numero de aciertos: "<< corrects << endl; // imprime el numero de aciertos
        cout << "Numero de semi-aciertos: "<< semicorrects << endl; //imprime el numero de semi-aciertos
        trynumber++; // aumentamos el contador de intentos
        if (corrects == length) // comprobamos si el valor de correctos es igual a la longitud del array
            finish = true; // asignamos al finish true ya que todos los numeros son correctos, por lo tanto el usuario gana y acaba el bucle
     }
    if (finish == true) // comprobamos si ha ganado o ha perdido
        cout << "Has ganado"<< endl;
    else
        cout << "Has perdido"<< endl;
    printCode(code,length); // imprimimos el codigo
}

void printCode(unsigned int code[],int length) // esta funcion imprime el valor de un array, uno seguido de otro
{
    cout<< "El codigo era el numero: " ;
    for(int i = 0; i < length; i++)
        cout<< code[i];
}

