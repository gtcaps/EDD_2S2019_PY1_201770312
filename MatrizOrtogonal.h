//
// Created by aybso on 24/08/2019.
//

#ifndef MATRIZORTOGONAL_MATRIZORTOGONAL_H
#define MATRIZORTOGONAL_MATRIZORTOGONAL_H

#include <iostream>
#include "NodoOrtogonal.h"
#include <fstream>
#include <algorithm>
#include <math.h>

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
        void graficar(string nombre, int z);
        void graficar(string nombre, int z, string img);
        
        NodoOrtogonal* getNodo(int x, int y);
        NodoOrtogonal* getCabezaX();
        NodoOrtogonal* getCabezaY();
        
        //FILTROS
        void filtroNegativo();
        void filtroEscalaGrises();
        MatrizOrtogonal* filtroEspejoX(int width);
        MatrizOrtogonal* filtroEspejoY(int height);
        MatrizOrtogonal* filtroCollage(int width, int height, int repX, int repY);
        MatrizOrtogonal* filtroMosaico(int width, int height);
        
        MatrizOrtogonal* getCopiaMatriz();
        
        int getSizeX();
        int getSizeY();
        
        void reporteLinealFilas();
        void reporteLinealColumnas();
        
        
};


#endif //MATRIZORTOGONAL_MATRIZORTOGONAL_H
