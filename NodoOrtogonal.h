//
// Created by aybso on 24/08/2019.
//

#ifndef MATRIZORTOGONAL_NODOORTOGONAL_H
#define MATRIZORTOGONAL_NODOORTOGONAL_H

#include <string>
using namespace std;

class NodoOrtogonal {
    
    private:
        string valor;
        string opacityColor;
        int posX, posY;
        NodoOrtogonal *arriba, *abajo, *izquierda, *derecha;
        
    public:
        NodoOrtogonal();
        NodoOrtogonal(string valor_, int posX_, int posY_);
        
        void setValor(string valor_, int posX_, int posY_);
        void setArriba(NodoOrtogonal* arriba_);
        void setAbajo(NodoOrtogonal* abajo_);
        void setIzquierda(NodoOrtogonal* izquierda_);
        void setDerecha(NodoOrtogonal* derecha_);
        void setOpacityColor(string color);
        void setX(int x);
        void setY(int y);
        
        
        string getValor();
        NodoOrtogonal* getArriba();
        NodoOrtogonal* getAbajo();
        NodoOrtogonal* getDerecha();
        NodoOrtogonal* getIzquierda();
        int getX();
        int getY();
        string getOpacityColor();

};


#endif //MATRIZORTOGONAL_NODOORTOGONAL_H
