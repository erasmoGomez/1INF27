//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef COLA_FUNCIONESCOLA_H
#define COLA_FUNCIONESCOLA_H

void construir(struct Cola & colaTAD);
void encolar(struct Cola &colaTAD, struct NodoArbolBinario * elemento);
struct NodoArbolBinario * desencolar(struct Cola & colaTAD);
bool esColaVacia(const struct Cola & colaTAD);
void imprimir(const struct Cola & colaTAD);
int longitud(const struct Cola & colaTAD) ;
void destruir(struct Cola & colaTAD);
#endif //COLA_FUNCIONESCOLA_H
