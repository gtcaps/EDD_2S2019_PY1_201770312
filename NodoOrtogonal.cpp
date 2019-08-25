//
// Created by aybso on 24/08/2019.
//

#include "NodoOrtogonal.h"

NodoOrtogonal::NodoOrtogonal() {
    valor = "";
    posX = 0;
    posY = 0;
    arriba = NULL;
    abajo = NULL;
    derecha = NULL;
    izquierda = NULL;
    
}

NodoOrtogonal::NodoOrtogonal(string valor_, int posX_, int posY_) {
    valor = valor_;
    posX = posX_;
    posY = posY_;
    arriba = NULL;
    abajo = NULL;
    izquierda = NULL;
    derecha = NULL;
}

void NodoOrtogonal::setValor(string valor_, int posX_, int posY_) {
    valor = valor_;
    posX = posX_;
    posY = posY_;
}

void NodoOrtogonal::setDerecha(NodoOrtogonal *derecha_) {
    derecha = derecha_;
}

void NodoOrtogonal::setArriba(NodoOrtogonal *arriba_) {
    arriba = arriba_;
}

void NodoOrtogonal::setAbajo(NodoOrtogonal *abajo_) {
    abajo = abajo_;
}

void NodoOrtogonal::setIzquierda(NodoOrtogonal *izquierda_) {
    izquierda = izquierda_;
}

string NodoOrtogonal::getValor() {
    return valor;
}

NodoOrtogonal *NodoOrtogonal::getAbajo() {
    return abajo;
}

NodoOrtogonal *NodoOrtogonal::getIzquierda() {
    return izquierda;
}

NodoOrtogonal *NodoOrtogonal::getArriba() {
    return arriba;
}

NodoOrtogonal *NodoOrtogonal::getDerecha() {
    return derecha;
}

void NodoOrtogonal::setX(int x) {
    posX = x;
}

void NodoOrtogonal::setY(int y) {
    posY = y;
}

int NodoOrtogonal::getX() {
    return posX;
}

int NodoOrtogonal::getY() {
    return posY;
}
