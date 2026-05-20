#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <stdexcept>

#include "include/persona.h"
#include "include/Usuarios.h"
#include "include/Bibliotecarios.h"
#include "include/Libros.h"

// ---helpers----

/**
 * @brief limpiar el buffer de entrada y lee una linea
 */
std::string leerLinea(const std::string& prompt){

    std::string valor;
    std::cout << prompt;
    std::getline(std::cin,valor);
    return valor;
}

/**
 * @brief Lee un entero; lanza std::invalid_argument si hay letras.
 */
int leerEntero(const std::string& prompt){
    std::string entrada;
    std::cout << prompt;
    std::getline(std::cin, entrada);
    for (char c : entrada) {
        if (!std::isdigit(c)) {
            throw std::invalid_argument("Entrada no es un número válido.");
        }
    }
    return std::stoi(entrada);    
}

/**
 * @brief busca un libro por codigo; lanza std::runtime_error si no se encuentra.
 */
Libro* buscarLibro(std::vector<Libro>& libros, int codigo) {
    for (auto& l : libros)
        if (l.getCodigoLibro() == codigo) return &l;
    return nullptr;
}

/**
 * @brief busca un usuario por codigo; lanza std::runtime_error si no se encuentra.
 */
Usuario* buscarUsuario(std::vector<Usuario>& usuarios, int codigo) {
    for (auto& u: usuarios) 
        if (u.getCodigoUsuario() == codigo) return &u;
    return nullptr;
}

//---funciones de menu---

void registrarUsuario(std::vector<Usuario>& usuarios){
    std::cout << "Registrar nuevo usuario" << std::endl;
    try {
        std::string nombre = leerLinea("Nombre: ");
        std::string doc = leerLinea("documento: ");
        int edad = leerEntero("Edad: ");
        int codigo = leerEntero("Codigo de usuario: ");
        usuarios.emplace_back(nombre, doc, edad, codigo);
        std::cout << "Usuario registrado exitosamente." << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what()<< "\n";
    }
}

void registrarBibliotecario(std::vector<Bibliotecarios>& bibliotecarios){
    std::cout << "Registrar nuevo bibliotecario" << std::endl;
    try {
        std::string nombre = leerLinea("Nombre: ");
        std::string doc = leerLinea("documento: ");
        int edad = leerEntero("Edad: ");
        int codigo = leerEntero("Codigo de bibliotecario: ");
        std::string salStr = leerLinea("Salario: ");
        double salario = std::stod(salStr);
        bibliotecarios.emplace_back(nombre, doc, edad, codigo, salario);
        std::cout << "Bibliotecario registrado exitosamente." << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what()<< "\n";
    }
}

void registrarLibro(std::vector<Libro>& libros){
    std::cout << "Registrar nuevo libro" << std::endl;
    try {
        std::string titulo = leerLinea("Titulo: ");
        std::string autor = leerLinea("Autor: ");
        int codigo = leerEntero("Codigo de libro: ");
        libros.emplace_back(titulo, autor, codigo);
        std::cout << "Libro registrado exitosamente." << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what()<< "\n";
    }
}

void prestarLibro(std::vector<Usuario>& usuarios, std::vector<Libro>& libros){
    std::cout << "Prestar libro" << std::endl;
    try {
        int codLib = leerEntero("Codigo de libro a prestar: ");
        int codUser = leerEntero("Codigo de usuario: ");
        
        Libro* libro = buscarLibro(libros, codLib);
        Usuario* usuario = buscarUsuario(usuarios, codUser);
        
        if (!libro) {std::cout << "Libro no encontrado.\n"; return;}
        if (!usuario) {std::cout << "Usuario no encontrado.\n"; return;}

        if (libro->prestarLibro()){
            usuario->incrementarPrestamos();
            std::cout << "Libro prestado exitosamente.\n";
        } else {
            std::cout << "Libro no disponible para prestar.\n";
        }
    } catch (const std::exception& e) {
        std::cout << e.what()<< "\n";
    }
}

void devolverLibro(std::vector<Libro>& Libros, std::vector<Usuario>& usuarios){
    std::cout << "Devolver libro" << std::endl;
    try {
        int codLib = leerEntero("Codigo de libro a devolver: ");
        int codUser = leerEntero("Codigo de usuario: ");
        
        Libro* libro = buscarLibro(Libros, codLib);
        Usuario* usuario = buscarUsuario(usuarios, codUser);
        
        if (!libro) {std::cout << "Libro no encontrado.\n"; return;}
        if (!usuario) {std::cout << "Usuario no encontrado.\n"; return;}

        libro->devolverLibro();
        usuario->decrementarPrestamos();
        std::cout << "Libro devuelto exitosamente.\n";
    } catch (const std::exception& e) {
        std::cout << e.what()<< "\n";
    }
}
void mostrarUsuarios(const std::vector<Usuario>& usuarios,
                     const std::vector<Bibliotecarios>& bibliotecarios) {
    std::cout << "Usuarios registrados:\n";
    if (usuarios.empty()) std::cout << "sin usuarios registrados.\n";
    for (const auto& u : usuarios) {u.mostrarInformacion(); std::cout << "\n";}

    std::cout << "Bibliotecarios registrados:\n";
    if (bibliotecarios.empty()) std::cout << "sin bibliotecarios registrados.\n";
    for (const auto& b : bibliotecarios) {b.mostrarInformacion(); std::cout << "\n";}
}

void mostrarLibros(const std::vector<Libro>& libros) {
    std::cout << "Libros registrados:\n";
    if (libros.empty()) std::cout << "sin libros registrados.\n";
    for (const auto& l : libros) {l.mostrarInformacion(); std::cout << "\n";}
}

//---main---

/**
 * @brief menu principal del programa
 */

int main() {
    std::vector<Usuario> usuarios;
    std::vector<Bibliotecarios> bibliotecarios;
    std::vector<Libro> libros;

    int opcion = 0;
    do {
        std::cout << "Menu de biblioteca:\n"
                  << "1. Registrar usuario\n"
                  << "2. Registrar bibliotecario\n"
                  << "3. Registrar libro\n"
                  << "4. Prestar libro\n"
                  << "5. Devolver libro\n"
                  << "6. Mostrar usuarios y bibliotecarios\n"
                  << "7. Mostrar libros\n"
                  << "8. Salir\n";
        
        std::string entrada;
        std::getline(std::cin, entrada);
        try {
            opcion = std::stoi(entrada);
        } catch (...){
            std::cout << "Entrada no es un número válido.\n";
            continue;
        }
            switch (opcion) {
                case 1: registrarUsuario(usuarios); break;
                case 2: registrarBibliotecario(bibliotecarios); break;
                case 3: registrarLibro(libros); break;
                case 4: prestarLibro(usuarios, libros); break;
                case 5: devolverLibro(libros, usuarios); break;
                case 6: mostrarUsuarios(usuarios, bibliotecarios); break;
                case 7: mostrarLibros(libros); break;
                case 8: std::cout << "Saliendo del programa.\n"; break;
                default: std::cout << "Opcion no valida.\n"; break;
            }
        }while (opcion != 8);
        return 0;
}        