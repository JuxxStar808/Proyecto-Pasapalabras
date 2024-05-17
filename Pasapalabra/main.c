#include <stdio.h>
#include <string.h>

#define MAXIMO_JUGADORES 50  // Se definió el máximo de jugadores para el juego
#define CARAC_DE_LOS_NOMBRES 25  // Aquí para el máximo de caracteres del nombre que son 25

char jugadores[MAXIMO_JUGADORES][CARAC_DE_LOS_NOMBRES];  // Aquí se usaron arreglos para los jugadores y los nombres
int puntuacion[MAXIMO_JUGADORES];  // Otro arreglo para almacenar las puntuaciones
int numero_jugadores = 0;  // Se inicia en cero para el orden de los jugadores...jugador1....jugador2...

void registrar_jugador() {
    char jugador_nuevo[CARAC_DE_LOS_NOMBRES];  // Aquí se almacenarán los jugadores
    int i;  // La i es un contador para usarlo en for

    printf("\nIngresa el nombre del Jugador: ");
    fgets(jugador_nuevo, CARAC_DE_LOS_NOMBRES, stdin);  // Aquí almacena el jugador, no es necesario agregar & ya que son caracteres

    // Eliminar el salto de línea al final del nombre ingresado
    size_t len = strlen(jugador_nuevo);
    if (len > 0 && jugador_nuevo[len - 1] == '\n') {
        jugador_nuevo[len - 1] = '\0';
    }

    for (i = 0; i < numero_jugadores; i++) {  // Aquí verifica que no se repitan los nombres
        if (strcmp(jugadores[i], jugador_nuevo) == 0) {  // Aquí se hace una comparación de los nombres, por si vuelven a poner el mismo
            printf("El nombre %s ya está registrado, por favor ingresa otro nombre.\n", jugador_nuevo);
            return;
        }
    }

    // Esto solo es cuando se ingresa un nombre que ya estaba registrado o bien que se encuentra repetido, es para lo único que sirve

    strcpy(jugadores[numero_jugadores], jugador_nuevo);  // Función que copia las cadenas
    puntuacion[numero_jugadores] = 0;  // Aquí se establece la puntuación 0, si se repitió el nombre y se necesita crear otro
    numero_jugadores++;

    printf("\nRegistro de %s exitoso.\n", jugador_nuevo);  // Aquí le aparecerá al jugador su nombre, confirmando así su registro exitoso

    // Mostrar la lista de jugadores registrados hasta ahora
    printf("\nLista de jugadores registrados:\n");
    for (i = 0; i < numero_jugadores; i++) {
        printf("%d. %s\n", i + 1, jugadores[i]);
    }
}

void puntuaciones() {
    // Aquí va la implementación de la función para mostrar las puntuaciones
    printf("Función de puntuaciones no implementada aún.\n");
}

void jugar() {
    // Aquí va la implementación de la función para jugar
    printf("Función de jugar no implementada aún.\n");
}

void menu() {
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



