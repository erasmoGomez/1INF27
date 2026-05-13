//
// Created by Erasmo on 26/09/25.
//

#ifndef QUEUES_NODOCOLA_HPP
#define QUEUES_NODOCOLA_HPP
#include "ElementoCola.hpp"

struct NodoCola{
    struct ElementoCola elemento;
    struct NodoCola *siguiente;
};
#endif //QUEUES_NODOCOLA_HPP
