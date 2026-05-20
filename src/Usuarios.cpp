#include "../include/Usuarios.h"
#include <iostream>

Usuario::Usuario(const std::string& nombre, const std::string& documento,
                 int edad, int codigoUsuario)
    : Persona(nombre, documento, edad),
      codigoUsuario(codigoUsuario),
      cantidadLibrosPrestados(0) {}

void Usuario::mostrarRol() const {
    std::cout << "  Rol: Usuario\n";
}

void Usuario::mostrarInformacion() const {
    std::cout << "=== USUARIO ===\n";
    Persona::mostrarInformacion();
    std::cout << "  Código Usuario    : " << codigoUsuario           << "\n"
              << "  Libros Prestados  : " << cantidadLibrosPrestados  << "\n";
    mostrarRol();
}

int  Usuario::getCodigoUsuario()          const { return codigoUsuario; }
int  Usuario::getCantidadLibrosPrestados() const { return cantidadLibrosPrestados; }
void Usuario::incrementarPrestamos()             { cantidadLibrosPrestados++; }
void Usuario::decrementarPrestamos()             { if (cantidadLibrosPrestados > 0) cantidadLibrosPrestados--; }



