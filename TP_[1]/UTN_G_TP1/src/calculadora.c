#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * @fn void mostrarMenu()
 * @brief
 * Por una cuestión estética, desarrollé el menú del tp, en una función, que a su vez, recibirá otras funciones.
 * Las variables del menú, solamente son bandera y opción.
 * La bandera, simplemente forma parte de una condición y esta solamente cambia de valor en el case 5, en este caso, "Salir".
 * La función menú, recibirá, 7 funciones.
 *
 */
void mostrarMenu(){

int bandera = 0;
int opcion;
float primerOperando = 0;
float segundoOperando = 0;
float resultadoSuma;
float resultadoResta;
float resultadoMultiplicacion;
float resultadoDivision;
float resultadoPrimerFactorial;
float resultadoSegundoFactorial;

float pedirOperando();
float suma(float a, float b);
float resta(float a, float b);
float multiplicacion(float a, float b);
float division(float a, float b);
float factorial(float numero);
void mostrarResultados(float suma,float resta,float multiplicacion,float division, float resPrimFact, float resSegFact, float primerOperando, float segundoOperando);

while(bandera == 0){

	do{
			printf("\n1) Ingresar primer operando A = %.0f",primerOperando);
			printf("\n2) Ingresar segundo operando A = %.0f",segundoOperando);
			printf("\n3) Calcular todas las operaciones");
			printf("\n4) Informar resultados");
			printf("\n5) Salir\n");
			printf("\nIngrese una opcion. ");
			scanf("%i", &opcion);

			if(opcion <= 0 || opcion > 5){
				printf("ERROR, Ingrese las opciones del 1 al 5");
			}
		}while(opcion <= 0 || opcion > 5 || bandera == 1);

		switch(opcion){

		case 1:
			primerOperando = pedirOperando();
			break;
		case 2:
			segundoOperando = pedirOperando();
			break;
		case 3:
			resultadoSuma = suma(primerOperando,segundoOperando);
			resultadoResta = resta(primerOperando,segundoOperando);
			resultadoMultiplicacion = multiplicacion(primerOperando,segundoOperando);

			if(segundoOperando != 0){
				resultadoDivision = division(primerOperando,segundoOperando);
			}

			resultadoPrimerFactorial = factorial(primerOperando);
			resultadoSegundoFactorial = factorial(segundoOperando);
			break;
		case 4:
			mostrarResultados(resultadoSuma,resultadoResta,resultadoMultiplicacion,resultadoDivision, resultadoPrimerFactorial, resultadoSegundoFactorial, primerOperando,segundoOperando);
			break;

		case 5:
			bandera = 1;
		}
	}
}

/**
 * @fn float pedirOperando()
 * @brief
 * Funcion que pide un numero. Es utilizada en el case 1 y 2.
 * @return devuelve el mismo numero
 */
float pedirOperando(){

	float numero;
	printf("\nIngrese un numero");
	scanf("%f", &numero);

	return numero;
}

/**
 * @fn float suma(float, float)
 * @brief
 * Recibe dos valores, y los suma
 * @param a
 * @param b
 * @return devuelve el resultado de la suma
 */

float suma(float a, float b) {
	float suma;
	suma = a + b;
	return suma;
}


/**
 * @fn float resta(float, float)
 * @brief
 * Recibe 2 valores y los resta
 * @param a
 * @param b
 * @return devuelve el resultado de la resta
 */
float resta(float a, float b) {
	float resta;
	resta = a - b;
	return resta;
}

/**
 * @fn float multiplicacion(float, float)
 * @brief
 * Recibe dos valores y los multiplica
 * @param a
 * @param b
 * @return devuelve el resultado de la multiplicacion
 */

float multiplicacion(float a, float b){
	float multiplicacion;
	multiplicacion = a * b;
	return multiplicacion;
}

/**
 * @fn float division(float, float)
 * @brief
 * Recibe dos parametros solamente si el segundo operador es distinto de cero y los divide
 * @param a
 * @param b
 * @return
 */
float division(float a, float b){
		float resultado;
		resultado = a/b;
		return resultado;
}

/**
 * @fn float factorial(float)
 * @brief
 * Funcion factorial con uso de recursividad, ya que se llama dentro de la funcion. Nos permite crear factoriales, recibiendo un solo numero. Se llama dos veces.
 * @param numero
 * @return revuelve el resultado
 */

float factorial(float numero)  {
	float resultado;
	if (numero < 2) {
		return 1;
	}
	resultado = factorial(numero - 1) * numero;
	return resultado;
}

/**
 * @fn void mostrarResultados(float, float, float, float, float, float, float, float)
 * @brief
 * Recibe los resultados de todas las operaciones, y los muestra. En caso de que el divisor sea cero, muestra un mensaje de error.
 * @param suma
 * @param resta
 * @param multiplicacion
 * @param division
 * @param resultadoPrimerFactorial
 * @param resultadoSegundoFactorial
 * @param primerOperando
 * @param segundoOperando
 */
void mostrarResultados(float suma,float resta,float multiplicacion,float division, float resultadoPrimerFactorial, float resultadoSegundoFactorial,  float primerOperando, float segundoOperando){

	printf("\nEl resultado de la suma entre %.0f y %.0f es igual a %.0f",primerOperando, segundoOperando, suma);
	printf("\nEl resultado de la resta entre %.0f y %.0f es igual a %.0f",primerOperando, segundoOperando, resta);
	printf("\nEl resultado de la multiplicacion entre %.0f y %.0f es igual a %.0f",primerOperando, segundoOperando, multiplicacion);
	if(segundoOperando == 0){
		printf("\n No se puede dividir por cero");
	}else{
		printf("\nEl resultado de la division entre %.0f y %.0f es igual a %f",primerOperando, segundoOperando, division);
	}
	if(segundoOperando < 0){
		printf("\nEl factorial de %.0f es %.0f y el factorial de %.0f No se realiza porque no se pueden negativos", primerOperando, resultadoPrimerFactorial, segundoOperando);
	}else{
		printf("\nEl factorial de %.0f es %.0f y El factorial de %.0f es %.0f\n",primerOperando, resultadoPrimerFactorial, segundoOperando, resultadoSegundoFactorial );
	}
}



