# ===============================================
# Proyecto: Decodificador de Protocolo 
# Autor: Israel Eliseo Cisneros Salas
# ===============================================

# Versión mínima de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(DecodificadorPRT7 LANGUAGES CXX)

# Configuración del estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Archivos fuente del proyecto
set(SOURCES
    main.cpp
)

# Archivos de cabecera (para visibilidad en IDEs)
set(HEADERS
    Trambase.h
    Trama.h
    Treapeomap.h
    Listacargada.h
    Rotomapeo.h
)

# Crear el ejecutable
add_executable(decodificador ${SOURCES} ${HEADERS})

# Mensaje informativo al compilar
message(STATUS "Compilando Decodificador PRT-7 con CMake...")
message(STATUS "Salida esperada: ejecutable './decodificador'")
