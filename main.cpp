#include <iostream>
#include <string>
#include "Clases_Cpp/Clases.h"

std::string identificacion;

int main()
{
    std::cout << "Ingrese el nombre del estudiante: "; std::cin>>identificacion;

    try {
        if (identificacion == "Gabriel") {
            // Crear un estudiante
            Estudiante estudiante1("Gabriel", 19, 9.2);

            // Mostrar datos del estudiante
            estudiante1.mostrarEstudiante();

            // Agregar materias
            estudiante1.agregarMateria("Matematicas");
            estudiante1.agregarMateria("Fisica");
            estudiante1.agregarMateria("Programacion");

            // Mostrar materias
            estudiante1.mostrarMaterias();

            // Registrar asistencias
            estudiante1.registrarAsistencia("2024-11-19", "Matematicas", "Asistio");
            estudiante1.registrarAsistencia("2024-11-21", "Programacion", "Tardanza");
            estudiante1.registrarAsistencia("2024-11-20", "Historia", "Falta");

            // Mostrar asistencias
            estudiante1.mostrarAsistencias();

            // Intentar eliminar una materia inexistente
            estudiante1.eliminarMateria("Historia");

            // Intentar registrar asistencia para una materia no inscrita
            estudiante1.registrarAsistencia("2024-11-22", "Fisica", "Asistio");

        }
        else if (identificacion == "Carlos") {
            // Crear un estudiante
            Estudiante estudiante2("Carlos", 18, 8.5);

            // Mostrar datos del estudiante
            estudiante2.mostrarEstudiante();

            // Agregar materias
            estudiante2.agregarMateria("Matematicas");
            estudiante2.agregarMateria("Fisica");
            estudiante2.agregarMateria("Programacion");

            // Mostrar materias
            estudiante2.mostrarMaterias();

            // Registrar asistencias
            estudiante2.registrarAsistencia("2024-11-19", "Matematicas", "Asistio");
            estudiante2.registrarAsistencia("2024-11-21", "Programacion", "Tardanza");
            estudiante2.registrarAsistencia("2024-11-20", "Historia", "Falta");

            // Mostrar asistencias
            estudiante2.mostrarAsistencias();

            // Intentar eliminar una materia inexistente
            estudiante2.eliminarMateria("Historia");

            // Intentar registrar asistencia para una materia no inscrita
            estudiante2.registrarAsistencia("2024-11-22", "Fisica", "Asistio");

        }
        else {
            std::cout << identificacion << " no se encuentra en la base de datos de alumnos.\n Por favor, ingrese otro nombre." << std::endl;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}