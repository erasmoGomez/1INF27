
#include "src/Helpers.hpp"

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
