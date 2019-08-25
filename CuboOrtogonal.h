//
// Created by aybso on 24/08/2019.
//

#ifndef MATRIZORTOGONAL_CUBOORTOGONAL_H
#define MATRIZORTOGONAL_CUBOORTOGONAL_H

#include "NodoZ.h"


class CuboOrtogonal {

    private:
        NodoZ* cabeza;
        NodoZ* cola;
        int lengthZ;
        bool existeZ(int z);
        void agregarCabeceraZ(int z);
        NodoZ* getNodeZ(int z);
        
    public:
        CuboOrtogonal();
        
        void imprimir();
        void agregar(string valor, int x, int y, int z);
        NodoZ* getCabeza();
        
        
        
};


#endif //MATRIZORTOGONAL_CUBOORTOGONAL_H
