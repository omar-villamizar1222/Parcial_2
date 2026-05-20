#ifndef BIBLIOTECARIOS_H
#define BIBLIOTECARIOS_H

#include "persona.h"

/**
* @brief Clase que representa a un bibliotecario, heredando de la clase Persona.
*
* Esta clase puede tener atributos y métodos específicos para un bibliotecario, como gestionar libros, atender a los usuarios, etc.
*/
class Bibliotecarios    : public Persona {
private:
    int codigoEmpleado; // Código único para cada bibliotecario
    double salario; // Salario del bibliotecario

public:
    /** 
    * @brief Constructor de la clase Bibliotecario.
    * @param nombre Nombre del bibliotecario.
    * @param edad Edad del bibliotecario.
    * @param documento Documento de identidad del bibliotecario.
    * @param codigoEmpleado Código único para el bibliotecario.
    * @param salario Salario del bibliotecario.
    */
    Bibliotecarios(const std::string& nombre,const std::string& documento,int edad, int codigoEmpleado, double salario);

    ///@brief Muestra el rol del bibliotecario.
    void mostrarRol() const override;

    ///@brief Muestra la información del bibliotecario.
    void mostrarInformacion() const override;

    ///getters
    int getCodigoEmpleado() const;
    double getSalario() const;
};

#endif // BIBLIOTECARIOS_H

