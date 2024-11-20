#include <iostream>
#include <string>
#include <list>
#include "Clases_Cpp/Clases.h"

int main() {
    try {
        // Crear un estudiante
        Estudiante estudiante1("Juan Perez", 20, 8.75);

        // Mostrar datos del estudiante
        estudiante1.mostrarEstudiante();

        // Agregar materias
        estudiante1.agregarMateria("Matematicas");
        estudiante1.agregarMateria("Historia");
        estudiante1.agregarMateria("Programacion");

        // Mostrar materias
        estudiante1.mostrarMaterias();

        // Registrar asistencias
        estudiante1.registrarAsistencia("2024-11-19", "Matematicas", "Asistio");
        estudiante1.registrarAsistencia("2024-11-20", "Historia", "Falta");
        estudiante1.registrarAsistencia("2024-11-21", "Programacion", "Tardanza");

        // Mostrar asistencias
        estudiante1.mostrarAsistencias();

        // Intentar eliminar una materia inexistente
        estudiante1.eliminarMateria("Fisica");

        // Intentar registrar asistencia para una materia no inscrita
        estudiante1.registrarAsistencia("2024-11-22", "Fisica", "Asistio");

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
