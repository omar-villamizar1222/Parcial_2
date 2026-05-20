#ifndef PERSONA_H
#define PERSONA_H

#include <string>

/**
 * @brief Clase que representa una persona en el sistema.
 * contiene los atributos básicos de una persona, como su nombre, documento.
 * asi como metodos virtuales para mostrar su información.
 */
class Persona {
protected:
    std::string nombre; ///< Nombre de la persona.
    std::string documento; ///< Documento de la persona.
    int edad; ///< Edad de la persona.

public:
    /**
     * @brief Constructor de la clase Persona.
     * @param nombre Nombre de la persona.
     * @param documento Documento de la persona.
     * @param edad Edad de la persona.
     */
    Persona(const std::string& nombre, const std::string& documento, int edad);

    /**
     * @brief Destructor virtual de la clase Persona.
     */
    virtual ~Persona() = default;

    /// @brief Muestra el rol de la persona (virtual puro, debe ser implementado por las clases derivadas).
    virtual void mostrarRol() const = 0;

    /// @brief Muestra la información de la persona (virtual puro, debe ser implementado por las clases derivadas).
    virtual void mostrarInformacion() const = 0;

    //Getters
    std::string getNombre() const;
    std::string getDocumento() const;
    int getEdad() const;
};

#endif // PERSONA_H