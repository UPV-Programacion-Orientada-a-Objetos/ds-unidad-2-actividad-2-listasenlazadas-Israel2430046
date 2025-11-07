#ifndef LISTACARGADA_H
#define LISTACARGADA_H

#include <iostream>

struct NodoCarga {
    char dato;
    NodoCarga* siguiente;
    NodoCarga* anterior;
};

class Listacargada {
private:
    NodoCarga* cabeza;
    NodoCarga* cola;

public:
    Listacargada() : cabeza(nullptr), cola(nullptr) {}

    void insertarAlFinal(char d) {
        NodoCarga* nuevo = new NodoCarga{d, nullptr, cola};
        if (cola) {
            cola->siguiente = nuevo;
        } else {
            cabeza = nuevo;
        }
        cola = nuevo;
    }

    void imprimirMensaje() {
        NodoCarga* temp = cabeza;
        std::cout << "\nMensaje actual: ";
        while (temp) {
            std::cout << temp->dato;
            temp = temp->siguiente;
        }
        std::cout << std::endl;
    }

    ~Listacargada() {
        while (cabeza) {
            NodoCarga* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

#endif
