//
// Created by erasmo on 4/20/26.
//

#ifndef INTERSECTIONPOINTTWOLISTS_HELPERS_HPP
#define INTERSECTIONPOINTTWOLISTS_HELPERS_HPP

#include "BibliotecaLista.hpp"

NodoLista *obtener_k_esimo(NodoLista *head, int k);

NodoLista *forzar_interseccion(Lista &l1, Lista &l2, int k_en_l1);

NodoLista *obtener_interseccion(const Lista &a, const Lista &b);

void destruir_hasta(Lista &l, NodoLista *stop_exclusive);

#endif //INTERSECTIONPOINTTWOLISTS_HELPERS_HPP
