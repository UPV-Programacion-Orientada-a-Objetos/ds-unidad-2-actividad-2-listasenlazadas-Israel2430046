#ifndef ROTOMAPEO_H
#define ROTOMAPEO_H

#include <iostream>

/**
 * @brief Nodo para la rueda del rotor.
 */
struct NodoRotor {
    char letra;          
    NodoRotor* siguiente;
    NodoRotor* anterior;
};

/**
 * @brief Rotor simple que mapea letras y se puede rotar.
 */
class Rotomapeo {
private:
    NodoRotor* cabeza;

public:
    /**
     * @brief Construye el rotor con las letras A..Z en una rueda circular.
     */
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
        if (cabeza && previo) {
            cabeza->anterior = previo;
            previo->siguiente = cabeza;
        }
    }

    /**
     * @brief Rota el rotor n posiciones 
     * @param n desplazamiento en posiciones
     */
    void rotar(int n) {
        if (!cabeza) return;
        int pasos = std::abs(n) % 26;
        if (n > 0) {
            for (int i = 0; i < pasos; ++i) cabeza = cabeza->siguiente;
        } else {
            for (int i = 0; i < pasos; ++i) cabeza = cabeza->anterior;
        }
        std::cout << "Rotor rotado " << n << " posiciones. Nueva cabeza: " << cabeza->letra << std::endl;
    }

    /**
     * @brief Obtiene la letra mapeada según la entrada.
     * @param in caracter de entrada (A..Z o a..z)
     * @return caracter mapeado; si no es letra devuelve el mismo caracter
     */
    char getMapeo(char in) {
        if (!cabeza) return in;
        if (in >= 'a' && in <= 'z') in = static_cast<char>(in - 'a' + 'A');
        if (in < 'A' || in > 'Z') return in;
        int offset = in - 'A';
        NodoRotor* temp = cabeza;
        for (int i = 0; i < offset; ++i) temp = temp->siguiente;
        return temp->letra;
    }

    /**
     * @brief Destructor: libera los nodos del rotor.
     */
    ~Rotomapeo() {
        if (!cabeza) return;
        NodoRotor* cur = cabeza->siguiente;
        while (cur != cabeza) {
            NodoRotor* borrar = cur;
            cur = cur->siguiente;
            delete borrar;
        }
        delete cabeza;
    }
};

#endif