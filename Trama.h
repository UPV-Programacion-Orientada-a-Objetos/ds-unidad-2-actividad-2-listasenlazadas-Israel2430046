#ifndef TRAMA_H
#define TRAMA_H

#include "Tramabase.h"
#include "Listacargada.h"
#include "Rotomapeo.h"
#include <iostream>
#include <cctype>

class Trama : public Trambase {
private:
    char dato;
public:
    Trama(char d) : dato(static_cast<char>(std::toupper(static_cast<unsigned char>(d)))) {}

    void procesar(Listacargada* carga, Rotomapeo* rotor) override {
        char decodificado = rotor->getMapeo(dato);
        carga->insertarAlFinal(decodificado);
        std::cout << "Trama [L," << dato << "] ->  decodificado como '" 
                  << decodificado << "'" << std::endl;
    }
};

#endif
