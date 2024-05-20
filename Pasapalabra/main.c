#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXIMO_JUGADORES 50  // Se definió el máximo de jugadores para el juego
#define CARAC_DE_LOS_NOMBRES 25  // Aquí para el máximo de caracteres del nombre que son 25

char jugadores[MAXIMO_JUGADORES][CARAC_DE_LOS_NOMBRES];
int puntuacion[MAXIMO_JUGADORES];
int numero_jugadores = 0;

void registrar_jugador();
void verificarJugador(char listaJugadores[][CARAC_DE_LOS_NOMBRES], int numero_jugadores);
void puntuaciones();
void jugar();

void registrar_jugador() {
	system("cls");
    char jugador_nuevo[CARAC_DE_LOS_NOMBRES];
    int i;

    printf("\nIngresa el nombre del Jugador: ");
    fgets(jugador_nuevo, CARAC_DE_LOS_NOMBRES, stdin);

    size_t len = strlen(jugador_nuevo);
    if (len > 0 && jugador_nuevo[len - 1] == '\n') {
        jugador_nuevo[len - 1] = '\0';
    }

    for (i = 0; i < numero_jugadores; i++) {
        if (strcmp(jugadores[i], jugador_nuevo) == 0) {
            printf("El nombre %s ya está registrado, por favor ingresa otro nombre.\n", jugador_nuevo);
            return;
        }
    }

    strcpy(jugadores[numero_jugadores], jugador_nuevo);
    puntuacion[numero_jugadores] = 0;
    numero_jugadores++;

    printf("\nRegistro de %s exitoso.\n", jugador_nuevo);

    printf("\nLista de jugadores registrados:\n");
    for (i = 0; i < numero_jugadores; i++) {
        printf("%d. %s\n", i + 1, jugadores[i]);
    }

    verificarJugador(jugadores, numero_jugadores);
}

typedef struct {
    char letra;
    char pregunta[100];
    char respuesta[100];
} Pregunta;

// Función para jugar al Pasapalabra
void jugarPasapalabra(Pregunta *preguntas, int num_preguntas) {
    int i, pasapalabra_count = 0;
    char respuesta_usuario[100];
    char respuesta_correcta[100];
    int respuesta_dada[num_preguntas]; // Array para registrar si se ha dado una respuesta a cada pregunta
    
    // Inicializar el array de respuestas dadas a 0
    for (i = 0; i < num_preguntas; i++) {
        respuesta_dada[i] = 0;
    }
    
    // Iterar a través de todas las preguntas
    for (i = 0; i < num_preguntas; i++) {

        if (!respuesta_dada[i]) {
            printf("Pregunta %d (%c): %s\n", i+1, preguntas[i].letra, preguntas[i].pregunta);
            printf("¿Responder o pasapalabra? (responder/pasapalabra): ");
            scanf("%s", respuesta_usuario);
            int j;
            // Convertir la respuesta del usuario a minúsculas
            for ( j = 0; respuesta_usuario[j]; j++) {
                respuesta_usuario[j] = tolower(respuesta_usuario[j]);
            }
            if (strcmp(respuesta_usuario, "responder") == 0) {
                
                strcpy(respuesta_correcta, preguntas[i].respuesta);
                
                printf("Respuesta: ");
                scanf("%s", respuesta_usuario);
                int j;
                // Convertir la respuesta del usuario a minúsculas
                for (j = 0; respuesta_usuario[j]; j++) {
                    respuesta_usuario[j] = tolower(respuesta_usuario[j]);
                }
                
                if (strcmp(respuesta_usuario, respuesta_correcta) == 0) {
                    printf("¡Respuesta correcta!\n");
                } else {
                    printf("Respuesta incorrecta. La respuesta correcta era: %s\n", respuesta_correcta);
                }
            } else if (strcmp(respuesta_usuario, "pasapalabra") == 0) {
                
                pasapalabra_count++;
                
                if (pasapalabra_count == 3) {
                    printf("Has aplicado 3 pasapalabras. Fin del juego.\n");
                    return;
                }
                printf("Pasapalabra aplicado. Saltando a la siguiente pregunta.\n");
                continue; 
            } else {
                printf("Entrada no válida. Por favor, introduce 'responder' o 'pasapalabra'.\n");
                i--; // Decrementar i para repetir la pregunta
            }
        }

        respuesta_dada[i] = 1;
    }
    printf("Has completado todas las preguntas. ¡Felicidades!\n");
}


void  pasaPalabras(){
    system("cls");
	
	char A = 'A', B = 'B';
	printf(" \n\n\n\n");
	printf("  %c ",B);
	
}
void verificarJugador(char listaJugadores[][CARAC_DE_LOS_NOMBRES], int numero_jugadores) {
	system("cls");
    char nombreJugador[CARAC_DE_LOS_NOMBRES];
    int i;

    printf("Escribe tu usuario: ");
    fgets(nombreJugador, sizeof(nombreJugador), stdin);

    size_t len = strlen(nombreJugador);
    if (len > 0 && nombreJugador[len - 1] == '\n') {
        nombreJugador[len - 1] = '\0';
    }

    for (i = 0; i < numero_jugadores; i++) {
        if (strcmp(listaJugadores[i], nombreJugador) == 0) {
            printf("Bienvenido, %s!\n", nombreJugador);
            pasaPalabras();
        }else{
        	printf(" No estas registrado!\n");
        	
		}
    }


}

void puntuaciones() {
    printf("Función de puntuaciones no implementada aún.\n");
}

void jugar() {
    verificarJugador(jugadores, numero_jugadores);
    
    
}



void menu() {
	system("cls");
    int opcion;  // La opción nos va ayudar para que escojan el camino que quieran tomar
    do {
        printf("\n\n\nMenu Principal Pasa La Palabra: \n");
        printf("\n1. Registrar Jugadores.\n");
        printf("2. Verificar las puntuaciones.\n");
        printf("3. Jugar.\n");
        printf("4. Salir del Juego.\n");
        printf("\nIngresa tu opción: ");
        scanf("%d", &opcion);  // Aquí se guarda la variable opción
        getchar();  // Consumir el salto de línea restante del buffer

        switch (opcion) {  // Aquí se usó un switch para cada opción del menú
            case 1:  // Aquí el caso 1, Registro de los jugadores
                registrar_jugador();
                break;

            case 2:  // Aquí el caso 2, Las puntuaciones
                puntuaciones();
                break;

            case 3:  // Aquí el caso 3, Jugar
                jugar();
                break;

            case 4:  // Aquí el caso 4, la salida de juego
                printf("\nGracias por jugar Pasa la Palabra!\n");
                break;

            default:  // Y por último el default, que es cuando selecciona una opción que no está en el menú
                printf("\nOpción no válida, por favor inténtalo de nuevo con el número de opciones mostradas :)\n");
                break;
        }
    } while (opcion != 4);  // Aquí se usó un bucle, para que puedan viajar en el menú sin salir del programa
}



int main() {
    menu();
    return 0;
}
