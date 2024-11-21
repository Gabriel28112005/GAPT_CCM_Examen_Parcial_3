//
// Created by gapt2 on 20/11/2024.
//

#ifndef CLASES_H
#define CLASES_H

#include <iostream>
#include <string>
#include <list>
#include <algorithm> // Para std::find
#include <exception> // Para std::exception

// Excepción personalizada para materia no encontrada (Hecha por ChatGPT)
class MateriaNoEncontrada : public std::exception {
private:
    std::string mensaje;
public:
    MateriaNoEncontrada(const std::string &materia)
        : mensaje("La materia \"" + materia + "\" no se encuentra en la lista.") {}

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

// Excepción personalizada para asistencia a materia no inscrita (Hecha por ChatGPT)
class MateriaNoInscrita : public std::exception {
private:
    std::string mensaje;
public:
    MateriaNoInscrita(const std::string &materia)
        : mensaje("No se puede registrar asistencia. La materia \"" + materia + "\" no esta inscrita.") {}

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

// Clase Asistencia
class Asistencia {
private:
    std::string fecha;
    std::list<char> materia; // Cambiado a lista de caracteres
    std::string estado;      // Asistió, Falta, Tardanza

    // Función para convertir std::string a std::list<char>
    std::list<char> stringToList(const std::string &str) {
        return std::list<char>(str.begin(), str.end());
    }

    // Función para convertir std::list<char> a std::string (para mostrar)
    std::string listToString(const std::list<char> &charList) const {
        return std::string(charList.begin(), charList.end());
    }

public:
    // Constructor
    Asistencia(const std::string &f, const std::string &m, const std::string &e)
        : fecha(f), materia(stringToList(m)), estado(e) {}

    // Mostrar los detalles de la asistencia
    void mostrarAsistencia() const {
        std::cout << "Fecha: " << fecha << ", Materia: " << listToString(materia)
                  << ", Estado: " << estado << std::endl;
    }

    // Obtener materia asociada como lista de caracteres
    std::list<char> obtenerMateria() const {
        return materia;
    }
};

// Clase Estudiante
class Estudiante {
private:
    std::string nombre;
    int edad;
    float promedio;
    std::list<std::string> materias; // Lista para almacenar las materias
    std::list<Asistencia> asistencias; // Lista para registrar las asistencias

public:
    // Constructor
    Estudiante(const std::string &n, int e, float p)
        : nombre(n), edad(e), promedio(p) {}

    // Función para mostrar los datos del estudiante
    void mostrarEstudiante() {
        std::cout << "El nombre del estudiante es: " <<nombre<< std::endl;
        std::cout << "La edad del estudiante es: " <<edad<< std::endl;
        std::cout << "El promedio del estudiante es: " <<promedio<< std::endl;
    }

    // Función para mostrar las materias (Hecho con ChatGPT)
    void mostrarMaterias() {
        if (materias.empty()) { //condición de que ejecute el siguiente código en caso de que no hayan materias.
            std::cout << "El estudiante no está inscrito en ninguna materia." << std::endl;
            return;
        }

        std::cout << "Materias inscritas:" << std::endl;
        int i = 1;
        for (const auto &materia : materias) {
            std::cout << i++ << ". " << materia << std::endl;
        }
    }

    // Función para agregar una materia (Hecho con ChatGPT)
    void agregarMateria(const std::string &materia) {
        materias.push_back(materia);
        std::cout << "La materia \"" << materia << "\" ha sido agregada correctamente." << std::endl;
    }

    // Función para eliminar una materia por nombre (Hecho con ChatGPT)
    void eliminarMateria(const std::string &materia) {
        auto it = std::find(materias.begin(), materias.end(), materia);
        if (it == materias.end()) {
            throw MateriaNoEncontrada(materia);
        }
        materias.erase(it);
        std::cout << "La materia \"" << materia << "\" ha sido eliminada correctamente." << std::endl;
    }

    // Función para registrar asistencia (Hecho con ChatGPT)
    void registrarAsistencia(const std::string &fecha, const std::string &materia, const std::string &estado) {
        auto it = std::find(materias.begin(), materias.end(), materia);
        if (it == materias.end()) {
            throw MateriaNoInscrita(materia);
        }

        asistencias.emplace_back(fecha, materia, estado);
        std::cout << "Asistencia registrada: " << fecha << ", Materia: " << materia << ", Estado: " << estado << std::endl;
    }

    // Función para mostrar todas las asistencias
    void mostrarAsistencias() {
        if (asistencias.empty()) {
            std::cout << "No hay registros de asistencia." << std::endl;
            return;
        }

        std::cout << "Registros de asistencia:" << std::endl;
        for (const auto &asistencia : asistencias) {
            asistencia.mostrarAsistencia();
        }
    }
};

#endif //CLASES_H
