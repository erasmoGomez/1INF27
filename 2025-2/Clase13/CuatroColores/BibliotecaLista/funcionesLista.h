//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal 

#ifndef LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H
#define LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H

void construir(struct Lista & listaTAD);
bool esListaVacia(const struct Lista & listaTAD);

//void insertarAlInicio(struct Lista & listaTAD, const struct ElementoLista & elemento);
void insertarVertice(struct Lista & listaTAD, const struct ElementoLista & elemento);
struct NodoLista * obtenerUltimoNodo(const struct Lista & listaTAD);
void insertarArista(struct Lista & listaVertices, const struct ElementoLista & origen, const struct ElementoLista & destino);
void eliminaNodo(struct Lista & listaTAD, const struct ElementoLista & elemento);
void destruir(struct Lista & listaTAD) ;
void imprimir(const struct Lista & listaTAD);


int longitudGrafo(struct Lista & grafo) ;
struct NodoLista* buscarVertice(struct Lista & grafo, int codigo) ;


#endif //LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H