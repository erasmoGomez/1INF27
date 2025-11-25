//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal 

#ifndef ARBOLBINARIO_FUNCIONESARBOLBINARIO_H
#define ARBOLBINARIO_FUNCIONESARBOLBINARIO_H

void construir(struct ArbolBinario &arbol);
bool esArbolVacio(const struct ArbolBinario &nodo);
bool esNodoVacio(const struct NodoArbolBinario *nodo);
void plantarArbolBinario(struct ArbolBinario &arbol, const struct ArbolBinario &izquierda,
                         const struct ElementoArbolBinario &elemento, const struct ArbolBinario &derecha);
void plantarNodoArbolBinario(struct NodoArbolBinario *&nodo, struct NodoArbolBinario *izquierda,
                             const struct ElementoArbolBinario &elemento, struct NodoArbolBinario *derecha);

void imprimirNodo(struct NodoArbol *raiz);
void imprimir(const struct ArbolBinario &arbol);

void recorrerPreOrden(const struct ArbolBinario &arbol);
void recorrerPreOrdenRecursivo(struct NodoArbolBinario *nodo);
void recorrerEnOrden(const struct ArbolBinario &arbol);
void recorrerEnOrdenRecursivo(struct NodoArbolBinario *nodo);
void recorrerPostOrden(const struct ArbolBinario &arbol);
void recorrerPostOrdenRecursivo(struct NodoArbolBinario *nodo);

int maximo(int a, int b);
int numeroHojas(const struct ArbolBinario &arbol);
int numeroHojasRecursivo(struct NodoArbolBinario *nodo);
int numeroNodos(const struct ArbolBinario &arbol);
int numeroNodosRecursivo(struct NodoArbolBinario *nodo);
bool esEquilibrado(const struct ArbolBinario &arbol);
bool esEquilibradoRecursivo(struct NodoArbolBinario *nodo);
int altura(const struct ArbolBinario &arbol);
int alturaRecursivo(struct NodoArbolBinario *nodo);
void destruirArbolBinario(struct ArbolBinario & arbol);
void destruirRecursivo(struct NodoArbolBinario * nodo);

void llenarArbol(struct ArbolBinario &arbol, struct ElementoArbolBinario *arreglo, int inicio, int fin);
void llenarArbolRecursivo(struct NodoArbolBinario *&nodo, struct ElementoArbolBinario  *arreglo,
                         int inicio, int fin);


void recorridoPorNivel(const struct ArbolBinario & arbol) ;
void recorridoPorNivelCambioLinea(const struct ArbolBinario & arbol);
void enOrdenIterativo(const struct ArbolBinario & arbol) ;
void preOrdenIterativo(const struct ArbolBinario & arbol);
void postOrdenIterativo(const struct ArbolBinario & arbol) ;


void insertarEnCumulo(struct ArbolBinario & cumulo, int dato);
void intercambiarDatos(struct NodoArbolBinario * nodo1, struct NodoArbolBinario * nodo2);
void flotar(struct NodoArbolBinario *nodo) ;

#endif //ARBOLBINARIO_FUNCIONESARBOLBINARIO_H
