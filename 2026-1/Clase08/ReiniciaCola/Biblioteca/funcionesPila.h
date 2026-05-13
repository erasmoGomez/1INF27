//Fecha:  lunes 01 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef PILA_FUNCIONES_H
#define PILA_FUNCIONES_H

void construir(struct Pila & pilaTAD);
bool esPilaVacia(const struct Pila & pilaTAD);
void apilar(struct Pila & pilaTAD, const struct Elemento & elemento);
struct Elemento desapilar(struct Pila & pilaTAD);
void imprimir(const struct Pila & pilaTAD);
int longitud(Pila & pilaTAD);
#endif //PILA_FUNCIONES_H