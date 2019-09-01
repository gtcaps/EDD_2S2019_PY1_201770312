#include <iostream>
#include "MatrizOrtogonal.h"
#include "CuboOrtogonal.h"
#include <fstream>
#include "CargarImagen.h"

using namespace std;

int main() {
    
    CargarImagen* img = new CargarImagen("realmadrid", "realmadrid");
    CuboOrtogonal* kubo = img->getImagen();
    //kubo->generarImagen();
    
    CargarImagen* img2 = new CargarImagen("hulk","hulk");
    CuboOrtogonal* cubo = img2->getImagen();
    
    cout << "----> " << kubo << endl;
    cout << "----> " << cubo << endl;
    
    return 0;
}