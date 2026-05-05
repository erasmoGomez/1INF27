#include <iostream>

#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"

using namespace std;

/* =========================================================
 * PLANTEAMIENTO DEL PROBLEMA
 * =========================================================
 * Dada una lista simplemente enlazada, donde cada nodo tiene
 * un campo 'codigo', se pide reorganizar la lista de tal forma que:
 *
 * 1. Todos los elementos con código PAR aparezcan al inicio.
 * 2. Todos los elementos con código IMPAR aparezcan al final.
 * 3. Se debe mantener el orden relativo original dentro de cada grupo.
 *
 * Restricciones:
 * - No se pueden crear nodos nuevos.
 * - No se pueden usar arreglos, vectores ni estructuras auxiliares.
 * - Solo se pueden usar punteros auxiliares.
 *
 * Ejemplo:
 * Entrada:  17 -> 4 -> 12 -> 7
 * Salida:   4 -> 12 -> 17 -> 7
 */


/* =========================================================
 * IDEA DE SOLUCIÓN (ALGORITMO)
 * =========================================================
 * Estrategia:
 *
 * 1. Recorrer la lista original UNA sola vez. O(n)
 *
 * 2. Durante el recorrido, separar los nodos en dos sublistas:
 *    - Lista de pares
 *    - Lista de impares
 *
 *    Para cada nodo:
 *    - Se "desconecta" (actual->siguiente = nullptr)
 *    - Se inserta al final de su sublista correspondiente
 *
 * 3. Mantener punteros para cada sublista:
 *    - inicio y fin de pares
 *    - inicio y fin de impares
 *
 * 4. Al finalizar el recorrido:
 *    - Si hay pares:
 *        lista = pares + impares
 *    - Si no hay pares:
 *        lista = impares
 *
 * Complejidad:
 * - Tiempo: O(n)
 * - Espacio: O(1) (no se crean nodos nuevos)
 */


/* =========================================================
 * IMPLEMENTACIÓN
 * =========================================================
 */
void reorganizarLista(Lista &lista) {

    // Sublista de pares
    NodoLista *paresInicio = nullptr;
    NodoLista *paresFin = nullptr;

    // Sublista de impares
    NodoLista *imparesInicio = nullptr;
    NodoLista *imparesFin = nullptr;

    NodoLista *actual = lista.lista;

    while (actual != nullptr) {
        NodoLista *siguiente = actual->siguiente;

        // Desconectamos el nodo actual
        actual->siguiente = nullptr;

        if (actual->elemento.codigo % 2 == 0) {
            // ===== PAR =====
            if (lista.inicio_par == nullptr) {
                lista.inicio_par = lista.fim_par = actual;
            } else {
                lista.inicio_par->siguiente = actual;
                lista.fim_par = actual;
            }
        } else {
            // ===== IMPAR =====
            if (lista.inicio_inpar == nullptr) {
                lista.inicio_inpar = lista.fim_inpar = actual;
            } else {
                lista.fim_inpar->siguiente = actual;
                lista.fim_inpar = actual;
            }
        }

        actual = siguiente;
    }

    // // Reconstrucción de la lista final
    // if (paresInicio == nullptr) {
    //     lista.lista = imparesInicio;
    // } else {
    //     lista.lista = paresInicio;
    //     paresFin->siguiente = imparesInicio;
    // }
    // lista.cabeza = lista.inicio_par;
    // lista.cola = lista.fim_inpar;
}


/* =========================================================
 * FUNCIÓN PRINCIPAL DE PRUEBA
 * =========================================================
 */
int main() {
    Lista lista;

    construir(lista);

    insertarAlFinal(lista, {17, "Ben Hur", "Azul"});
    insertarAlFinal(lista, {14, "Ben Hur", "Azul"}));
    insertarAlFinal(lista, {12, "Ben Hur", "Azul"}));
    insertarAlFinal(lista, {7, "Ben Hur", "Azul"}));

    cout << "Lista original: ";
    imprimir(lista);

    reorganizarLista(lista);

    cout << "Lista reorganizada: ";
    imprimir(lista);

    return 0;
}