#include "../include/Bibliotecarios.h"
#include <iostream>

Bibliotecarios::Bibliotecarios(const std::string& nombre, 
                               const std::string& document,
                               int edad, 
                               int codigoEmpleado, 
                               double salario)
    : Persona(nombre, documento, edad), codigoEmpleado(codigoEmpleado), salario(salario) {}

void Bibliotecarios::mostrarRol() const {
 std::cout << " Rol: Bibliotecario\n";
}
void Bibliotecarios::mostrarInformacion() const {
    std::cout << "Información del Bibliotecario:\n";
    Persona::mostrarInformacion();
    std::cout << " Código de Empleado: " << codigoEmpleado << "\n";
    std::cout << " Salario: $" << salario << "\n";
    mostrarRol();
}
int Bibliotecarios::getCodigoEmpleado() const {
    return codigoEmpleado;
}
double Bibliotecarios::getSalario() const {
    return salario;
}



