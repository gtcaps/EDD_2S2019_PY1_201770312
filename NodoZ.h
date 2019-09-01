//
// Created by aybso on 24/08/2019.
//

#ifndef MATRIZORTOGONAL_NODOZ_H
#define MATRIZORTOGONAL_NODOZ_H
#include "MatrizOrtogonal.h"


class NodoZ {

    private:
        MatrizOrtogonal* matriz;
        int posZ;
        NodoZ* siguiente;
        NodoZ* anterior;
        
        
    public:
        NodoZ();
        NodoZ(int z);
        NodoZ(string valor, int x, int y, int z);
        
        MatrizOrtogonal* getMatriz();
        int getZ();
        NodoZ* getSiguiente();
        NodoZ* getAnterior();
        
        void insertar(string valor, int x, int y);
        void setZ(int z);
        void setSiguiente(NodoZ* siguiente);
        void setAnterior(NodoZ* anterior);
        
};


#endif //MATRIZORTOGONAL_NODOZ_H
