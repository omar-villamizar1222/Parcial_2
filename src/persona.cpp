#include "../include/persona.h"
#include <iostream>
#include <stdexcept>

Persona::Persona(const std::string& nombre, const std::string& documento, int edad) {
    if (edad <= 0) 
        throw std::invalid_argument("Erro: la edad debe ser mayor a 0.");
    
        for(char c :documento){
            if (!std::isalnum(c)) 
                throw std::invalid_argument("Error: el documento solo puede contener caracteres alfanuméricos y espacios.");
            }
            this->nombre = nombre;
            this->documento = documento;
            this->edad = edad;
}

void Persona::mostrarInformacion() const {
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "documento: " << documento << "\n";
    std::cout << "Edad: " << edad << "\n";
}

std::string Persona::getNombre() const {
    return nombre;
}
std::string Persona::getDocumento() const {
    return documento;
}
int Persona::getEdad() const {
    return edad;
}