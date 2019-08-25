#include <iostream>
#include "MatrizOrtogonal.h"


int main() {
    
    MatrizOrtogonal* m = new MatrizOrtogonal();
    m->insertar("120-100-15",5,10);
    m->insertar("100-100-0",3,10);
    m->insertar("0-0-0",10,1);
    m->insertar("90-150-200",7,5);
    m->insertar("100,0,15",1,3);
    m->insertar("15,0,20",1,2);
    m->insertar("0-0-0", 1, 5);
    m->imprimir();
    
    
    return 0;
}