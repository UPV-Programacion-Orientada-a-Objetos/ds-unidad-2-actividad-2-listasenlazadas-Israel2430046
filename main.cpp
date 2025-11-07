#include <iostream>
#include <fstream>
#include <cstring>

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
            if (!cabeza) cabeza = nuevo;
            if (previo) previo->siguiente = nuevo;
            previo = nuevo;
        }
        cabeza->anterior = previo;
        previo->siguiente = cabeza;
    }

    void rotar(int n) {
        if (!cabeza) return;
        if (n > 0) {
            for (int i = 0; i < n % 26; i++) cabeza = cabeza->siguiente;
        } else {
            for (int i = 0; i < (-n) % 26; i++) cabeza = cabeza->anterior;
        }
        std::cout << "Rotor rotado " << n << " posiciones. Nueva cabeza: " << cabeza->letra << std::endl;
    }

    char getMapeo(char in) {
        if (!cabeza) return in;
        if (in >= 'a' && in <= 'z') in = in - 'a' + 'A';
        if (in < 'A' || in > 'Z') return in;
        int offset = in - 'A';
        NodoRotor* temp = cabeza;
        for (int i = 0; i < offset; ++i) temp = temp->siguiente;
        return temp->letra;
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

class Trambase {
public:
    virtual void procesar(Listacargada* carga, Rotomapeo* rotor) = 0;
    virtual ~Trambase() {}
};

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


class Treapeomap : public Trambase {
private:
    int desplazamiento;
public:
    Treapeomap(int n) : desplazamiento(n) {}
    void procesar(Listacargada*, Rotomapeo* rotor) override {
        rotor->rotar(desplazamiento);
    }
};

int main() {
    std::cout << "=== DECODIFICADOR PRT-7 ===" << std::endl;

    std::ifstream serial("/dev/ttyUSB0");
    if (!serial.is_open()) {
        std::cerr << "Error al abrir /dev/ttyUSB0, usando archivo de prueba 'tramas.txt'..." << std::endl;
        serial.open("tramas.txt");
        if (!serial.is_open()) {
            std::cerr << "No se pudo abrir archivo de prueba." << std::endl;
            return 1;
        }
    }

    Listacargada lista;
    Rotomapeo rotor;
    char linea[32];

    std::cout << "Conectado. Esperando tramas..." << std::endl;

    while (serial.getline(linea, 32)) {
        if (std::strlen(linea) < 2) continue;

        char tipo;
        char letra;
        int num;

        if (std::sscanf(linea, "%c,%d", &tipo, &num) == 2 && tipo == 'M') {
            Trambase* t = new Treapeomap(num);
            t->procesar(&lista, &rotor);
            delete t;
        } else if (std::sscanf(linea, "%c,%c", &tipo, &letra) == 2 && tipo == 'L') {
            Trambase* t = new Trama(letra);
            t->procesar(&lista, &rotor);
            delete t;
        }

        lista.imprimirMensaje();
    }

    serial.close();
    std::cout << "\n=== FIN DEL DECODIFICADOR ===" << std::endl;
    return 0;
}
