#ifndef MMIND_BASIC_H_INCLUDED
#define MMIND_BASIC_H_INCLUDED


/* Funci�n comprobarDigitosRepetidos():
Devuelve true si 'numero[]' contiene alg�n d�gito repetido, False en caso contrario.
'numero[]' es un array de "num_elem" posiciones,
cada posici�n del array contiene un d�gito del n�mero secreto.
*/
bool comprobarDigitosRepetidos(const unsigned int numero[], const int num_elem);


/* Funci�n rellenarIntento():
Rellena el array de "num_elem" posiciones 'intentoDigitos[]',
de forma que en cada posici�n del array almacena el d�gito correspondiente del n�mero 'intento'.
Por ejemplo, si num_elem=4 e intento=4512, la funci�n debe rellenar el array de la siguiente forma:
intentoDigitos[0] = 4; intentoDigitos[1] = 5; intentoDigitos[2] = 1; intentoDigitos[3] = 2.
*/
void rellenarIntento(unsigned int intento, unsigned int intentoDigitos[], const int num_elem);


/* Funci�n calcularAciertos():
Devuelve el n�mero de d�gitos acertados existente en el array de "num_elem" posiciones 'intentoDigitos[]'
con respecto al array de "num_elem"  posiciones 'numSecreto[]'.
Un d�gito de 'intentoDigitos[]' se considera acertado si coincide el valor y la posici�n del mismo
con respecto a los de 'numSecreto[]'.
Por ejemplo, si numSecreto[] = {1,2,3,4} e intentoDigitos[] = {5,0,3,4}, la funci�n debe devolver el valor 2.
*/
unsigned int calcularAciertos(const unsigned int numSecreto[],
                              const unsigned int intentoDigitos[],
                              const int num_elem);


/* Funci�n calcularSemiaciertos():
Devuelve el n�mero de d�gitos semi-acertados existente en el array de "num_elem" posiciones 'intentoDigitos[]'
con respecto al array de "num_elem" posiciones 'numSecreto[]'.
Un d�gito de 'intentoDigitos[]' se considera semi-acertado si coincide el valor pero no la posici�n del mismo
con respecto a los de 'numSecreto[]'.
Por ejemplo, si numSecreto[] = {1,2,3,4} e intentoDigitos[] = {3,1,0,4}, la funci�n debe devolver el valor 2.
*/
unsigned int calcularSemiaciertos(const unsigned int numSecreto[],
                                  const unsigned int intentoDigitos[],
                                  const int num_elem);


#endif // MMIND_BASIC_H_INCLUDED
