#include <stdio.h>
#include <string.h>
void menu()
{
	int opcion;											//La opcion nos va ayudar para que escogan el camino que quieran tomar
    do
{ printf("\n\n\nMenu Principal Pasa La Palabra: ");
  printf("1. Registrar Jugadores.\n");
  printf("2. Verificar las puntaciones.\n");
  printf("3. Juega.\n");
  printf("4. Salir del Juego.\n");
  printf("Ingresa tu opcion: ");
  	scanf("%d",&opcion);											//Aqui se guarda la variable opcion

	switch (opcion){										//Aqui se uso un swicht para cada opcion del menu							
												
		case 1:										//Aqui el caso 1, Registro de los jugadores
		registrar_jugador();							
		break;

		case 2:										//Aqui el caso 2, Las puntuaciones
		puntuaciones();
		break;

		case 3:										//Aqui el caso 3, Jugar
		jugar();
		break;

		case 4:												//Aqui el caso 4, la salida de juego
		printf("\nGracias por jugar Pasa la Palabra!\n");
		break;

		default:											//Y por ultimo el default, que es cuando selecciona una opcion que no esta en el menu
		printf("\nOpcion no valida, porfavor intentalo de nuevo con el numero de opciones mostradas:)\n");
		break;
				}
	} while (opcion!=4);							//Aqui se uso un bucle, para que puedan viajar en el menu sin salir del programa
}



#define maximo_jugadores 50							//Se definio el el maximo de jugadores para el juego			
#define carac_delos_nombres 25						//Aqui para el maximo de caracteres del nombre que son 25

char jugadores[maximo_jugadores][carac_delos_nombres];		//Aqui se  uso arreglos para los jugadores y los nombres
int puntuacion[maximo_jugadores];							//Otro arrgelo para almacenar las puntuaciones
int numero_jugadores= 0;								//Se inicia en cero para el orden de los jugadores...jugador1....jugador2...

void registrar_jugador()
{
	char jugador_nuevo[carac_delos_nombres];				//Aqui se almacenaran los jugadores
	int i;												//La i es un contador para usarlo en for

		printf("\nIngresa el nombre del Jugador: ");
		fgets("%s", jugador_nuevo);						//Aqui almacena el jugador, no es necesario agregar & ya que son caracteres

		for(i=0; i<numero_jugadores; i++){				//Aqui verifica que no se repitan los nombres
			if(strcmp(jugadores[i], jugador_nuevo)==0){			//Aqui se hace una comparacion de los nombres, por que vuelven a pner el mismo
				printf("El nombre %s ya esta registrado, porfavor ingresa otro nombre.\n",jugador_nuevo);
				return;
			}
		}

		//Esto solo es cuando se ingresa un nombre que ya estaba registrado o bien que se encuentra repetido, es para lo unico que sirve

	strcpy(jugadores[numero_jugadores], jugador_nuevo);   //Funcion que copea las cadenas
	puntuacion[numero_jugadores]=0;						 //Aqui se establece la puntuacion 0, si se repitio el nombre y se necesita crear otro
	numero_jugadores++;

	printf("\nRegistro de %s exitoso.\n",jugador_nuevo);  //Aqui le aparecera al jugar su nombre y confirmando asi su registro exitoso

}



