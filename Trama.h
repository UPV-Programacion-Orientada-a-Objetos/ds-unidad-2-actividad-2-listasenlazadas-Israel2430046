#ifndef TRAMA_H
#define TRAMA_H

#include "Trambase.h"
#include <iostream>

class Trama : public Trambase {
private:
    char dato;

public:
    Trama(char d) : dato(d) {}

    void procesar(Listacargada* carga, Rotomapeo* rotor) override {
        char decodificado = rotor->getMapeo(dato);
        carga->insertarAlFinal(decodificado);
        std::cout << "Trama [L," << dato << "] → decodificado como '" << decodificado << "'" << std::endl;
    }
};

#endif
