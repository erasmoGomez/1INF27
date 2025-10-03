//
// Created by Erasmo on 3/10/25.
//
#include "ColaPrioridad.hpp"

int prioDe(char tipo) {
    if (tipo == '1') return 1;
    if (tipo == '2') return 2;
    return 3;
}

static NodoCola* nuevoNodo(const Elemento &e) {
    NodoCola* n = new NodoCola;
    n->elem = e;
    n->sig = nullptr;
    return n;
}

void construir(ColaPrioridad &cp) {
    cp.head = cp.tail = nullptr;
    cp.last1 = cp.last2 = nullptr;
    cp.size1 = cp.size2 = cp.size3 = 0;
}

bool esVacia(const ColaPrioridad &cp) {
    return cp.head == nullptr;
}

int sizeTotal(const ColaPrioridad &cp) {
    return cp.size1 + cp.size2 + cp.size3;
}

// Inserta nodo 'n' después del puntero 'p' (que puede ser nullptr para insertar al inicio)
void insertarDespues(ColaPrioridad &cp, NodoCola* p, NodoCola* n) {
    if (p == nullptr) {
        // Insertar al inicio
        n->sig = cp.head;
        cp.head = n;
        if (cp.tail == nullptr) cp.tail = n;  // lista estaba vacía
    } else {
        n->sig = p->sig;
        p->sig = n;
        if (cp.tail == p) cp.tail = n;        // si p era el último, actualiza tail
    }
}

void encolar(ColaPrioridad &cp, const Elemento &e, int prio) {
    NodoCola* n = nuevoNodo(e);

    if (prio == 1) {
        if (cp.last1 != nullptr) {
            // Hay P1: insertar después del último P1
            insertarDespues(cp, cp.last1, n);
            cp.last1 = n;
        } else {
            // No hay P1: insertar al inicio global
            insertarDespues(cp, nullptr, n);
            cp.last1 = n;
            // Nota: si existían P2/P3, mover el head está bien: P1 debe ir antes de todo
            // last2 no cambia (sigue apuntando al último de P2 si existía)
        }
        cp.size1++;
        return;
    }

    if (prio == 2) {
        if (cp.last2 != nullptr) {
            // Hay P2: insertar después del último P2
            insertarDespues(cp, cp.last2, n);
            cp.last2 = n;
        } else if (cp.last1 != nullptr) {
            // No hay P2 pero sí P1: insertar justo después del último P1 (entre P1 y P3)
            insertarDespues(cp, cp.last1, n);
            cp.last2 = n;
        } else {
            // No hay P1 ni P2: insertar al inicio (antes de P3 si existiera)
            insertarDespues(cp, nullptr, n);
            cp.last2 = n;
        }
        cp.size2++;
        return;
    }

    // prio == 3 (baja): siempre al final
    if (cp.tail == nullptr) {
        // lista vacía
        cp.head = cp.tail = n;
    } else {
        cp.tail->sig = n;
        cp.tail = n;
    }
    cp.size3++;
}

const Elemento& frente(const ColaPrioridad &cp) {
    // PRE: !esVacia(cp)
    return cp.head->elem;
}

Elemento desencolar(ColaPrioridad &cp) {
    // PRE: !esVacia(cp)
    NodoCola* primero = cp.head;
    Elemento e = primero->elem;

    // Avanzar head
    cp.head = primero->sig;
    if (cp.head == nullptr) cp.tail = nullptr;

    // Ajustar fronteras si el nodo eliminado era el último de algún segmento
    if (primero == cp.last1) cp.last1 = nullptr;
    if (primero == cp.last2) cp.last2 = nullptr;

    // Ajustar contadores según prioridad del elemento
    // (Si mapeas Elemento.tipo a prioridad de otra forma, cambia este switch)
    int prio = 3;
    if (e.tipo == '1') prio = 1;
    else if (e.tipo == '2') prio = 2;

    if (prio == 1 && cp.size1 > 0) cp.size1--;
    else if (prio == 2 && cp.size2 > 0) cp.size2--;
    else if (prio == 3 && cp.size3 > 0) cp.size3--;

    delete primero;
    return e;
}

void destruir(ColaPrioridad &cp) {
    while (!esVacia(cp)) (void)desencolar(cp);
    // ya quedó limpio
}
