#ifndef TREAPEOMAP_H
#define TREAPEOMAP_H

#include "Tramabase.h"
#include "Rotomapeo.h"
#include <iostream>

class Treapeomap : public Trambase {
private:
    int desplazamiento;
public:
    Treapeomap(int n) : desplazamiento(n) {}

    void procesar(Listacargada*, Rotomapeo* rotor) override {
        rotor->rotar(desplazamiento);
    }
};

#endif
