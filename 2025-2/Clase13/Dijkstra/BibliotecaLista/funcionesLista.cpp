//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

void construir(struct Lista & listaTAD) {
    listaTAD.inicio = nullptr;
    listaTAD.longitud = 0;
}

bool esListaVacia(const struct Lista & listaTAD) {
    return listaTAD.inicio == nullptr;
}

/*Inserta un elemento siempre al final de la lista*/
void insertarVertice(struct Lista & listaTAD, const struct ElementoLista & elemento) {

    struct NodoLista * ultimoNodoLista = obtenerUltimoNodo(listaTAD);
    struct NodoLista * nuevo;
    nuevo = new struct NodoLista;
    nuevo->elemento = elemento;
    nuevo->abajo = nullptr;  //para manejar los vétices
    nuevo->siguiente = nullptr;  //importante para ingresar aristas

    if (ultimoNodoLista == nullptr) /*Si la lista está vacía*/
        listaTAD.inicio = nuevo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene NodoListas
        ultimoNodoLista->abajo = nuevo;

    listaTAD.longitud++;
}

/*Obtiene el último NodoLista de la lista*/
struct NodoLista * obtenerUltimoNodo(const struct Lista & listaTAD) {
    struct NodoLista * ultimo = nullptr;
    struct NodoLista* recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->abajo;
    }
    return ultimo;
}

void eliminaNodo(struct Lista & listaTAD, const struct ElementoLista & elemento) {
    struct NodoLista * ultimo = nullptr;
    struct NodoLista * recorrido = listaTAD.inicio;
    /*Avanzo hasta encontrar el elemento*/
    /*Si no lo encuentra no elimina nada*/
    while ((recorrido != nullptr) and (recorrido->elemento.codigo != elemento.codigo)) {
        ultimo = recorrido;
        recorrido = recorrido->abajo;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr) /*Estoy al inicio de la lista*/
            listaTAD.inicio = recorrido->abajo;
        else
            ultimo->abajo = recorrido->abajo;
        delete recorrido; /*libera la memoria*/
    }
    listaTAD.longitud--;
}

void destruir(struct Lista & listaTAD) {
    /*recorrido apunta al inicio del tad*/
    struct NodoLista * recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        /*NodoLista auxiliar que va servir para eliminar los NodoListas*/
        struct NodoLista * NodoListaAEliminar = recorrido;
        recorrido = recorrido->abajo;
        delete NodoListaAEliminar;
    }
    /*la lista queda vacia*/
    listaTAD.inicio = nullptr;
    listaTAD.longitud = 0;
}

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprimir(const struct Lista & listaTAD) {

    if (esListaVacia(listaTAD)) {
        cout << "La lista esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoLista * vertices = listaTAD.inicio;

        while (vertices != nullptr) {
            struct NodoLista * arista = vertices->siguiente;
            /*Este artificio coloca las comas despuÃ©s de la cabeza*/
            cout << "[" << vertices->elemento.codigo << "]: ";
            while (arista != nullptr) {
                //cout << arista->elemento.codigo << " (" << arista->elemento.peso << ")  ";
                cout << arista->elemento.codigo << "  ";
                arista = arista->siguiente;
            }
            cout << endl;
            vertices = vertices->abajo;
        }
    }
}

void insertarArista(struct Lista & listaVertices, const struct ElementoLista & origen, const struct ElementoLista & destino) {

    struct NodoLista * vertice = listaVertices.inicio;
    //ACA recorro los vértices... busca el vértice
    while (vertice != nullptr) {
        if (vertice->elemento.codigo == origen.codigo) {
            break;
        }
        vertice = vertice->abajo; //en el vértice
    }

    struct NodoLista * ultimo = nullptr;
    struct NodoLista* recorrido = vertice;
    //ACA recorro las aristas... busca la última arista
    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente; //en arista
    }

    //crea la nueva conexión
    struct NodoLista * nuevo = new struct NodoLista;
    nuevo->elemento = destino;
    nuevo->siguiente = nullptr;  //importante para ingresar aristas

    //Realiza el enlace
    if (ultimo == nullptr) /*Si la lista está vacía*/
        vertice->siguiente = nuevo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene NodoListas
        ultimo->siguiente = nuevo;
}

// Función para obtener la longitud del grafo
int longitudGrafo(struct Lista & grafo) {
    return grafo.longitud;
}

// Función para buscar un vértice por su código
struct NodoLista* buscarVertice(struct Lista & grafo, int codigo) {
    struct NodoLista * vertice = grafo.inicio;
    while (vertice != nullptr) {
        if (vertice->elemento.codigo == codigo) {
            return vertice;
        }
        vertice = vertice->abajo;
    }
    return nullptr;
}

// Algoritmo de Dijkstra principal
void algoritmoDijkstra(struct Lista & grafo, int ciudadOrigen) {
    int numCiudades = longitudGrafo(grafo);
    int vertices[5] {0, 2, 3, 4, 5}; //empizo de la ciudad 1
    int D[5]{};// distancias mínimas
    bool S[5]{}; //conjunto de vértices visitados
    int previo[numCiudades]; // Vértice anterior en el camino más corto
    int minimo = 0;
    int minIndice;

    for(int i = 0; i < numCiudades; i++) {
        D[i] = 999;         // Distancia infinita
        S[i] = false;       // Ningún vértice visitado
        previo[i] = -1;     // Sin vértice anterior
    }

    // La distancia al origen es 0
    D[ciudadOrigen-1] = 0;

    cout << endl;
    cout << "Ejecutando Dijkstra desde ciudad " << ciudadOrigen << endl;

    // Para cada vértice en el grafo
    for(int count = 0; count < numCiudades; count++) {
        // Encontrar el vértice con la distancia mínima no visitado
        int minDistancia = 999;
        int u = -1;

        for(int i = 0; i < numCiudades; i++) {
            if( not S[i] and D[i] < minDistancia) {
                minDistancia = D[i];
                u = i;
            }
        }

        if(u == -1) break; // No hay más vértices alcanzables

        // Marcar como visitado
        S[u] = true;
        int verticeActual = u + 1; // Convertir índice a código de vértice

        cout << endl;
        cout << "Visitando ciudad " << verticeActual << " con distancia " << D[u] << endl;

        // Actualizar distancias de los vértices adyacentes
        struct NodoLista * vertice = buscarVertice(grafo, verticeActual);
        if(vertice) {
            struct NodoLista * arista = vertice->siguiente;
            while(arista != nullptr) {
                int v = arista->elemento.codigo - 1; // Índice del vértice destino
                int peso = arista->elemento.peso;

                if( not S[v] and D[u] + peso < D[v]) {
                    D[v] = D[u] + peso;
                    previo[v] = u;
                    cout << "  Actualizando ciudad " << (v+1) << " a distancia " << D[v] << endl;
                }
                arista = arista->siguiente;
            }
        }

        // Mostrar estado actual de D
        cout << "Distancias: ";
        for(int i = 0; i < numCiudades; i++) {
            if(D[i] == 999) cout << setw(5) << "INF";
            else cout << setw(5) << D[i];
        }
        cout << endl;
    }

    // Mostrar resultados finales
    cout << "\nRESULTADOS FINALES:" << endl;
    cout << "Distancias minimas desde ciudad " << ciudadOrigen << ":" << endl;
    for(int i = 0; i < numCiudades; i++) {
        cout << "Ciudad " << (i+1) << ": ";
        if(D[i] == 999) cout << "INF" << endl;
        else cout << D[i] << endl;
    }

    // Mostrar caminos
    cout << "\nCaminos mas cortos:" << endl;
    for(int i = 0; i < numCiudades; i++) {
        if(i != ciudadOrigen-1) {
            cout << "Hacia ciudad " << (i+1) << ": ";
            if(D[i] == 999) {
                cout << "No hay camino" << endl;
            } else {
                // Reconstruir camino
                vector<int> camino;
                int actual = i;
                while(actual != -1) {
                    camino.push_back(actual + 1);
                    actual = previo[actual];
                }
                /*reverse(inicio, fin) toma dos iteradores y invierte completamente
                 *la secuencia de elementos entre ellos.*/
                reverse(camino.begin(), camino.end());
                for(int j = 0; j < camino.size(); j++) {
                    if(j > 0) cout << " -> ";
                    cout << camino[j];
                }
                cout << " (distancia: " << D[i] << ")" << endl;
            }
        }
    }
}
