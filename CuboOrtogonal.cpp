//
// Created by aybso on 24/08/2019.
//

#include "CuboOrtogonal.h"

CuboOrtogonal::CuboOrtogonal() {
    cabeza = NULL;
    cola = NULL;
    lengthZ = 0;
}

bool CuboOrtogonal::existeZ(int z) {
    NodoZ* aux = cabeza;
    if(aux != NULL){
        while(aux != NULL){
            if(aux->getZ() == z){
                return true;
            }
            aux = aux->getSiguiente();
        }
    }
    return false;
}

void CuboOrtogonal::agregarCabeceraZ(int z) {
    if(!existeZ(z)){
        if(cabeza == NULL){
            cabeza = cola = new NodoZ(z);
        }else{
            NodoZ* nuevaPosicion = new NodoZ(z);
            if(z < cabeza->getZ()){
                nuevaPosicion->setSiguiente(cabeza);
                cabeza->setAnterior(nuevaPosicion);
                cabeza = nuevaPosicion;
            }else if(z > cola->getZ()){
                cola->setSiguiente(nuevaPosicion);
                nuevaPosicion->setAnterior(cola);
                cola = nuevaPosicion;
            }else{
                NodoZ* actual = cabeza->getSiguiente();
                while(actual != NULL){
                    if(z < actual->getZ()){
                        actual->getAnterior()->setSiguiente(nuevaPosicion);
                        nuevaPosicion->setAnterior(actual->getAnterior());
                        nuevaPosicion->setSiguiente(actual);
                        actual->setAnterior(nuevaPosicion);
                        break;
                    }
                    actual = actual->getSiguiente();
                }
            }
        }
    }
}

void CuboOrtogonal::agregar(string valor, int x, int y, int z) {
    //INGRESA LA CABECERA
    agregarCabeceraZ(z);
    
    //OBTENEMOS EL NODO Z DONDE SE LLENARA LA MATRIZ
    NodoZ* posZ = getNodeZ(z);
    
    //AGREGAMOS ELEMENTOS A LA MATRIZ
    posZ->insertar(valor, x, y);
    
    
}

NodoZ *CuboOrtogonal::getNodeZ(int z) {
    if(cabeza != NULL){
        NodoZ* aux = cabeza;
        while(aux != NULL){
            if(aux->getZ() == z){
                return aux;
            }
            aux = aux->getSiguiente();
        }
    }
    return NULL;
}

void CuboOrtogonal::imprimir() {

    if(cabeza == NULL){
        cout << "El cubo esta vacio" << endl;
    }else{
        NodoZ* aux = cabeza;
        while(aux != NULL){
            cout << "Z = " << aux->getZ() << " ------> " << endl ;
            aux->getMatriz()->imprimir();
            cout << endl << endl << endl;
            aux = aux->getSiguiente();
        }
    }
    
}

NodoZ *CuboOrtogonal::getCabeza() {
    return cabeza;
}
