//
// Created by aybso on 24/08/2019.
//

#include "CuboOrtogonal.h"

CuboOrtogonal::CuboOrtogonal(string nombre) {
    nombreCubo = nombre;
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

void CuboOrtogonal::imprimir(string nombre) {

    if(cabeza == NULL){
        cout << "El cubo esta vacio" << endl;
    }else{
        NodoZ* aux = cabeza;
        while(aux != NULL){
            //cout << "Z = " << aux->getZ() << " ------> " << endl ;
            //aux->getMatriz()->imprimir();
            //cout << "Imprimi a mario "<< aux->getZ()  << endl << endl;
            aux->getMatriz()->graficar(nombre, aux->getZ());
            //cout << endl << endl << endl;
            aux = aux->getSiguiente();
        }
    }
    
    
    
}

NodoZ *CuboOrtogonal::getCabeza() {
    return cabeza;
}

void CuboOrtogonal::agregar(int z) {
    agregarCabeceraZ(z);
}

void CuboOrtogonal::setDimensiones(int w, int h, int ph, int pw) {
    width = w;
    height = h;
    pixel_width = pw;
    pixel_height = ph;
}

int CuboOrtogonal::getWidth() {
    return width;
}

int CuboOrtogonal::getHeight() {
    return height;
}

int CuboOrtogonal::getPixelWidth() {
    return pixel_width;
}

int CuboOrtogonal::getPixelHeight() {
    return pixel_height;
}

void CuboOrtogonal::generateMatrix(){
    MatrizOrtogonal* base = cabeza->getMatriz();
    NodoZ* aux = cabeza->getSiguiente();
    
    
    
    int c = 0;
    while(aux != NULL){
        MatrizOrtogonal* mod = aux->getMatriz();
        NodoOrtogonal* y = mod->getCabezaY();
        
        
        while(y != NULL){
            
            NodoOrtogonal* x = y->getDerecha();
            while(x != NULL){
                NodoOrtogonal* modificarNodo = base->getNodo(x->getX(), x->getY());
                modificarNodo->setValor(x->getValor(), modificarNodo->getX(), modificarNodo->getY());
                x = x->getDerecha();
            }
            y = y->getAbajo();
        }
        aux = aux->getSiguiente();
    }
    
}

void CuboOrtogonal::generarImagen() {
    
    ListaDobleLineal* l = linealizarMatrix();
    
    //CREO LA CARPETA
    string cmdCarpeta = "./Exports/" + nombreCubo;
    _mkdir(cmdCarpeta.c_str());
    
    string path = "./Exports/" + nombreCubo + "/";
    
    //ARCHIVO HTML
    ofstream html;
    html.open(path + nombreCubo + ".html");
    html << "<!DOCTYPE html>" << endl;
    html << "<html>" << endl;
    html << "   <head>" << endl;
    html << "       <meta charset=\"UTF-8\"  >" << endl;
    html << "       <title>"<< nombreCubo <<"</title>" << endl;
    html << "       <link rel=\"stylesheet\" href=\"./"<< nombreCubo <<".css\">" << endl;
    html << "   </head>" << endl;
    html << "   <body>" << endl;
    html << "   <div class = \"image-container\">" << endl;
    
    for(int i = 0; i < l->getSize(); i++){
        html << "       <div class = \"pixel\"></div>" << endl;
    }
    
    html << "   </div>" << endl;
    html << "   </body>" << endl;
    html << "</html>" << endl;
    html.close();
    
    
    //ARCHIVO CSS
    ofstream css;
    css.open(path + nombreCubo + ".css");
    css << "*{\n    margin:0; \n    padding: 0;\n}" << endl << endl;
    css << "body{" << endl;
    css << "    background: #BDBDBD;" << endl;
    css << "}" << endl << endl;
    css << ".image-container{" << endl;
    css << "    margin:0 auto;" << endl;
    css << "    margin-top: 150px;" << endl;
    css << "    margin-bottom: 150px;" << endl;
    css << "    width:"<<(width * pixel_width)<<"px;" << endl;
    css << "    height:"<< (height * pixel_height) <<"px ;" << endl;
    css << "    display: flex;" << endl;
    css << "    flex-wrap: wrap;" << endl;
    css << "    background: transparent;" << endl;
    css << "}" << endl << endl;
    css << ".pixel{" << endl;
    css << "    width:"<< pixel_width <<"px;" << endl;
    css << "    height:"<< pixel_height <<"px;" << endl;
    css << "}" << endl << endl;
    
    NodoLineal* color = l->getCabeza();
    while(color != NULL){
        css << ".pixel:nth-child("<< color->getPosicion() <<"){" << endl;
        
        if(color->getRed() == "x"){
            css << " background: transparent;" << endl;
        }else{
            css << " background: rgb( "<< color->getColor() <<" );" << endl;
        }
        
        css << "}" << endl << endl;
        color = color->getSiguiente();
    }
    
    css.close();
    
}

ListaDobleLineal* CuboOrtogonal::linealizarMatrix() {
    
    generateMatrix();
    ListaDobleLineal* lista = new ListaDobleLineal();
    
    MatrizOrtogonal* base = cabeza->getMatriz();
    NodoOrtogonal* y = base->getCabezaY();
    int pos = 0;
    
    while(y != NULL){
        
        NodoOrtogonal* x = y->getDerecha();
        while(x != NULL){
            
            if(x->getValor() == "x"){
                lista->add(pos, "x","x","x");
                pos++;
            }else{
                size_t posComa = x->getValor().find("-");
                string red = x->getValor().substr(0, posComa);
                
                string auxG = x->getValor().substr(posComa + 1);
                posComa = auxG.find("-");
                string green = auxG.substr(0, posComa);
                
                string blue = auxG.substr(posComa + 1);
                
                lista->add(pos, red, green, blue);
                
                pos++;
            }
            
            
            x = x->getDerecha();
        }
        y = y->getAbajo();
    }
    
    return lista;
    
}

void CuboOrtogonal::setNombre(string nombre) {
    nombreCubo = nombre;
}

string CuboOrtogonal::getNombre() {
    return nombreCubo;
}

//FILTROS EN PRUEBA ------------------------------------

void CuboOrtogonal::filtroNegativo() {
    
    if(cabeza->getSiguiente() != NULL){
        NodoZ* aux = cabeza->getSiguiente();
        while(aux != NULL){
            aux->getMatriz()->filtroNegativo();
            aux = aux->getSiguiente();
        }
    }
    
    generarImagen();
    
}

void CuboOrtogonal::filtroEscalaGrises() {
    if(cabeza->getSiguiente() != NULL){
        NodoZ* aux = cabeza->getSiguiente();
        while(aux != NULL){
            aux->getMatriz()->filtroEscalaGrises();
            aux = aux->getSiguiente();
        }
    }
    
    generarImagen();
}

void CuboOrtogonal::filtroEspejoX() {

    if(cabeza->getSiguiente() != NULL){
        NodoZ* aux = cabeza->getSiguiente();
        while(aux != NULL){
            MatrizOrtogonal* espejo = aux->getMatriz()->filtroEspejoX(width);
            aux->setMatriz(espejo);
            aux = aux->getSiguiente();
        }
    }
    
    generarImagen();
    
}

void CuboOrtogonal::filtroEspejoY() {
    if(cabeza->getSiguiente() != NULL){
        NodoZ* aux = cabeza->getSiguiente();
        while(aux != NULL){
            MatrizOrtogonal* espejo = aux->getMatriz()->filtroEspejoY(height);
            aux->setMatriz(espejo);
            aux = aux->getSiguiente();
        }
    }
    
    generarImagen();
}

void CuboOrtogonal::filtroDobleEspejo() {
    
    //FILTRO EN X
    if(cabeza->getSiguiente() != NULL){
        NodoZ* aux = cabeza->getSiguiente();
        while(aux != NULL){
            MatrizOrtogonal* espejo = aux->getMatriz()->filtroEspejoX(width);
            aux->setMatriz(espejo);
            aux = aux->getSiguiente();
        }
    }
    
    //FILTRO EN Y
    if(cabeza->getSiguiente() != NULL){
        NodoZ* aux = cabeza->getSiguiente();
        while(aux != NULL){
            MatrizOrtogonal* espejo = aux->getMatriz()->filtroEspejoY(height);
            aux->setMatriz(espejo);
            aux = aux->getSiguiente();
        }
    }
    
    generarImagen();
}

void CuboOrtogonal::reporteCapas() {
    if(cabeza != NULL){
        generateMatrix();
        NodoZ* aux = cabeza;
        
        while(aux != NULL){
            aux->getMatriz()->graficar(nombreCubo, aux->getZ());
            aux = aux->getSiguiente();
        }
    }
}












