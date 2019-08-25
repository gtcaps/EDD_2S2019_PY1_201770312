//
// Created by aybso on 24/08/2019.
//

#ifndef MATRIZORTOGONAL_MATRIZORTOGONAL_H
#define MATRIZORTOGONAL_MATRIZORTOGONAL_H

#include <iostream>
#include "NodoOrtogonal.h"

using namespace std;

class MatrizOrtogonal {

    
    private:
        NodoOrtogonal* raiz;
        NodoOrtogonal* cabezaX, *colaX;
        NodoOrtogonal* cabezaY, *colaY;
        
        int sizeX, sizeY;
        
        bool esNulo(NodoOrtogonal* nodo);
        bool existeX(int x);
        bool existeY(int y);
        void insertarCabeceraX(int x);
        void insertarCabeceraY(int y);
        
        NodoOrtogonal* getX(int x);
        NodoOrtogonal* getY(int y);
        
    public:
        MatrizOrtogonal();
        void insertar(string valor, int x, int y);
        
        void imprimir();
        
        
};


#endif //MATRIZORTOGONAL_MATRIZORTOGONAL_H
