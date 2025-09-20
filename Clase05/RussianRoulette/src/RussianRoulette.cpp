//
// Created by Erasmo on 19/09/25.
//

#include "RussianRoulette.hpp"

void lista_avanzar(NodoLista*& p, int pasos) {
    // p debe pertenecer al anillo (no nulo si lista no está vacía)
    while (pasos-- > 0) p = p->sig;
}

int lista_borrar_siguiente(Lista& L, NodoLista*& p) {
    // borra p->sig (la víctima) y deja p apuntando al previo de la nueva p->sig
    // Precondición: L.tam > 0 y p != nullptr
    NodoLista* victima = p->sig;
    int val = victima->valor;

    if (victima == p) {
        // había 1 solo nodo
        delete victima;
        L.cola = nullptr;
        L.tam = 0;
        p = nullptr;
        return val;
    }

    p->sig = victima->sig;       // saltar a la víctima
    if (victima == L.cola)       // si borré el último, actualizar cola
        L.cola = p;
    delete victima;
    L.tam--;
    return val;
}

int russian_roulette(int n, int seed) {
    if (n <= 0) return -1;
    srand(seed); // o srand((unsigned)time(NULL));

    Lista L{}; lista_init(L);
    for (int i = 1; i <= n; ++i) lista_push_back(L, i);

    NodoLista* p = L.cola; // previo al primero
    while (lista_tam(L) > 1) {
        int tam = lista_tam(L);
        int k   = 1 + (rand() % tam);     // k ∈ [1, tam]
        cout<<setw(5)<<k;
        int pasos = (k - 1) % tam;        // reducir vueltas
        cout<<setw(5)<<pasos<<endl;
        lista_avanzar(p, pasos);
        lista_borrar_siguiente(L, p);
    }
    int ganador = L.cola ? L.cola->valor : -1;
    lista_destruir(L);
    return ganador;
}

