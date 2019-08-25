//
// Created by aybso on 24/08/2019.
//

#include "MatrizOrtogonal.h"

bool MatrizOrtogonal::esNulo(NodoOrtogonal *nodo) {
    if(nodo == NULL){
        return true;
    }
    return false;
}

MatrizOrtogonal::MatrizOrtogonal() {
    raiz = new NodoOrtogonal("raiz",0,0);
    
    cabezaX = colaX = NULL;
    cabezaY = colaY = NULL;
    
    raiz->setDerecha(cabezaX);
    raiz->setAbajo(cabezaY);
    sizeX = 0;
    sizeY = 0;
}

void MatrizOrtogonal::insertarCabeceraX(int x) {
    
    if(esNulo(cabezaX)){
        cabezaX = colaX = new NodoOrtogonal("x", x,0);
        sizeX++;
    }else{
        
        if(existeX(x) == false){
            NodoOrtogonal* nuevaPosX = new NodoOrtogonal("x",x,0);
    
            if(nuevaPosX->getX() < cabezaX->getX() ){
                nuevaPosX->setDerecha(cabezaX);
                nuevaPosX->setIzquierda(cabezaX->getIzquierda());
                cabezaX->setIzquierda(nuevaPosX);
                cabezaX = nuevaPosX;
                raiz->setDerecha(cabezaX);
                sizeX++;
            }else if( nuevaPosX->getX() > colaX->getX() ){
                colaX->setDerecha(nuevaPosX);
                nuevaPosX->setIzquierda(colaX);
                colaX = nuevaPosX;
                sizeX++;
            }else{
                NodoOrtogonal* auxActual = cabezaX->getDerecha();
        
                while(auxActual != NULL){
                    if(nuevaPosX->getX() < auxActual->getX()){
                        nuevaPosX->setDerecha(auxActual);
                        nuevaPosX->setIzquierda(auxActual->getIzquierda());
                        auxActual->getIzquierda()->setDerecha(nuevaPosX);
                        auxActual->setIzquierda((nuevaPosX));
                        break;
                    }
                    auxActual = auxActual->getDerecha();
                }
            }
        }
        
    }
    
}

void MatrizOrtogonal::insertarCabeceraY(int y) {
    if(esNulo(cabezaY)){
        cabezaY = colaY = new NodoOrtogonal("y", 0,y);
        sizeY++;
    }else{
        
        if(existeY(y) == false){
            NodoOrtogonal* nuevaPosY = new NodoOrtogonal("y",0,y);
            
            if(nuevaPosY->getY() < cabezaY->getY() ){
                nuevaPosY->setAbajo(cabezaY);
                nuevaPosY->setArriba(cabezaY->getArriba());
                cabezaY->setArriba(nuevaPosY);
                cabezaY = nuevaPosY;
                raiz->setAbajo(cabezaY);
                sizeY++;
            }else if( nuevaPosY->getY() > colaY->getY() ){
                colaY->setAbajo(nuevaPosY);
                nuevaPosY->setArriba(colaY);
                colaY = nuevaPosY;
                sizeY++;
            }else{
                NodoOrtogonal* auxActual = cabezaY->getAbajo();
                
                while(auxActual != NULL){
                    if(nuevaPosY->getY() < auxActual->getY()){
                        nuevaPosY->setAbajo(auxActual);
                        nuevaPosY->setArriba(auxActual->getArriba());
                        auxActual->getArriba()->setAbajo(nuevaPosY);
                        auxActual->setArriba((nuevaPosY));
                        break;
                    }
                    auxActual = auxActual->getAbajo();
                }
            }
        }
        
    }
}

void MatrizOrtogonal::imprimir() {
    //IMPRIMIR X
    NodoOrtogonal* aux_x = cabezaX;
    
    if(aux_x == NULL){
        cout << "X esta vacia" << endl;
    }else{
        while(aux_x != NULL){
            cout << aux_x->getX() << endl;
            cout << "--------------------" << endl;
            
            NodoOrtogonal* fils = aux_x->getAbajo();
            if(fils == NULL){
                cout << "----------> Vacio" << endl;
            }else{
                while(fils != NULL){
                    cout << " [ "<< fils->getValor() <<" ," <<fils->getX() << " , " << fils->getY() << " ] --------> ";
                    fils = fils->getAbajo();
                }
                cout << endl << endl << endl;
            }
            
            aux_x = aux_x->getDerecha();
        }
        cout << endl;
    }
    
    cout << endl << endl << "-------------------" << endl;
    //IMPRIMIR Y
    
    NodoOrtogonal* aux_y= cabezaY;
    
    if(aux_y == NULL){
        cout << "Y esta vacia" << endl;
    }else{
        while(aux_y != NULL){
            cout << aux_y->getY() << endl;
            
            NodoOrtogonal* cols = aux_y->getDerecha();
            if(cols == NULL){
                cout << "----------> Vacio" << endl;
            }else{
                while(cols != NULL){
                    cout << " [ "<< cols->getValor() <<" ," <<cols->getX() << " , " << cols->getY() << " ] --------> ";
                    cols = cols->getDerecha();
                }
                cout << endl << endl << endl;
            }
            
            aux_y = aux_y->getAbajo();
        }
    }
    
}

bool MatrizOrtogonal::existeX(int x) {
    NodoOrtogonal* aux = cabezaX;
    if(aux != NULL){
        while(aux != NULL){
            if(aux->getX() == x){
                return true;
            }
            aux = aux->getDerecha();
        }
    }
    return false;
}

bool MatrizOrtogonal::existeY(int y) {
    NodoOrtogonal* aux = cabezaY;
    if(aux != NULL){
        while(aux != NULL){
            if(aux->getY() == y){
                return true;
            }
            aux = aux->getAbajo();
        }
    }
    return false;
}

NodoOrtogonal *MatrizOrtogonal::getX(int x) {
    if(existeX(x)){
        NodoOrtogonal* aux = cabezaX;
        while(aux != NULL){
            if( aux->getX() == x ){
                return aux;
            }
            aux = aux->getDerecha();
        }
    }
    return NULL;
}

NodoOrtogonal *MatrizOrtogonal::getY(int y) {
    if(existeY(y)){
        NodoOrtogonal* aux = cabezaY;
        while(aux != NULL){
            if( aux->getY() == y ){
                return aux;
            }
            aux = aux->getAbajo();
        }
    }
    return NULL;
}

void MatrizOrtogonal::insertar(string valor, int x, int y) {
    
    //INSERTAR CABECERAS
    insertarCabeceraX(x);
    insertarCabeceraY(y);
    
    //OBTENER LAS POSICIONES DE CABECERA
    NodoOrtogonal* posX = getX(x);
    NodoOrtogonal* posY = getY(y);
    
    //CREO EL NODO A INSERTAR
    NodoOrtogonal* nuevoPunto = new NodoOrtogonal(valor, x, y);
    
    //INSERTO EL NODO NUEVO EN LA POSICION X
    if(posX->getAbajo() == NULL){
        posX->setAbajo(nuevoPunto);
    }else{
        NodoOrtogonal* actual = posX->getAbajo();
        NodoOrtogonal* anterior = posX;
        
        while(actual != NULL){
            if(nuevoPunto->getY() < actual->getY() ){
                nuevoPunto->setAbajo(actual);
                nuevoPunto->setArriba(anterior);
                anterior->setAbajo(nuevoPunto);
                actual->setArriba(nuevoPunto);
                break;
            }
            anterior = actual;
            actual = actual->getAbajo();
        }
        
        if(actual == NULL){
            nuevoPunto->setArriba(anterior);
            anterior->setAbajo(nuevoPunto);
        }
    }
    
    //INSERTO EL NODO NUEVO EN LA POSICION Y
    if( posY->getDerecha() == NULL ){
        posY->setDerecha(nuevoPunto);
    }else{
        NodoOrtogonal* actual = posY->getDerecha();
        NodoOrtogonal* anterior = posY;
        
        while(actual != NULL){
            if(nuevoPunto->getX() < actual->getX()){
                nuevoPunto->setDerecha(actual);
                nuevoPunto->setIzquierda(anterior);
                anterior->setDerecha(nuevoPunto);
                actual->setIzquierda(anterior);
                break;
            }
            anterior = actual;
            actual = actual->getDerecha();
        }
        
        if(actual == NULL){
            nuevoPunto->setIzquierda(anterior);
            anterior->setDerecha(nuevoPunto);
        }
    }
    
    
}