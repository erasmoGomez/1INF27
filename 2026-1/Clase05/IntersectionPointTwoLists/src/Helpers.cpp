//
// Created by erasmo on 4/20/26.
//

#include "Helpers.hpp"

/* ---------- Helpers para pruebas ---------- */

// Devuelve el puntero al k-esimo nodo (0-based). Si no existe, retorna nullptr.
NodoLista* obtener_k_esimo(NodoLista* head, int k) {
    int i = 0;
    while (head and i < k) {
        head = head->siguiente;
        i++;
    }
    return head; // puede ser nullptr si k fuera de rango
}

// Crea una intersección: el tail de l2 apuntará al nodo k (0-based) de l1.
// Retorna el puntero al nodo de intersección (o nullptr si no se pudo).
NodoLista* forzar_interseccion(Lista& l1, Lista& l2, int k_en_l1) {
    NodoLista* objetivo = obtener_k_esimo(l1.head, k_en_l1);
    if (!objetivo) return nullptr;

    NodoLista* tail_l2 = obtener_nodo_final(l2);
    if (!tail_l2) {
        // l2 está vacía: la "lista" 2 completa será desde objetivo
        l2.head = objetivo;
    } else {
        tail_l2->siguiente = objetivo;
    }
    return objetivo;
}

/* ---------- Algoritmo de intersección (dos punteros) ---------- */
// Si hay intersección, ambos punteros se alinean tras alternar de lista.
NodoLista* obtener_interseccion(const Lista& a, const Lista& b) {
    NodoLista* p = a.head;
    NodoLista* q = b.head;

    // Recorremos como máximo (lenA + lenB + 1) pasos hacia el encuentro o nullptr.
    while (p != q) {
        p = (p == nullptr) ? b.head : p->siguiente;
        q = (q == nullptr) ? a.head : q->siguiente;
    }
    return p; // puede ser nullptr si no hay intersección
}

/* ---------- Limpieza segura cuando hay intersección ---------- */
/*
 * Si liberas l1 completo, ya liberas también la “cola compartida”.
 * Entonces SOLO debes liberar el prefijo exclusivo de l2 (antes del nodo de intersección).
 * Esta función libera nodos de l2 hasta (pero sin incluir) 'stop'.
 */
void destruir_hasta(Lista& l, NodoLista* stop_exclusive) {
    NodoLista* cur = l.head;
    while (cur && cur != stop_exclusive) {
        NodoLista* nxt = cur->siguiente;
        delete cur;
        cur = nxt;
    }
    l.head = stop_exclusive; // el resto podría ser compartido; no tocar aquí
}