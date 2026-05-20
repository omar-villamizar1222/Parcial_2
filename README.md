# Sistema de Gestión de Biblioteca

Proyecto orientado a objetos en C++ para administrar una biblioteca universitaria.

## Estructura del Proyecto

```
Proyecto/
├── include/
│   ├── persona.h
│   ├── Usuarios.h
│   ├── Bibliotecarios.h
│   └── Libros.h
├── src/
│   ├── persona.cpp
│   ├── Usuarios.cpp
│   ├── Bibliotecarios.cpp
│   └── Libros.cpp
├── main.cpp
├── README.md
└── .gitignore
```

## Compilación

```bash
g++ -std=c++17 -Wall main.cpp src/*.cpp -o biblioteca
./biblioteca
```

## Conceptos aplicados

- **Encapsulación**: atributos privados/protegidos con getters/setters.
- **Herencia**: `Usuario` y `Bibliotecario` heredan de `Persona`.
- **Polimorfismo**: `mostrarRol()` y `mostrarInformacion()` son virtuales.
- **Vectores STL**: almacenamiento dinámico de entidades.
- **Validaciones**: edad > 0, documentos y códigos solo numéricos.
- **Documentación Doxygen**: comentarios `///` y `@brief` en todos los archivos.

## Menú

| Opción | Descripción |
|--------|-------------|
| 1 | Registrar usuario |
| 2 | Registrar bibliotecario |
| 3 | Registrar libro |
| 4 | Prestar libro |
| 5 | Devolver libro |
| 6 | Mostrar usuarios y bibliotecarios |
| 7 | Mostrar libros |
| 8 | Salir |
