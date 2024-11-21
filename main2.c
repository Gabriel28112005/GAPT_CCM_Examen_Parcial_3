#include<string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    ASISTIO,
    FALTA,
    TARDANZA
} EstadoAsistencia; // Enumeración para el estado de la asistencia


struct Asistencia {
    char fecha[11];        // Fecha en formato dd/mm/aaaa
    char materia[50];      // Nombre de la materia
    EstadoAsistencia estado; // Estado de la asistencia (asistió, falta, tardanza)
};


struct Estudiante
{
    char nombre[50];
    int edad;
    float promedio;
    struct Asistencia* asistencias;  // Lista dinámica de asistencias
    int numAsistencias;              // Número de asistencias registradas
    char materias[3][50];
};

// Función para mostrar los datos del estudiante (Chat gpt)

void mostrarEstudiante(struct Estudiante est) {
    printf("Nombre: %s\n", est.nombre);
    printf("Edad: %d\n", est.edad);
    printf("Promedio: %.2f\n", est.promedio);
    printf("Materias: ");
    for (int i = 0; i < 3; ++i) {
        printf("%s ", est.materias[i]);
    }
    printf("\n");
}

// Función para agregar materia
void agregarMateria(struct Estudiante* est, int index, const char* materia) {
    if (index >= 0 && index < 3) {
        strcpy(est->materias[index], materia);
    }
}

// Función para registrar una nueva asistencia
void registrarAsistencia(struct Estudiante* est, const char* fecha, const char* materia, EstadoAsistencia estado) {
    // Realocamos memoria para la nueva asistencia
    est->asistencias = realloc(est->asistencias, (est->numAsistencias + 1) * sizeof(struct Asistencia));

    // Asignamos los valores a la nueva asistencia
    strcpy(est->asistencias[est->numAsistencias].fecha, fecha);
    strcpy(est->asistencias[est->numAsistencias].materia, materia);
    est->asistencias[est->numAsistencias].estado = estado;

    // Incrementamos el número de asistencias
    est->numAsistencias++;
}

// Función para mostrar todas las asistencias de un estudiante

void mostrarAsistencias(struct Estudiante est) {
    printf("Asistencias de %s:\n", est.nombre);
    for (int i = 0; i < est.numAsistencias; i++) {
        printf("Fecha: %s | Materia: %s | Estado: ", est.asistencias[i].fecha, est.asistencias[i].materia);

        // Mostrar el estado según el valor de la enumeración

        switch (est.asistencias[i].estado) {
        case ASISTIO:
            printf("Asistio\n");
            break;
        case FALTA:
            printf("Falta\n");
            break;
        case TARDANZA:
            printf("Tardanza\n");
            break;
        }
    }
}

// Función para liberar la memoria de las asistencias

void liberarAsistencias(struct Estudiante* est) {
    free(est->asistencias);
}

char nombreEst[50];

int main()
{
     // Pedir el nombre del estudiante
    printf("Ingresa el nombre del estudiante: ");
    fgets(nombreEst, sizeof(nombreEst), stdin);
    nombreEst[strcspn(nombreEst, "\n")] = '\0';  // Eliminar salto de línea

    // Verificar si el estudiante es Gabriel o Carlos
    if (strcmp(nombreEst, "Gabriel") == 0) {
        struct Estudiante estudianteGabriel = {"Gabriel", 19, 9.2, NULL, 0};

        // Agregar materias
        agregarMateria(&estudianteGabriel, 0, "Matematicas");
        agregarMateria(&estudianteGabriel, 1, "Fisica");
        agregarMateria(&estudianteGabriel, 2, "Programacion");

        // Mostrar los datos del estudiante
        mostrarEstudiante(estudianteGabriel);

        // Registrar asistencias
        registrarAsistencia(&estudianteGabriel, "12/10/2024", "Matematicas", ASISTIO);
        registrarAsistencia(&estudianteGabriel, "13/10/2024", "Fisica", FALTA);

        // Mostrar las asistencias de Gabriel
        mostrarAsistencias(estudianteGabriel);

        // Liberar memoria
        liberarAsistencias(&estudianteGabriel);
    }
    else if (strcmp(nombreEst, "Carlos") == 0) {
        struct Estudiante estudianteCarlos = {"Carlos", 18, 8.5, NULL, 0};

        // Agregar materias
        agregarMateria(&estudianteCarlos, 0, "Matematicas");
        agregarMateria(&estudianteCarlos, 1, "Fisica");
        agregarMateria(&estudianteCarlos, 2, "Programacion");

        // Mostrar los datos del estudiante
        mostrarEstudiante(estudianteCarlos);

        // Registrar algunas asistencias
        registrarAsistencia(&estudianteCarlos, "12/10/2024", "Matematicas", ASISTIO);
        registrarAsistencia(&estudianteCarlos, "13/10/2024", "Fisica", FALTA);
        registrarAsistencia(&estudianteCarlos, "14/10/2024", "Programacion", TARDANZA);

        // Mostrar las asistencias de Carlos
        mostrarAsistencias(estudianteCarlos);

        // Liberar memoria
        liberarAsistencias(&estudianteCarlos);
    } else {
        // Si el nombre no es ni Gabriel ni Carlos
        printf("El estudiante ingresado no se encuentra matriculado\n");
    }
    return 0;
}