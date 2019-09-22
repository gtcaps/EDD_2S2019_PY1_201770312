//
// Created by aybso on 24/08/2019.
//

#include "MatrizOrtogonal.h"

bool MatrizOrtogonal::esNulo(NodoOrtogonal *nodo) {
    if(nodo == NULL){
        return true;
    }
    return false;
}

MatrizOrtogonal::MatrizOrtogonal() {
    raiz = new NodoOrtogonal("raiz",0,0);
    
    cabezaX = colaX = NULL;
    cabezaY = colaY = NULL;
    
    raiz->setDerecha(cabezaX);
    raiz->setAbajo(cabezaY);
    sizeX = 0;
    sizeY = 0;
}

void MatrizOrtogonal::insertarCabeceraX(int x) {
    
    if(esNulo(cabezaX)){
        cabezaX = colaX = new NodoOrtogonal("x", x,0);
        sizeX++;
    }else{
        
        if(existeX(x) == false){
            NodoOrtogonal* nuevaPosX = new NodoOrtogonal("x",x,0);
    
            if(nuevaPosX->getX() < cabezaX->getX() ){
                nuevaPosX->setDerecha(cabezaX);
                nuevaPosX->setIzquierda(cabezaX->getIzquierda());
                cabezaX->setIzquierda(nuevaPosX);
                cabezaX = nuevaPosX;
                raiz->setDerecha(cabezaX);
                sizeX++;
            }else if( nuevaPosX->getX() > colaX->getX() ){
                colaX->setDerecha(nuevaPosX);
                nuevaPosX->setIzquierda(colaX);
                colaX = nuevaPosX;
                sizeX++;
            }else{
                NodoOrtogonal* auxActual = cabezaX->getDerecha();
        
                while(auxActual != NULL){
                    if(nuevaPosX->getX() < auxActual->getX()){
                        nuevaPosX->setDerecha(auxActual);
                        nuevaPosX->setIzquierda(auxActual->getIzquierda());
                        auxActual->getIzquierda()->setDerecha(nuevaPosX);
                        auxActual->setIzquierda((nuevaPosX));
                        sizeX++;
                        break;
                    }
                    auxActual = auxActual->getDerecha();
                }
            }
        }
        
    }
    
}

void MatrizOrtogonal::insertarCabeceraY(int y) {
    if(esNulo(cabezaY)){
        cabezaY = colaY = new NodoOrtogonal("y", 0,y);
        sizeY++;
    }else{
        
        if(existeY(y) == false){
            NodoOrtogonal* nuevaPosY = new NodoOrtogonal("y",0,y);
            
            if(nuevaPosY->getY() < cabezaY->getY() ){
                nuevaPosY->setAbajo(cabezaY);
                nuevaPosY->setArriba(cabezaY->getArriba());
                cabezaY->setArriba(nuevaPosY);
                cabezaY = nuevaPosY;
                raiz->setAbajo(cabezaY);
                sizeY++;
            }else if( nuevaPosY->getY() > colaY->getY() ){
                colaY->setAbajo(nuevaPosY);
                nuevaPosY->setArriba(colaY);
                colaY = nuevaPosY;
                sizeY++;
            }else{
                NodoOrtogonal* auxActual = cabezaY->getAbajo();
                
                while(auxActual != NULL){
                    if(nuevaPosY->getY() < auxActual->getY()){
                        nuevaPosY->setAbajo(auxActual);
                        nuevaPosY->setArriba(auxActual->getArriba());
                        auxActual->getArriba()->setAbajo(nuevaPosY);
                        auxActual->setArriba((nuevaPosY));
                        sizeY++;
                        break;
                    }
                    auxActual = auxActual->getAbajo();
                }
            }
        }
        
    }
}

void MatrizOrtogonal::imprimir() {
    //IMPRIMIR X
    NodoOrtogonal* aux_x = cabezaX;
    
    if(aux_x == NULL){
        cout << "X esta vacia" << endl;
    }else{
        while(aux_x != NULL){
            cout << aux_x->getX() << endl;
            cout << "--------------------" << endl;
            
            NodoOrtogonal* fils = aux_x->getAbajo();
            if(fils == NULL){
                cout << "----------> Vacio" << endl;
            }else{
                while(fils != NULL){
                    cout << " [ "<< fils->getValor() <<" ," <<fils->getX() << " , " << fils->getY() << " ] --------> ";
                    fils = fils->getAbajo();
                }
                cout << endl << endl << endl;
            }
            
            aux_x = aux_x->getDerecha();
        }
        cout << endl;
    }
    
    cout << endl << endl << "-------------------" << endl;
    //IMPRIMIR Y
    
    NodoOrtogonal* aux_y= cabezaY;
    
    if(aux_y == NULL){
        cout << "Y esta vacia" << endl;
    }else{
        while(aux_y != NULL){
            cout << aux_y->getY() << endl;
            
            NodoOrtogonal* cols = aux_y->getDerecha();
            if(cols == NULL){
                cout << "----------> Vacio" << endl;
            }else{
                while(cols != NULL){
                    cout << " [ "<< cols->getValor() <<" ," <<cols->getX() << " , " << cols->getY() << " ] --------> ";
                    cols = cols->getDerecha();
                }
                cout << endl << endl << endl;
            }
            
            aux_y = aux_y->getAbajo();
        }
    }
    
}

bool MatrizOrtogonal::existeX(int x) {
    NodoOrtogonal* aux = cabezaX;
    if(aux != NULL){
        while(aux != NULL){
            if(aux->getX() == x){
                return true;
            }
            aux = aux->getDerecha();
        }
    }
    return false;
}

bool MatrizOrtogonal::existeY(int y) {
    NodoOrtogonal* aux = cabezaY;
    if(aux != NULL){
        while(aux != NULL){
            if(aux->getY() == y){
                return true;
            }
            aux = aux->getAbajo();
        }
    }
    return false;
}

NodoOrtogonal *MatrizOrtogonal::getX(int x) {
    if(existeX(x)){
        NodoOrtogonal* aux = cabezaX;
        while(aux != NULL){
            if( aux->getX() == x ){
                return aux;
            }
            aux = aux->getDerecha();
        }
    }
    return NULL;
}

NodoOrtogonal *MatrizOrtogonal::getY(int y) {
    if(existeY(y)){
        NodoOrtogonal* aux = cabezaY;
        while(aux != NULL){
            if( aux->getY() == y ){
                return aux;
            }
            aux = aux->getAbajo();
        }
    }
    return NULL;
}

void MatrizOrtogonal::insertar(string valor, int x, int y) {
    
    //INSERTAR CABECERAS
    insertarCabeceraX(x);
    insertarCabeceraY(y);
    
    //OBTENER LAS POSICIONES DE CABECERA
    NodoOrtogonal* posX = getX(x);
    NodoOrtogonal* posY = getY(y);
    
    //CREO EL NODO A INSERTAR
    NodoOrtogonal* nuevoPunto = new NodoOrtogonal(valor, x, y);
    
    //INSERTO EL NODO NUEVO EN LA POSICION X
    if(posX->getAbajo() == NULL){
        posX->setAbajo(nuevoPunto);
    }else{
        NodoOrtogonal* actual = posX->getAbajo();
        NodoOrtogonal* anterior = posX;
        
        while(actual != NULL){
            if(nuevoPunto->getY() < actual->getY() ){
                nuevoPunto->setAbajo(actual);
                nuevoPunto->setArriba(anterior);
                anterior->setAbajo(nuevoPunto);
                actual->setArriba(nuevoPunto);
                break;
            }
            anterior = actual;
            actual = actual->getAbajo();
        }
        
        if(actual == NULL){
            nuevoPunto->setArriba(anterior);
            anterior->setAbajo(nuevoPunto);
        }
    }
    
    //INSERTO EL NODO NUEVO EN LA POSICION Y
    if( posY->getDerecha() == NULL ){
        posY->setDerecha(nuevoPunto);
    }else{
        NodoOrtogonal* actual = posY->getDerecha();
        NodoOrtogonal* anterior = posY;
        
        while(actual != NULL){
            if(nuevoPunto->getX() < actual->getX()){
                nuevoPunto->setDerecha(actual);
                nuevoPunto->setIzquierda(anterior);
                anterior->setDerecha(nuevoPunto);
                actual->setIzquierda(anterior);
                break;
            }
            anterior = actual;
            actual = actual->getDerecha();
        }
        
        if(actual == NULL){
            nuevoPunto->setIzquierda(anterior);
            anterior->setDerecha(nuevoPunto);
        }
    }
    
    
}

void MatrizOrtogonal::graficar(string nombre, int z) {
    string nombre_archivo = nombre;
    nombre_archivo += "_";
    nombre_archivo += to_string(z);
    
    ofstream archivo;
    archivo.open(nombre_archivo + ".txt");
    archivo << "digraph SparseMatrix{" << endl;
    archivo << "    node[shape=record,  width=1.4, height=0.8, fontsize=22, fontcolor=blue ];" << endl;
    archivo << "    graph[pencolor=transparent];" << endl;
    archivo << "    node[style=filled];" << endl;
    archivo << "    rankdir=LR;" << endl << endl;
    
    archivo << "    raiz[label=\"{Raiz}\" pos=\"0,0!\"];" << endl;
    
    //IMPRIMIENDO LAS CABECERAS DE X --------------------------------------
    NodoOrtogonal* cabeceraX = cabezaX;
    archivo << "    raiz -> x" << cabeceraX->getX() << "[dir=\"both\"]"<< endl;
    while(cabeceraX != NULL){
        archivo << "    ";
        archivo << "x"<< cabeceraX->getX() <<"[label=\"{  "<< cabeceraX->getX() <<" , 0}\"";
        archivo << "pos=\""<< (cabeceraX->getX() * 2) <<",0!\"];" << endl;
        
        if(cabeceraX->getDerecha() != NULL){
            archivo << "    ";
            archivo << "x" << cabeceraX->getX() << "->" << "x" << cabeceraX->getDerecha()->getX() << "[dir=\"both\"]"<<  endl;
        }
        
        cabeceraX = cabeceraX->getDerecha();
    }
    //FIN DE LAS CABECERAS DE X -----------------------------------------------
    
    archivo << endl << endl;
    
    //IMPRIMIENDO LAS CABECERAS DE Y -----------------------------------------
    NodoOrtogonal* cabeceraY = cabezaY;
    archivo << "    raiz -> y" << cabeceraY->getY() << "[dir=\"both\"];"<< endl;
    
    while(cabeceraY != NULL){
        archivo << "    ";
        archivo << "y"<< cabeceraY->getY() <<"[label=\"{ 0, " << cabeceraY->getY() <<"}\"";
        archivo << "pos=\" 0, "<< (cabeceraY->getY() * -2) <<"!\"];" << endl;
        
        
        if(cabeceraY->getAbajo() != NULL){
            archivo << "    ";
            archivo << "y" << cabeceraY->getY() << "->" << "y" << cabeceraY->getAbajo()->getY() << "[dir=\"both\"]"<<  endl;
        }
    
        cabeceraY = cabeceraY->getAbajo();
    }
    //FIN DE LAS CABECERAS DE Y
    
    archivo << endl << endl;
    
    //IMPRIMIENDO LOS VALORES DE CADA COLUMNA X
    NodoOrtogonal* x = cabezaX;
    while(x != NULL){
        
        NodoOrtogonal* rows = x->getAbajo();
        archivo << "    x" << x->getX() << "->nodo" << rows->getX() << "_" << rows->getY() << "[dir=both];" << endl;
        while(rows != NULL){
    
            archivo << "    ";
            archivo << "nodo"<< rows->getX() << "_" << rows->getY();
            archivo << "[ label = \" { "<< rows->getValor() << " } \" ";
            archivo << "pos =  \""<< (rows->getX() * 2) <<"," << (rows->getY() * -2) << "!\"]; " << endl;
            
            if(rows->getAbajo() != NULL){
                archivo << "    ";
                archivo << "nodo"<< rows->getX() << "_" << rows->getY() << "->";
                archivo << "nodo" << rows->getAbajo()->getX() << "_" << rows->getAbajo()->getY() << "[dir=both];" << endl;
            }
            
            rows = rows->getAbajo();
        }
        archivo << endl;
        x = x->getDerecha();
    }
    
    //FIN DE LOS VALORES DE X
    
    archivo << endl << endl;
    
    //IMPRIMIENDO LOS VALORES DE CADA COLUMNA X
    NodoOrtogonal* y = cabezaY;
    while(y != NULL){
        
        NodoOrtogonal* cols = y->getDerecha();
        archivo << "    y" << y->getY() << "->nodo" << cols->getX() << "_" << cols->getY() << "[dir=both];" << endl;
        while(cols != NULL){
            
            if(cols->getDerecha() != NULL){
                archivo << "    ";
                archivo << "nodo"<< cols->getX() << "_" << cols->getY() << "->";
                archivo << "nodo" << cols->getDerecha()->getX() << "_" << cols->getDerecha()->getY() << "[dir=both];" << endl;
            }
            
            cols = cols->getDerecha();
        }
        archivo << endl;
        y = y->getAbajo();
    }
    
    //FIN DE LOS VALORES DE X
    
    
    archivo << "}" << endl;
    archivo.close();
    
    
    string generar_grafico = "neato -Tpng ";
    generar_grafico += nombre_archivo + ".txt";
    generar_grafico += " -o ";
    generar_grafico += nombre_archivo + ".png";
    system((generar_grafico).c_str());
    
    string abrir_imagen = nombre_archivo + ".png";
    system((abrir_imagen).c_str());
    
    
    
}

NodoOrtogonal *MatrizOrtogonal::getNodo(int x, int y) {
    if(cabezaX != NULL && cabezaY != NULL){
        //OBTENGO LA CABECERA EN X
        NodoOrtogonal* posX = getX(x)->getAbajo();
        while(posX != NULL){
            if(posX->getY() == y){
                return posX;
            }
            posX = posX->getAbajo();
        }
    }
    return NULL;
}

NodoOrtogonal *MatrizOrtogonal::getCabezaX(){
    return cabezaX;
}

NodoOrtogonal *MatrizOrtogonal::getCabezaY(){
    return cabezaY;
}

//PRUEBA DE LOS FILTOS ------------------------

void MatrizOrtogonal::filtroNegativo() {
    if(cabezaX != NULL && cabezaY != NULL){
        NodoOrtogonal* auxY = cabezaY;
        
        while(auxY != NULL){
            NodoOrtogonal* x = auxY->getDerecha();
    
            while(x != NULL){
        
                if(x->getValor() != "x" && x->getValor() != ""){
                    size_t posComa = x->getValor().find("-");
                    int red = stoi(x->getValor().substr(0, posComa));
            
                    string auxG = x->getValor().substr(posComa + 1);
                    posComa = auxG.find("-");
                    int green = stoi(auxG.substr(0, posComa));
            
                    int blue = stoi(auxG.substr(posComa + 1));
                    
                    //CALCULAR EL NEGATIVO DE CADA COLOR
                    red = 255 - red;
                    green = 255 - green;
                    blue = 255 - blue;
                    
                    string negativo = to_string(red) + "-" +to_string(green) + "-" + to_string(blue);
                    
                    x->setValor(negativo, x->getX(), x->getY());
                }
                
                x = x->getDerecha();
            }
            
            auxY = auxY->getAbajo();
        }
        
    }
}

void MatrizOrtogonal::filtroEscalaGrises() {
    if(cabezaX != NULL && cabezaY != NULL){
        NodoOrtogonal* auxY = cabezaY;
        
        while(auxY != NULL){
            NodoOrtogonal* x = auxY->getDerecha();
            
            while(x != NULL){
                
                if(x->getValor() != "x" && x->getValor() != ""){
                    //cout << "->"<<x->getValor()<<"<-" << endl << endl;
                    size_t posComa = x->getValor().find("-");
                    int red = stoi(x->getValor().substr(0, posComa));
                    
                    
                    string auxG = x->getValor().substr(posComa + 1);
                    posComa = auxG.find("-");
                    int green = stoi(auxG.substr(0, posComa));
                    
                    
                    int blue = stoi(auxG.substr(posComa + 1));
                    
                    
                    //CALCULAR EL GRIS EQUIVALENTE
                    int gray = (0.3 * red) + (0.59 * green) + (0.11*blue);
                    
                    string gris = to_string(gray) + "-" +to_string(gray) + "-" + to_string(gray);
                    
                    x->setValor(gris, x->getX(), x->getY());
                }
                
                x = x->getDerecha();
            }
            
            auxY = auxY->getAbajo();
        }
        
    }
}


MatrizOrtogonal* MatrizOrtogonal::filtroEspejoX(int width){
    if(cabezaX != NULL && cabezaY != NULL){
        MatrizOrtogonal* espejo = new MatrizOrtogonal();
        NodoOrtogonal* auxY = cabezaY;
        
        while(auxY != NULL){
            NodoOrtogonal* xInicio = auxY->getDerecha();
            
            while (xInicio != NULL){
                espejo->insertar(xInicio->getValor(), (width + 1 - xInicio->getX()), xInicio->getY());
                xInicio = xInicio->getDerecha();
            }
            
            auxY = auxY->getAbajo();
        }
        return espejo;
    }
    return  NULL;
}

MatrizOrtogonal *MatrizOrtogonal::filtroEspejoY(int height) {
    if(cabezaX != NULL && cabezaY != NULL){
        MatrizOrtogonal* espejo = new MatrizOrtogonal();
        NodoOrtogonal* auxX = cabezaX;
        
        while(auxX != NULL){
            NodoOrtogonal* yInicio = auxX->getAbajo();
            
            while (yInicio != NULL){
                espejo->insertar(yInicio->getValor(), yInicio->getX(), (height + 1 - yInicio->getY()));
                yInicio = yInicio->getAbajo();
            }
            
            auxX = auxX->getDerecha();
        }
        return espejo;
    }
    return  NULL;
}

MatrizOrtogonal *MatrizOrtogonal::filtroCollage(int width, int height, int repX, int repY) {
    if(cabezaX != NULL && cabezaY != NULL){
    
        //IMPRIMIR LAS REPETICIONES EN X
        int contX = 0;
        MatrizOrtogonal* collage = new MatrizOrtogonal();
        
        while(contX < repX ){
            
            NodoOrtogonal* y = cabezaY;
            
            while(y != NULL){
                
                NodoOrtogonal* x = y->getDerecha();
                while ( x != NULL ){
                    collage->insertar(x->getValor(), ((x->getX()) + ( contX * width)), x->getY());
                    x = x->getDerecha();
                }
    
                y = y->getAbajo();
            }
            //cout << contX << endl;
            contX++;
        }
        
        //IMPRIMIR LAS REPETICIONES EN Y
        MatrizOrtogonal* collageCompleto = new MatrizOrtogonal();
        int contY = 0;
        while(contY < repY ){
        
            NodoOrtogonal* y = collage->getCabezaY();
        
            while(y != NULL){
            
                NodoOrtogonal* x = y->getDerecha();
                while ( x != NULL ){
                    collageCompleto->insertar(x->getValor(), x->getX(), ((x->getY()) + ( contY * (height))));
                    x = x->getDerecha();
                }
            
                y = y->getAbajo();
            }
        
            contY++;
        }
        
        
        return collageCompleto;
        
    }
    return  NULL;
}

MatrizOrtogonal *MatrizOrtogonal::filtroMosaico(int width, int height) {
    return filtroCollage(width, height, width, height);
}

MatrizOrtogonal *MatrizOrtogonal::getCopiaMatriz() {
    MatrizOrtogonal* matriz = new MatrizOrtogonal();
    if(   cabezaX != NULL && cabezaY != NULL){
        
        NodoOrtogonal* y = cabezaY;
        while(y != NULL){
            NodoOrtogonal* x = y->getDerecha();
            while(x != NULL){
                matriz->insertar(x->getValor(), x->getX(), x->getY());
                x = x->getDerecha();
            }
            y = y->getAbajo();
        }
        
        return matriz;
        
    }
    return matriz;
}

int MatrizOrtogonal::getSizeX() {
    return sizeX;
}

int MatrizOrtogonal::getSizeY() {
    return sizeY;
}

void MatrizOrtogonal::reporteLinealFilas() {
    string path = "./linealizarFilas.txt";
    
    //ARCHIVO DOT
    ofstream dot;
    dot.open(path);
    dot << "digraph filas{" << endl;
    dot << "    rankdir=LR;" << endl;
    dot << "    node [shape = record];" << endl;
    dot << "    graph [ranksep=\"1\"];" << endl << endl;
    
    if(cabezaY == NULL || cabezaX == NULL){
        dot << "        nodo[ label=\"vacio\" ]" << endl;
    }else{
        NodoOrtogonal* y = cabezaY;
        while(y != NULL){
            
            NodoOrtogonal* x = y->getDerecha();
            while(x != NULL){
                if(x->getDerecha() == NULL){
                    dot << "    nodo"<< x->getX() <<"_"<< x->getY() <<"[ label=\" "<< x->getValor() <<"\\n Pos[ "<< x->getX() <<"  , "<< x->getY() <<" ]   \" ];" << endl;
                    if(y->getAbajo() != NULL){
                        dot << "    nodo"<< y->getAbajo()->getDerecha()->getX() <<"_"<< y->getAbajo()->getDerecha()->getY() <<"[ label=\" "<< y->getAbajo()->getDerecha()->getValor() <<"\\n Pos[ "<< y->getX() <<"  , "<< y->getY() <<" ]   \" ];" << endl;
                        dot << "    nodo"<< x->getX() <<"_"<< x->getY() << "->nodo"<< y->getAbajo()->getDerecha()->getX() <<"_"<< y->getAbajo()->getDerecha()->getY() << endl << endl << endl;
                    }
                }else{
                    dot <<"    nodo"<< x->getX() <<"_"<< x->getY() <<"[ label=\" "<< x->getValor() <<"\\n Pos[ "<< x->getX() <<"  , "<< x->getY() <<" ]   \" ];" << endl;
                    dot << "    nodo"<< x->getDerecha()->getX() <<"_"<< x->getDerecha()->getY() <<"[label=\" "<< x->getDerecha()->getValor() <<"\\n Pos[ "<< x->getDerecha()->getX() <<"  , "<< x->getDerecha()->getY() <<" ]   \" ];" << endl;
                    dot << "    nodo"<< x->getX() <<"_"<< x->getY() << "->" << "nodo"<< x->getDerecha()->getX() <<"_"<< x->getDerecha()->getY() << ";" << endl;
                    
                }
                x = x->getDerecha();
            }
    
            
            if(y->getAbajo() != NULL){
                dot << "    { rank=same;  nodo"<<y->getDerecha()->getX() <<"_"<< y->getDerecha()->getY() <<"; nodo"<< y->getAbajo()->getDerecha()->getX() <<"_"<< y->getAbajo()->getDerecha()->getY() <<";}" << endl << endl;
            }
            
            
            
            y = y->getAbajo();
        }
    }
    
    dot << "}" << endl;
    dot.close();
    system("dot -Tpng linealizarFilas.txt -o filas.png");
    system("filas.png");
}

void MatrizOrtogonal::reporteLinealColumnas() {
    string path = "./linealizarCols.txt";
    
    //ARCHIVO DOT
    ofstream dot;
    dot.open(path);
    dot << "digraph filas{" << endl;
    dot << "    rankdir=TB;" << endl;
    dot << "    node [shape = record];" << endl;
    dot << "    graph [ranksep=\"1\"];" << endl << endl;
    
    if(cabezaY == NULL || cabezaX == NULL){
        dot << "        nodo[ label=\"vacio\" ]" << endl;
    }else{
        NodoOrtogonal* x = cabezaX;
        while(x != NULL){
            
            NodoOrtogonal* y = x->getAbajo();
            while(y != NULL){
                if(y->getAbajo() == NULL){
                    dot << "    nodo"<< y->getX() <<"_"<< y->getY() <<"[ label=\" "<< y->getValor() <<"\\n Pos[ "<< y->getX() <<"  , "<< y->getY() <<" ]   \" ];" << endl;
                    if(x->getDerecha() != NULL){
                        dot << "    nodo"<< x->getDerecha()->getAbajo()->getX() <<"_"<< x->getDerecha()->getAbajo()->getY() <<"[ label=\" "<< x->getDerecha()->getAbajo()->getValor() <<"\\n Pos[ "<< x->getX() <<"  , "<< x->getY() <<" ]   \" ];" << endl;
                        dot << "    nodo"<< y->getX() <<"_"<< y->getY() << "->nodo"<< x->getDerecha()->getAbajo()->getX() <<"_"<< x->getDerecha()->getAbajo()->getY() << endl << endl << endl;
                    }
                }else{
                    dot <<"    nodo"<< y->getX() <<"_"<< y->getY() <<"[ label=\" "<< y->getValor() <<"\\n Pos[ "<< y->getX() <<"  , "<< y->getY() <<" ]   \" ];" << endl;
                    dot << "    nodo"<< y->getAbajo()->getX() <<"_"<< y->getAbajo()->getY() <<"[label=\" "<< y->getAbajo()->getValor() <<"\\n Pos[ "<< y->getAbajo()->getX() <<"  , "<< y->getAbajo()->getY() <<" ]   \" ];" << endl;
                    dot << "    nodo"<< y->getX() <<"_"<< y->getY() << "->" << "nodo"<< y->getAbajo()->getX() <<"_"<< y->getAbajo()->getY() << ";" << endl;
        
                }
                y = y->getAbajo();
            }
            
            if(x->getDerecha() != NULL){
                dot << "    {rank=same; nodo"<< x->getAbajo()->getX() <<"_"<< x->getAbajo()->getY() << "; nodo" << x->getDerecha()->getAbajo()->getX() << "_" << x->getDerecha()->getAbajo()->getY() << "; }" << endl << endl;
            }
            
            
            x = x->getDerecha();
        }
    }
    
    dot << "}" << endl;
    dot.close();
    system("dot -Tpng linealizarCols.txt -o cols.png");
    system("cols.png");
}



