//
// Created by erasmo on 5/11/26.
//

#include "FuncionesColas.hpp"

void ordenarec(struct Cola & cola, int n){//Recibimos la cola y la longitud de la cola
    int mayor, aux, i=1;
    //CASO BASE:
    if (esColaVacia(cola))
        return;
    //CASO RECURSIVO
    mayor=desencolar(cola);//desencolamos el primer elemento de la cola
    while (i<n){
        aux=desencolar(cola);//desencolamos los demás elementos para encontrar un posible mayor
        if (aux>mayor){//si elemento que hemos desencolado es mayor, tenemos un nuevo mayor
            encolar(cola, mayor);//el mayor (anterior) lo encolamos
            mayor=aux;//"guardamos" el nuevo mayor que hemos encontrado
        }
        else
            encolar(cola, aux);
        i++;
    }
    ordenarec(cola, n-1);//Aquí regresará en algún momento del CASO BASE
    encolar(cola, mayor);//encolamos el mayor de la instancia
}

/*Construye la Cola*/
void construir(struct Cola & cola){
    construir(cola.lista);
}

/*Verifica si la cola está vacía*/
bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

/*Devuelve la longitud de la cola*/
int longitud(const struct Cola & cola){
    return longitud(cola.lista);
}

/*Añade un elemento a la cola*/
void encolar(struct Cola & cola, int elemento){
    insertarencola(cola.lista, elemento);
    //cout<<"Encolando: "<<elemento<<endl;
}

/*Elimina un elemento de la cola*/
int desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        return -1; //Cero o algún elemento que no esté en la cola
    }
    else{
        int elemento = retornaCabeza(cola.lista);
        eliminaCabeza(cola.lista);
        if(esColaVacia(cola))
            cola.lista.cola = nullptr;
        return elemento;
    }

}

/*Muestra los elementos de la cola*/
void imprime(const struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede mostrar"<<endl;
    }
    else
        imprime(cola.lista);
}

void destruirCola(struct Cola & cola){
    destruir(cola.lista);
}


/*Valores iniciales de la lista*/
void construir(struct Lista & tad) {
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
const bool esListaVacia(const struct Lista & tad) {
    return tad.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista  & tad) {
    return tad.longitud;
}

/*inserta un nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & tad, int elemento) {

    /*Se va cambiar por la función crear nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = tad.cabeza;

    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

/*inserta un nodo siempre al final de la lista*/
void insertarAlFinal(struct Lista & tad, int elemento) {

    struct Nodo * ultimoNodo = obtenerUltimoNodo(tad);
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);

    if (ultimoNodo == nullptr) /*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    tad.longitud++;
}
/*inserta un nodo siempre al final de la cola*/
void insertarencola(struct Lista & tad, int elemento) {

    struct Nodo * ultimoNodo = tad.cola;
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);

    if (ultimoNodo == nullptr){/*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
        tad.cola = nuevoNodo;
    }
    else{ //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
        tad.cola = nuevoNodo;
    }
    tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(int elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

//Notar que esta función retorna nulo cuando la lista es vacía

/*Obtiene el último nodo de la lista*/
struct Nodo * obtenerUltimoNodo(const struct Lista & tad) {
    struct Nodo * ultimo = nullptr;
    struct Nodo* recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

/*inserta nodos al inicio de la lista desde un archivo*/
void insertarAlInicioArchivo(const char * nombArchText, struct Lista & tad) {
    ifstream archText(nombArchText, ios::in);
    if (not archText.is_open()) {
        cout << "ERROR: No se puede abrir el archivo";
        exit(1);
    }

    int elemento;
    while (true) {
        archText>>elemento; //lee el elemento del archivo
        if (archText.eof()) break;
        insertarAlInicio(tad, elemento);
    }
}

/*inserta un nodo en orden*/
void insertarEnOrden(struct Lista & tad, int elemento) {

    struct Nodo * nodoAnterior = obtenerNodoAnterior(tad, elemento);
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);
    /*Si nodoAnterior es igual a nulo, la lista está vacia, se debe
     insertar al inicio, no hay nodos menores que elemento*/
    if (nodoAnterior == nullptr) { /*la lista está vacia*/
        nuevoNodo->siguiente = tad.cabeza;
        tad.cabeza = nuevoNodo;
    } else {
        nuevoNodo->siguiente = nodoAnterior->siguiente;
        nodoAnterior->siguiente = nuevoNodo;
    }
    tad.longitud++;
}

/*retorna el anterior al que tiene el elemento*/
struct Nodo * obtenerNodoAnterior(const struct Lista & tad, int elemento) {
    struct Nodo * anterior = nullptr;
    struct Nodo * recorrido = tad.cabeza;
    while ((recorrido != nullptr) and (recorrido->elemento < elemento)) {
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    return anterior;
}

struct Nodo * seEncuentra(const struct Lista & tad, int elemento) {
    struct Nodo * recorrido = tad.cabeza;

    /*retorna el nodo correspondiente al elemento buscado*/
    while ((recorrido != nullptr) and (recorrido->elemento != elemento)) {
        recorrido = recorrido->siguiente;
    }
    return recorrido;
}

int retornaCabeza(const struct Lista & tad){
    return tad.cabeza->elemento;
}


void eliminaNodo(struct Lista & tad, int elemento) {
    struct Nodo * ultimo = nullptr;
    struct Nodo * recorrido = tad.cabeza;
    /*Avanzo hasta encontrar el elemento*/
    /*Si no lo encuentra no elimina nada*/
    while ((recorrido != nullptr) and (recorrido->elemento != elemento)) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr) /*Estoy al inicio de la lista*/
            tad.cabeza = recorrido->siguiente;
        else
            ultimo->siguiente = recorrido->siguiente;
        delete recorrido; /*libera la memoria*/
        tad.longitud--;
    }
}

void eliminaCabeza(struct Lista & tad) {
    struct Nodo * nodoAEliminar = tad.cabeza;
    if (nodoAEliminar != nullptr) {
        tad.cabeza = tad.cabeza->siguiente;
        delete nodoAEliminar;
        tad.longitud--;
    }
}

/*Elimina el último elemento de la lista, es llamado cola*/
void eliminaCola(struct Lista & tad) {
    struct Nodo * ultimo = nullptr;
    struct Nodo * penultimo = nullptr;
    struct Nodo * recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        if (ultimo != nullptr)
            penultimo = ultimo;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (ultimo != nullptr) {
        //Si no hay penultimo, se está¡ eliminando el Único nodo de la lista
        if (penultimo == nullptr)
            tad.cabeza = nullptr;
        else
            penultimo->siguiente = nullptr;
        delete ultimo;
        tad.longitud--;
    }
}

void destruir(struct Lista & tad) {
    /*recorrido apunta al inicio del tad*/
    struct Nodo * recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    /*la lista queda vacia*/
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la prOteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo tad.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprime(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(tad)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

void destruir_cola_chevere(struct Cola & cola) {
    //Caso Base
    if (esColaVacia(cola)) return;
    //Caso Recursivo
    desencolar(cola);
    destruir_cola_chevere(cola);
}

void ordenar_cola_iterativo(struct Cola & cola) {
    int k = 0;
    int mayor = 0, aux = 0;
    int n = cola.lista.longitud;
    for (int i=1; i<=n; i++) {
        mayor = desencolar(cola);
        for (int j=1; j<=n-1+1; j++) {
            aux = desencolar(cola);
            if (aux > mayor) {
                encolar(cola, mayor);
                mayor = aux;
            }
            else {
                encolar(cola, aux);
            }
        }
        for (int m = 0; m<k; m++) {
            aux = desencolar(cola);
            encolar(cola, aux);
        }
        k++;
        encolar(cola, mayor);
    }
}