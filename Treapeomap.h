#ifndef TREAPEOMAP_H
#define TREAPEOMAP_H

#include "Tramabase.h"
#include "Rotomapeo.h"
#include <iostream>


/**
 * @brief Trama tipo M que rota el rotor.
 *
 * La trama contiene un desplazamiento que se aplica al rotor cuando se
 * procesa.
 */
class Treapeomap : public Trambase {
private:
    int desplazamiento; 
public:
    /**
     * @brief Construye la trama de rotación.
     * @param n desplazamiento en posiciones
     */
    Treapeomap(int n) : desplazamiento(n) {}

    /**
     * @brief Procesa la trama aplicando la rotación al rotor.
     * @param carga puntero a la lista (no usado)
     * @param rotor rotor sobre el que se aplica la rotación
     */
    void procesar(Listacargada*, Rotomapeo* rotor) override {
        rotor->rotar(desplazamiento);
    }
};

#endif