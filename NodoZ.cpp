//
// Created by aybso on 24/08/2019.
//

#include "NodoZ.h"

NodoZ::NodoZ() {
    matriz = new MatrizOrtogonal();
    posZ = -1;
    siguiente = NULL;
    anterior = NULL;
}

NodoZ::NodoZ(string valor, int x, int y, int z) {
    matriz = new MatrizOrtogonal();
    matriz->insertar(valor, x, y);
    posZ = z;
    siguiente = NULL;
    anterior = NULL;
}

MatrizOrtogonal *NodoZ::getMatriz() {
    return matriz;
}

int NodoZ::getZ() {
    return posZ;
}

NodoZ *NodoZ::getSiguiente() {
    return siguiente;
}

NodoZ *NodoZ::getAnterior() {
    return anterior;
}

void NodoZ::insertar(string valor, int x, int y) {
    matriz->insertar(valor, x, y);
}

void NodoZ::setZ(int z) {
    posZ = z;
}

void NodoZ::setSiguiente(NodoZ *siguiente_) {
    siguiente = siguiente_;
}

void NodoZ::setAnterior(NodoZ *anterior_) {
    anterior = anterior_;
}

NodoZ::NodoZ(int z) {
    posZ = z;
    matriz = new MatrizOrtogonal();
    siguiente = NULL;
    anterior = NULL;
}

void NodoZ::setMatriz(MatrizOrtogonal *matriz_) {
    matriz = matriz_;
}
