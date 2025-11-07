#ifndef TRAMA_H
#define TRAMA_H

#include "Tramabase.h"
#include "Listacargada.h"
#include "Rotomapeo.h"
#include <iostream>
#include <cctype>
/**
 * @brief Trama tipo L que contiene un caracter.
 */
class Trama : public Trambase {
private:
    char dato;
public:
    /**
     * @brief Construye la trama normalizando el caracter a mayúscula.
     * @param d caracter entrante
     */
    Trama(char d) : dato(static_cast<char>(std::toupper(static_cast<unsigned char>(d)))) {}

    /**
     * @brief Decodifica el caracter usando el rotor y lo guarda en la lista.
     * @param carga lista destino
     * @param rotor rotor usado para decodificar
     */
    void procesar(Listacargada* carga, Rotomapeo* rotor) override {
        char decodificado = rotor->getMapeo(dato);
        carga->insertarAlFinal(decodificado);
        std::cout << "Trama [L," << dato << "] ->  decodificado como '"
                  << decodificado << "'" << std::endl;
    }
};

#endif
