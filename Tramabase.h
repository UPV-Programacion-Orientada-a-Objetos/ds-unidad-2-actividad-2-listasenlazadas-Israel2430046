#ifndef TRAMABASE_H
#define TRAMABASE_H

#include "Listacargada.h"
#include "Rotomapeo.h"

class Trambase {
public:
    virtual void procesar(Listacargada* carga, Rotomapeo* rotor) = 0;
    virtual ~Trambase() {}
};

#endif
