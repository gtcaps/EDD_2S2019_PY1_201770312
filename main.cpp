#include <iostream>
#include "MatrizOrtogonal.h"
#include "CuboOrtogonal.h"

int main() {
    /*
    MatrizOrtogonal* m = new MatrizOrtogonal();
    cubo->agregar("120-100-15",5,10,1);
    cubo->agregar("100-100-0",3,10,1);
    cubo->agregar("0-0-0",10,1,1);
    cubo->agregar("90-150-200",7,5,1);
    cubo->agregar("100,0,15",1,3,1);
    cubo->agregar("15,0,20",1,2,1);
    cubo->agregar("0-0-0", 1, 5,1);
    m->imprimir();
    */
    
    CuboOrtogonal* cubo = new CuboOrtogonal();
    cubo->agregar("120-100-15",5,10,1);
    cubo->agregar("100-100-0",3,10,1);
    cubo->agregar("0-0-0",10,1,1);
    cubo->agregar("90-150-200",7,5,1);
    cubo->agregar("100,0,15",1,3,1);
    cubo->agregar("15,0,20",1,2,1);
    cubo->agregar("0-0-0", 1, 5,1);
    //cubo->agregar("120-120-120", 5, 10, 5);
    
    cubo->imprimir();
    
    return 0;
}