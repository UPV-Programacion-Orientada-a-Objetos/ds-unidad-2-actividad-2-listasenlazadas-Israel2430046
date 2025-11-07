#ifndef ROTOMAPEO_H
#define ROTOMAPEO_H

#include <iostream>

struct NodoRotor {
    char letra;
    NodoRotor* siguiente;
    NodoRotor* anterior;
};

class Rotomapeo {
private:
    NodoRotor* cabeza;

public:
    Rotomapeo() {
        cabeza = nullptr;
        NodoRotor* previo = nullptr;
        for (char c = 'A'; c <= 'Z'; c++) {
            NodoRotor* nuevo = new NodoRotor{c, nullptr, previo};
            if (!cabeza) {
                cabeza = nuevo;
            }
            if (previo) {
                previo->siguiente = nuevo;
            }
            previo = nuevo;
        }
        cabeza->anterior = previo;
        previo->siguiente = cabeza;
    }

    void rotar(int n) {
        if (!cabeza) return;
        if (n > 0) {
            for (int i = 0; i < n % 26; i++) {
                cabeza = cabeza->siguiente;
            }
        } else {
            for (int i = 0; i < (-n) % 26; i++) {
                cabeza = cabeza->anterior;
            }
        }
        std::cout << "Rotor rotado " << n << " posiciones. Nueva cabeza: " << cabeza->letra << std::endl;
    }

    char getMapeo(char in) {
        NodoRotor* temp = cabeza;
        for (int i = 0; i < 26; i++) {
            if (temp->letra == in) return cabeza->letra;
            temp = temp->siguiente;
        }
        return in;
    }

    ~Rotomapeo() {
        if (!cabeza) return;
        NodoRotor* temp = cabeza->siguiente;
        while (temp != cabeza) {
            NodoRotor* borrar = temp;
            temp = temp->siguiente;
            delete borrar;
        }
        delete cabeza;
    }
};

#endif
