#ifndef USUARIO_H
#define USUARIO_H

#include "persona.h"

/**
 * @brief La clase Usuario que hereda de Persona y representa a un usuario del sistema.
 * 
 * agrega un codigo de usuario y la cantidad de libros prestados por el usuario.
 */
class Usuario : public Persona {
private:
    int codigoUsuario; // Código único del usuario
    int cantidadLibrosPrestados; // Cantidad de libros prestados por el usuario
public:
    /**
     * @brief Constructor de la clase Usuario.
     * @param nombre Nombre del usuario.
     * @param documento Documento del usuario.
     * @param edad Edad del usuario.
     * @param codigoUsuario Código único del usuario.
     */
    Usuario(const std::string& nombre, const std::string& documento, int edad, int codigoUsuario);
    /**
     * @brief Método para mostrar la información del usuario.
     */    void mostrarInformacion() const override;
    /**
     * @brief Muestra el rol del usuario.
     */    void mostrarRol() const override;

    // Getters y Setters
    int getCodigoUsuario() const;
    int getCantidadLibrosPrestados() const;
    void incrementarPrestamos();
    void decrementarPrestamos();
};

#endif // USUARIO_H