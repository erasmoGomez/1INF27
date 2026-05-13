//
// Created by Erasmo on 26/09/25.
//

#ifndef QUEUES_COLA_HPP
#define QUEUES_COLA_HPP
#include "Utils.hpp"
#include "NodoCola.hpp"
struct Cola{
    struct NodoCola *inicio;
    struct NodoCola * fin;
    int longitud;
};
#endif //QUEUES_COLA_HPP
