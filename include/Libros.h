#ifndef LIBROS_H
#define LIBROS_H

#include <string>

/**
 * @brief Clase que representa un libro en una biblioteca.  
 */

class Libro {
private:
    std::string titulo; ///< Título del libro.
    std::string autor;  ///< Autor del libro.
    int codigoLibro; ///< Código único del libro.
    bool disponible;   ///< Indica si el libro está disponible para préstamo.

public:
    /**
     * @brief Constructor de la clase Libro.
     * @param titulo Título del libro.
     * @param autor Autor del libro.
     * @param codigoLibro Código único del libro.
     */
    Libro(const std::string& titulo, const std::string& autor, int codigoLibro);

    /**
     * @brief Muestra la información del libro.
     */
    void mostrarInformacion() const;

    /**
     * @brief Presta el libro si está disponible.
     * @return true si el libro fue prestado exitosamente, false si no está disponible.
     */
    bool prestarLibro();

    ///@brief devuelve el libro; marcandolo como disponible
    void devolverLibro();

    //Getters
    std::string getTitulo() const;
    std::string getAutor() const;
    int getCodigoLibro() const;
    bool isDisponible() const;
};

#endif // LIBROS_H