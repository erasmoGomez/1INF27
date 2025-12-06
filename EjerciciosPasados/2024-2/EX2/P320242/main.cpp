#include "iostream"
using namespace std;

struct Nodo {
    int flag; // 0 o 1 (es Cueva)
    int id; // id del servidor
    Nodo *izq;
    Nodo *der;
};

const int MAX_NODOS = 100; // ajustar si hace falta

struct ElemCola {
    Nodo *nodo;
};

struct Cola {
    ElemCola datos[MAX_NODOS];
    int ini, fin;
};

void inicializarCola(Cola &q) {
    q.ini = q.fin = 0;
}

bool colaVacia(const Cola &q) {
    return q.ini == q.fin;
}

void encolar(Cola &q, Nodo *nodo) {
    q.datos[q.fin].nodo = nodo;
    q.fin++;
}

Nodo *desencolar(Cola &q) {
    Nodo *nodo = q.datos[q.ini].nodo;
    q.ini++;
    return nodo;
}

void diagonal(Nodo *raiz) {
    if (raiz == nullptr) return;

    Cola q;
    inicializarCola(q);

    // Encolamos la raíz y un marcador de fin de diagonal
    encolar(q, raiz);
    encolar(q, nullptr); // marcador

    while (!colaVacia(q)) {
        Nodo *actual = desencolar(q);

        if (actual == nullptr) {
            // Fin de una diagonal
            if (!colaVacia(q)) {
                // Si aún hay nodos, ponemos un nuevo marcador
                encolar(q, nullptr);
            }
        } else {
            // Recorremos la diagonal completa hacia la derecha
            while (actual != nullptr) {
                // Imprimir flag-id del servidor
                cout << actual->flag << "-" << actual->id << " ";

                // El hijo izquierdo va a la siguiente diagonal
                if (actual->izq != nullptr) {
                    encolar(q, actual->izq);
                }

                // Avanzamos hacia la derecha en la misma diagonal
                actual = actual->der;
            }
        }
    }
}

struct Par {
    int flag;
    int id;
};

// Arreglos para guardar el resultado por diagonales
Par diag[MAX_NODOS][MAX_NODOS];
int cantPorDiag[MAX_NODOS];
int totalDiagonales;

void construirDiagonales(Nodo *raiz) {
    for (int i = 0; i < MAX_NODOS; i++) cantPorDiag[i] = 0;
    totalDiagonales = 0;

    if (raiz == nullptr) return;

    Cola q;
    inicializarCola(q);

    encolar(q, raiz);
    encolar(q, nullptr); // marcador

    int nivelDiag = 0;

    while (!colaVacia(q)) {
        Nodo *actual = desencolar(q);

        if (actual == nullptr) {
            // Terminó una diagonal
            nivelDiag++;
            if (!colaVacia(q)) {
                encolar(q, nullptr);
            }
        } else {
            // Recorremos hacia la derecha dentro de esta diagonal
            while (actual != nullptr) {
                int k = cantPorDiag[nivelDiag];
                diag[nivelDiag][k].flag = actual->flag;
                diag[nivelDiag][k].id = actual->id;
                cantPorDiag[nivelDiag]++;

                if (actual->izq != nullptr) {
                    encolar(q, actual->izq);
                }
                actual = actual->der;
            }
        }
    }
    totalDiagonales = nivelDiag; // cantidad de diagonales usadas
}

void diagonal2(Nodo *raiz) {
    construirDiagonales(raiz); // iterativa

    for (int d = 0; d < totalDiagonales; d++) {
        for (int i = 0; i < cantPorDiag[d]; i++) {
            cout << diag[d][i].flag << "-" << diag[d][i].id << " ";
        }
    }
}

void diagonal_inv(Nodo *raiz) {
    construirDiagonales(raiz); // misma construcción iterativa

    for (int d = totalDiagonales - 1; d >= 0; d--) {
        // Dentro de cada diagonal, de atrás hacia adelante
        for (int i = cantPorDiag[d] - 1; i >= 0; i--) {
            cout << diag[d][i].flag << "-" << diag[d][i].id << " ";
        }
    }
}

int main() {
    // Construcción manual del árbol del ejemplo
    Nodo *n100 = new Nodo{0, 100, nullptr, nullptr};
    Nodo *n50 = new Nodo{0, 50, nullptr, nullptr};
    Nodo *n150 = new Nodo{0, 150, nullptr, nullptr};
    Nodo *n75 = new Nodo{0, 75, nullptr, nullptr};
    Nodo *n175 = new Nodo{0, 175, nullptr, nullptr};
    Nodo *n200 = new Nodo{0, 200, nullptr, nullptr};
    Nodo *n25 = new Nodo{0, 25, nullptr, nullptr};
    Nodo *n40 = new Nodo{0, 40, nullptr, nullptr};
    Nodo *n125 = new Nodo{1, 125, nullptr, nullptr}; // SkyNerd

    // Enlaces según el gráfico del examen
    n100->izq = n50;
    n100->der = n150;

    n50->izq = n25;
    n50->der = n75;

    n25->der = n40;

    n150->der = n175;
    n150->izq = n125;

    n175->der = n200;

    cout << "Recorrido diagonal: " << endl;
    diagonal(n100);
    cout << endl;


    return 0;
}
