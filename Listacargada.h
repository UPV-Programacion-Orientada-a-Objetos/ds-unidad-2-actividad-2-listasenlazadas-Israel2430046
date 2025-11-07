#ifndef LISTACARGADA_H
#define LISTACARGADA_H

#include <iostream>

/**
 * @struct NodoCarga
 * @brief Nodo simple para la lista que guarda un solo caracter.
 */
struct NodoCarga {
    char dato;
    NodoCarga* siguiente;
    NodoCarga* anterior; 
};

/**
 * @class Listacargada
 * @brief Lista doblemente enlazada para ir acumulando el mensaje.
 *
 */
class Listacargada {
private:
    NodoCarga* cabeza; 
    NodoCarga* cola;  

public:
    /** @brief Crea la lista vacia */
    Listacargada() : cabeza(nullptr), cola(nullptr) {}

    /**
     * @brief Inserta un caracter al final de la lista.
     * @param d caracter a insertar
     */
    void insertarAlFinal(char d) {
        NodoCarga* nuevo = new NodoCarga{d, nullptr, cola};
        if (cola) {
            cola->siguiente = nuevo;
        } else {
            cabeza = nuevo;
        }
        cola = nuevo;
    }

    /**
     * @brief Imprime por stdout el mensaje actual construido.
     *
     */
    void imprimirMensaje() {
        NodoCarga* temp = cabeza;
        std::cout << "\nMensaje actual: ";
        while (temp) {
            std::cout << temp->dato;
            temp = temp->siguiente;
        }
        std::cout << std::endl;
    }

    /**
     * @brief Destructor: libera toda la memoria de los nodos.
     */
    ~Listacargada() {
        while (cabeza) {
            NodoCarga* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

#endif