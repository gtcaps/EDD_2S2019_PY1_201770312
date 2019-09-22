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
        //aux->getMatriz()->reporteLinealFilas();
        aux->getMatriz()->reporteLinealColumnas();
        while(aux != NULL){
            //cout << "Z = " << aux->getZ() << " ------> " << endl ;
            //aux->getMatriz()->imprimir();
            //cout << "Imprimi a mario "<< aux->getZ()  << endl << endl;
            //aux->getMatriz()->graficar(nombre, aux->getZ());
            //cout << endl << endl << endl;
            //aux = aux->getSiguiente();
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


void CuboOrtogonal::generarMosaico(MatrizOrtogonal* original) {
        
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
        
        if(original != NULL ){
            NodoOrtogonal* y = original->getCabezaY();
            html << "       <div class = \"container-upper\">" << endl;
            while( y != NULL){
                NodoOrtogonal* x = y->getDerecha();
                while(x != NULL){
                    html << "           <div class = \"big-pixel\"></div>" << endl;
                    x = x->getDerecha();
                }
                y = y->getAbajo();
            }
            html << "       </div>" << endl;
        }
        
        NodoLineal* a = l->getCabeza();
        while(a != NULL){
            if(a->getRed() == "x"){
                html << "       <div class = \"pixel\" style=\"background: transparent\">";
                html << "</div>" << endl;
            }else{
                html << "       <div class = \"pixel\" style=\"background: rgb("<< a->getColor() << ")\">";
                html << "</div>" << endl;
            }
            a = a->getSiguiente();
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
        css << "    position: relative;" << endl;
        css << "}" << endl << endl;
        css << ".pixel{" << endl;
        css << "    width:"<< pixel_width <<"px;" << endl;
        css << "    height:"<< pixel_height <<"px;" << endl;
        css << "    z-index: 1;>" << endl;
        css << "}" << endl << endl;
        css << ".container-upper{" << endl;
        css << "    position: absolute;" << endl;
        css << "    top: 0;" << endl;
        css << "    bottom: 0;" << endl;
        css << "    left: 0;" << endl;
        css << "    right: 0;" << endl;
        css << "    display: flex;" << endl;
        css << "    flex-wrap: wrap;" << endl;
        css << "    z-index: 1000;" << endl;
        css << "}" << endl << endl;
        css << ".big-pixel{" << endl;
        css << "    width: "<< pixel_width * original->getSizeX() <<"px;" << endl;
        css << "    height: "<< pixel_height * original->getSizeY() <<"px;" << endl;
        css << "    background: rgba(33,33,33,0.7);" << endl;
        css << "}" << endl << endl;
    
        int contador = 1;
        if(original != NULL){
            NodoOrtogonal* y = original->getCabezaY();
            while( y != NULL){
                NodoOrtogonal* x = y->getDerecha();
                
                while(x != NULL){
                    
                    string color = x->getValor();
                    if(color == "x"){
                        contador++;
                        x = x->getDerecha();
                        continue;
                    }else{
                        replace(color.begin(), color.end(), '-', ',');
                    }
                    
                    css << ".big-pixel:nth-child(" << contador << "){" << endl;
                    css << "    background: rgba(" <<  color << ", 0.8);" << endl;
                    css << "}" << endl << endl;
                    x = x->getDerecha();
                    contador++;
                }
                y = y->getAbajo();
            }
        }
        
        css.close();
        
    
}

void CuboOrtogonal::generarCollage() {
    
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
    NodoLineal* a = l->getCabeza();
    while(a != NULL){
        if(a->getRed() == "x"){
            html << "       <div class = \"pixel\" style=\"background: transparent\">";
            html << "</div>" << endl;
        }else{
            html << "       <div class = \"pixel\" style=\"background: rgb("<< a->getColor() << ")\">";
            html << "</div>" << endl;
        }
        a = a->getSiguiente();
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
    css << "    position: relative;" << endl;
    css << "}" << endl << endl;
    css << ".pixel{" << endl;
    css << "    width:"<< pixel_width <<"px;" << endl;
    css << "    height:"<< pixel_height <<"px;" << endl;
    css << "    z-index: 1;>" << endl;
    css << "}" << endl << endl;
    
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
                
                lista->add(pos, red, green, blue,x->getOpacityColor());
                
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
        nombreCubo = nombreCubo + "_negativo";
    }
    
    //generarImagen();
    
}

void CuboOrtogonal::filtroEscalaGrises() {
    if(cabeza->getSiguiente() != NULL){
        NodoZ* aux = cabeza->getSiguiente();
        while(aux != NULL){
            aux->getMatriz()->filtroEscalaGrises();
            aux = aux->getSiguiente();
        }
        nombreCubo = nombreCubo + "_grises";
    }
    
    //generarImagen();
}

void CuboOrtogonal::filtroEspejoX() {

    if(cabeza->getSiguiente() != NULL){
        NodoZ* aux = cabeza->getSiguiente();
        while(aux != NULL){
            MatrizOrtogonal* espejo = aux->getMatriz()->filtroEspejoX(width);
            aux->setMatriz(espejo);
            aux = aux->getSiguiente();
        }
        nombreCubo = nombreCubo + "_espejox";
    }
    
    //generarImagen();
    
}

void CuboOrtogonal::filtroEspejoY() {
    if(cabeza->getSiguiente() != NULL){
        NodoZ* aux = cabeza->getSiguiente();
        while(aux != NULL){
            MatrizOrtogonal* espejo = aux->getMatriz()->filtroEspejoY(height);
            aux->setMatriz(espejo);
            aux = aux->getSiguiente();
        }
        nombreCubo = nombreCubo + "_espejoy";
    }
    
    //generarImagen();
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
        nombreCubo = nombreCubo + "_dobleespejo";
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
    
    //generarImagen();
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

void CuboOrtogonal::filtroCollage(int x, int y) {
    
    if(cabeza != NULL){
        
        NodoZ* aux = cabeza;
        while(aux != NULL){
            MatrizOrtogonal* collage = aux->getMatriz()->filtroCollage(width, height, x, y);
            aux->setMatriz(collage);
            aux = aux->getSiguiente();
        }
        
        
        width = width * x;
        height = height * y;
        
        nombreCubo = nombreCubo + "_collage";
        //generarCollage();
    }
    cout << endl << endl << "Imagen generada" << endl << endl;
}

void CuboOrtogonal::filtroMosaico() {
    
    if(cabeza != NULL){
        cout << endl  << "Generando Mosaico: " << nombreCubo << endl;
        
        generateMatrix();
        MatrizOrtogonal* copia = cabeza->getMatriz()->getCopiaMatriz();
        
        NodoZ* aux = cabeza;
        while(aux != NULL){
            MatrizOrtogonal* collage = aux->getMatriz()->filtroCollage(width, height, width, height);
            aux->setMatriz(collage);
            aux = aux->getSiguiente();
        }
        
        
        width = width * width;
        height = height * height;
        
        int factorDivisionW = 10, factorDivisionH = 10;
        if(pixel_width < 40){
            factorDivisionW = 7;
        }
        
        if(pixel_height < 40){
            factorDivisionH = 7;
        }
        
        pixel_width = pixel_width / factorDivisionW;
        pixel_height = pixel_height / factorDivisionH;
    
        nombreCubo = nombreCubo + "_mosaico";
        //generarMosaico(copia);
        
    }
    cout << endl  << "Mosaico generada" << endl << endl;
    
}

CuboOrtogonal *CuboOrtogonal::getCopiaCubo() {
    if(cabeza != NULL){
        
        NodoZ* aux = cabeza;
        CuboOrtogonal* nuevoCubo = new CuboOrtogonal(nombreCubo + "_");
        nuevoCubo->setDimensiones(width, height, pixel_height, pixel_width);
        
        while(aux != NULL){
            
            MatrizOrtogonal* m = aux->getMatriz();
            NodoOrtogonal* y = m->getCabezaY();
            
            while(y != NULL){
                
                NodoOrtogonal* x = y->getDerecha();
                
                while(x != NULL){
                    
                    nuevoCubo->agregar(x->getValor(), x->getX(), x->getY(), aux->getZ());
                    
                    x = x->getDerecha();
                }
                
                
                y = y->getAbajo();
            }
            
            
            aux = aux->getSiguiente();
        }
        return nuevoCubo;
    }
    
    return NULL;
}











