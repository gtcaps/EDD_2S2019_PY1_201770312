//
// Created by aybso on 24/08/2019.
//

#ifndef MATRIZORTOGONAL_CUBOORTOGONAL_H
#define MATRIZORTOGONAL_CUBOORTOGONAL_H

#include "NodoZ.h"
#include "ListaDobleLineal.h"
#include <fstream>
#include <direct.h>

class CuboOrtogonal {

    private:
        NodoZ* cabeza;
        NodoZ* cola;
        int lengthZ;
        bool existeZ(int z);
        void agregarCabeceraZ(int z);
        NodoZ* getNodeZ(int z);
        int width, height, pixel_height, pixel_width;
        string nombreCubo = "";
        
    public:
        CuboOrtogonal(string nombre);
        
        void imprimir(string nombre);
        void agregar(int z);
        void agregar(string valor, int x, int y, int z);
        NodoZ* getCabeza();
        void setDimensiones(int w, int h, int ph, int pw);
        void setNombre(string nombre);
        
        int getWidth();
        int getHeight();
        int getPixelWidth();
        int getPixelHeight();
        string getNombre();
        
        void generateMatrix();
        ListaDobleLineal* linealizarMatrix();
        
        void generarImagen();
        
        void reporteCapas();
        
        //PRUEBA DE LOS FILTOS ------------------------
        void filtroNegativo();
        
        void filtroEscalaGrises();
        
        void filtroEspejoX();
        
        void filtroEspejoY();
        
        void filtroDobleEspejo();
        
};


#endif //MATRIZORTOGONAL_CUBOORTOGONAL_H
