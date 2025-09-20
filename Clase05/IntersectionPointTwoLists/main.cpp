
#include "src/BibliotecaLista.hpp"

/* ---------- Helpers para pruebas ---------- */

// Devuelve el puntero al k-esimo nodo (0-based). Si no existe, retorna nullptr.
static NodoLista* obtener_k_esimo(NodoLista* head, int k) {
    int i = 0;
    while (head and i < k) {
        head = head->siguiente;
        i++;
    }
    return head; // puede ser nullptr si k fuera de rango
}

// Crea una intersección: el tail de l2 apuntará al nodo k (0-based) de l1.
// Retorna el puntero al nodo de intersección (o nullptr si no se pudo).
static NodoLista* forzar_interseccion(Lista& l1, Lista& l2, int k_en_l1) {
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
static NodoLista* obtener_interseccion(const Lista& a, const Lista& b) {
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
static void destruir_hasta(Lista& l, NodoLista* stop_exclusive) {
    NodoLista* cur = l.head;
    while (cur && cur != stop_exclusive) {
        NodoLista* nxt = cur->siguiente;
        delete cur;
        cur = nxt;
    }
    l.head = stop_exclusive; // el resto podría ser compartido; no tocar aquí
}

int main() {
    // 1) Construimos dos listas
    Lista l1{}, l2{};
    construir(l1);
    construir(l2);

    // 2) Insertamos algunos datos (al final) para que quede orden de lectura natural
    // l1: [1, 2, 3, 4, 5]
    Elemento e{};
    e.numero = 1; insertar_final(l1, e);
    e.numero = 2; insertar_final(l1, e);
    e.numero = 3; insertar_final(l1, e);
    e.numero = 4; insertar_final(l1, e);
    e.numero = 5; insertar_final(l1, e);

    // l2: [9, 8]
    e.numero = 9; insertar_final(l2, e);
    e.numero = 8; insertar_final(l2, e);


    cout << "Lista 1 inicial: "; imprimir(l1);
    cout << "Lista 2 inicial: "; imprimir(l2);

    // 3) Forzamos una intersección: hacemos que el tail de l2 apunte al nodo 2 (valor 3) de l1
    NodoLista* nodo_interseccion_esperado = forzar_interseccion(l1, l2, 2);
    if (!nodo_interseccion_esperado) {
        cout << "No se pudo forzar interseccion (indice fuera de rango)" << endl;
        return 0;
    }

    cout << "Tras forzar interseccion en valor "
         << nodo_interseccion_esperado->elemento.numero << ":\n";
    cout << "Lista 1: "; imprimir(l1);        // [1,2,3,4,5]
    cout << "Lista 2: "; imprimir(l2);        // [9,8,3,4,5]

    // 4) Hallamos el punto de intersección con el algoritmo de dos punteros
    NodoLista* inter = obtener_interseccion(l1, l2);
    if (inter) {
        cout << "Interseccion encontrada en nodo con valor: "
             << inter->elemento.numero << endl;
    } else {
        cout << "No hay interseccion.\n";
    }

    // 5) Limpieza de memoria:
    //    - Libera SOLO el prefijo exclusivo de l2 (hasta 'inter').
    //    - Luego destruye l1 completo (lo que también libera la cola compartida).
    destruir_hasta(l2, inter);
    destruir(l1);
    // l2.head ya apunta a 'inter' (que fue borrado por destruir(l1)); opcionalmente:
    l2.head = nullptr;

    return 0;
}
