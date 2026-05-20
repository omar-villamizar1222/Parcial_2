#include "../include/Libros.h"
#include <iostream>
#include <stdexcept>

Libro::Libro(const std::string& titulo, const std::string& autor, int CodigoLibro)
    : titulo(titulo), autor(autor), codigoLibro(CodigoLibro),disponible(true) {}

void Libro::mostrarInformacion() const {
    std::cout << "Título: " << titulo << "\n";
    std::cout << "Autor: " << autor << "\n";
    std::cout << "Código del Libro: " << codigoLibro << "\n";
    std::cout << "Disponibilidad: " << (disponible ? "Disponible" : "No Disponible") << "\n";
}

bool Libro::prestarLibro(){
    if (!disponible) return false;{
        disponible = false;
        return true;
    }
}
void Libro::devolverLibro() {
    disponible = true;
}

std::string Libro::getTitulo() const {
    return titulo;
}

std::string Libro::getAutor() const {
    return autor;
}

int Libro::getCodigoLibro() const {
    return codigoLibro;
}

bool Libro::isDisponible() const {
    return disponible;
}
