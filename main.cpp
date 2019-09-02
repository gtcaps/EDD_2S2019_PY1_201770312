#include <iostream>
#include "MatrizOrtogonal.h"
#include "CuboOrtogonal.h"
#include <fstream>
#include "CargarImagen.h"
#include "ABB.h"

using namespace std;

int main() {
    
    CargarImagen* img = new CargarImagen("realmadrid", "realmadrid");
    CuboOrtogonal* kubo = img->getImagen();
    //kubo->generarImagen();
    
    CargarImagen* img2 = new CargarImagen("deadpool","deadpool");
    CuboOrtogonal* cubo = img2->getImagen();
    cubo->generarImagen();
    //cubo->filtroNegativo();
    //cubo->filtroEscalaGrises();
    //cubo->filtroEspejoY();
    //cubo->filtroEspejoX();
    //cubo->filtroDobleEspejo();
    
    
    CargarImagen* img3 = new CargarImagen("mario","mario");
    CuboOrtogonal* mario = img3->getImagen();
    //mario->filtroNegativo();
    //mario->generarImagen();
    //mario->filtroEscalaGrises();
    //mario->filtroEspejoX();
    //mario->filtroEspejoY();
    //mario->filtroDobleEspejo();
    //mario->reporteCapas();
    
    /*
    cout << "----> " << kubo << endl;
    cout << "----> " << cubo << endl;
    
    ABB* arbolImagenes = new ABB();
    arbolImagenes->add(img->getImagen()->getNombre() , img->getImagen());
    arbolImagenes->add(cubo->getNombre(), cubo);
    arbolImagenes->graficarABB();
    arbolImagenes->graficarEnOrden();
    arbolImagenes->graficarPreOrden();
    arbolImagenes->graficarPostOrden();
    arbolImagenes->getOpcionesEnOrden();
    */
    
    return 0;
}