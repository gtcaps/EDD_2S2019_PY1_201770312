//
// Created by aybso on 24/08/2019.
//

#ifndef MATRIZORTOGONAL_CUBOORTOGONAL_H
#define MATRIZORTOGONAL_CUBOORTOGONAL_H

#include "NodoZ.h"
#include "ListaDobleLineal.h"
#include <fstream>
#include <direct.h>
#include <algorithm>

class CuboOrtogonal {

    private:
        NodoZ* cabeza;
        NodoZ* cola;
        int lengthZ;
        void agregarCabeceraZ(int z);
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
        
        NodoZ* getNodeZ(int z);
        bool existeZ(int z);
        
        int getWidth();
        int getHeight();
        int getPixelWidth();
        int getPixelHeight();
        string getNombre();
        
        void generateMatrix();
        ListaDobleLineal* linealizarMatrix();
        
        void generarImagen();
        
        void generarMosaico(MatrizOrtogonal* original);
        void generarCollage();
        
        
        void reporteCapas();
        
        // FILTROS
        void filtroNegativo();
        
        void filtroEscalaGrises();
        
        void filtroEspejoX();
        
        void filtroEspejoY();
        
        void filtroDobleEspejo();
        
        void filtroCollage(int x, int y);
        
        void filtroMosaico();
        
        
        CuboOrtogonal* getCopiaCubo();
        
};


#endif //MATRIZORTOGONAL_CUBOORTOGONAL_H
