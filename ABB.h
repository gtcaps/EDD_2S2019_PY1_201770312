//
// Created by aybso on 1/09/2019.
//

#ifndef MATRIZORTOGONAL_ABB_H
#define MATRIZORTOGONAL_ABB_H

#include <iostream>
#include <string>
#include <fstream>
#include <direct.h>
#include "CargarImagen.h"
#include "CuboOrtogonal.h"
using  namespace std;


class NodoABB{
    
    private:
        string valor;
        CuboOrtogonal* imagen;
        NodoABB* izquierda;
        NodoABB* derecha;
    
    public:
        NodoABB(){
            valor = "";
            imagen = NULL;
            izquierda = NULL;
            derecha = NULL;
        }
        
        NodoABB(string valor_, CuboOrtogonal* img){
            valor = valor_;
            imagen = img;
            izquierda = NULL;
            derecha = NULL;
        }
        
        void setValor(string valor_){valor = valor_;}
        void setIzquierda(NodoABB* izquierda_){izquierda = izquierda_;}
        void setDerecha(NodoABB* derecha_){derecha = derecha_;}
        void setImagen(CuboOrtogonal* img){imagen = img;}
        
        string getValor(){return valor;}
        NodoABB* getIzquierda(){ return  izquierda;}
        NodoABB* getDerecha(){ return derecha; }
        CuboOrtogonal* getImagen(){return imagen;}
        
};


class NodoCola{
    public:
        NodoABB* valor;
        NodoCola* siguiente;
        
        NodoCola(NodoABB* val){
            valor = val;
            siguiente = NULL;
        }
};

class Cola{
    public:
        NodoCola* cabeza;
        NodoCola* cola;
        int size;
        
        Cola(){
            size = 0;
            cabeza = NULL;
        }
        
        Cola(NodoABB* val){
            size = 0;
            cabeza = new NodoCola(val);
        }
        
        void push(NodoABB* val){
            if(cabeza == NULL){
                cabeza = cola = new NodoCola(val);
                size++;
            }else{
                NodoCola* nuevoNodo = new NodoCola(val);
                cola->siguiente = nuevoNodo;
                cola = nuevoNodo;
                size++;
            }
        }
        
        NodoABB* pop(){
            if(cabeza != NULL){
                size--;
                NodoCola* n = cabeza;
                cabeza = cabeza->siguiente;
                return n->valor;
            }
            return NULL;
        }
};

class ABB{
    
    private:
        NodoABB* raiz;
        int cantidadNodos;
        
        bool existeHijoDerecho(NodoABB* nodo){
            if(nodo->getDerecha() != NULL){
                return true;
            }
            return false;
        }
        
        bool existeHijoIzquierdo(NodoABB* nodo){
            if(nodo->getIzquierda() != NULL){
                return true;
            }
            return false;
        }
        
        bool esNulo(NodoABB* nodo){
            if(nodo == NULL){
                return true;
            }
            return false;
        }
        
        NodoABB* obtenerPadre(string valor){
            
            if(existeHijoIzquierdo(raiz) == false && existeHijoDerecho(raiz) == false){
                return raiz;
            }else{
                NodoABB* padre = NULL;
                NodoABB* aux = raiz;
                while(aux != NULL){
                    if( aux->getValor().compare(valor) == -1){
                        padre = aux;
                        aux = aux->getDerecha();
                    }else if(aux->getValor().compare(valor) == 1){
                        padre = aux;
                        aux = aux->getIzquierda();
                    }else if(aux->getValor().compare(valor) == 0){
                        return NULL;
                    }
                }
                return padre;
            }
            
        }
        
        string enOrden(NodoABB* nodo, string* r, int n){
            if(nodo != NULL){
                enOrden(nodo->getIzquierda(), r, n);
                
                for(int i = 0; i < n; i++){
                    if(r[i] == ""){
                        r[i] = nodo->getValor();
                        break;
                    }
                }
                
                enOrden(nodo->getDerecha(), r, n);
            }
        }
        
        void preOrden(NodoABB* nodo, string* r, int n){
            if(nodo != NULL){
                
                for(int i = 0; i < n; i++){
                    if(r[i] == ""){
                        r[i] = nodo->getValor();
                        break;
                    }
                }
                
                preOrden(nodo->getIzquierda(), r, n);
                preOrden(nodo->getDerecha(), r, n);
            }
        }
        
        void postOrden(NodoABB* nodo, string* r, int n){
            if(nodo != NULL){
                postOrden(nodo->getIzquierda(), r, n);
                postOrden(nodo->getDerecha(), r, n);
                
                for(int i = 0; i < n; i++){
                    if(r[i] == ""){
                        r[i] = nodo->getValor();
                        break;
                    }
                }
            }
        }
    
    
    public:
        ABB(){
            raiz = NULL;
            cantidadNodos = 0;
        }
        
        void add(CargarImagen* img){
            
            if(img->getImagen()->getNombre() != "vacio"){
                if(esNulo(raiz) == true){
                    raiz = new NodoABB(img->getImagen()->getNombre(), img->getImagen());
                    cantidadNodos++;
                }else{
        
                    NodoABB* padre = obtenerPadre(img->getImagen()->getNombre());
                    if(padre->getValor().compare(img->getImagen()->getNombre()) == -1){
                        padre->setDerecha(new NodoABB(img->getImagen()->getNombre(), img->getImagen()));
                        cantidadNodos++;
                    }else if(padre->getValor().compare(img->getImagen()->getNombre()) == 1){
                        padre->setIzquierda(new NodoABB(img->getImagen()->getNombre(), img->getImagen()));
                        cantidadNodos++;
                    }else{
                        cout << endl << "No se aceptan valores repetidos" << endl;
                    }
        
                }
            }
            
        }
        
        void graficarEnOrden(){
            //CREO UNA CARPETA PARA GUARDAR LOS ARCHIVOS
            _mkdir("ABB");
            
            string path = "./ABB/orden.txt";
            
            //ARCHIVO DOT
            ofstream dot;
            dot.open(path);
            dot << "digraph InOrden{" << endl;
            dot << "    rankdir=LR;" << endl;
            dot << "    subgraph cluster_0{" << endl;
            dot << "        style = filled;" << endl;
            dot << "        color = lightgrey;" << endl;
            dot << "        node[style=filled, color=white] " << endl;
            dot << "        ";
            
            NodoABB* aux = raiz;
            if(raiz == NULL){
                dot << "        nodo[ label=\"<i>|vacio|<d>\" ]" << endl;
            }else{
                string* r = new string[cantidadNodos];
                for(int i = 0; i < cantidadNodos; i++ ){
                    r[i] = "";
                }
                
                enOrden(aux, r, cantidadNodos);
                
                for(int i = 0; i < cantidadNodos; i++ ){
                    if(i == cantidadNodos - 1){
                        dot << r[i] << endl;
                    }else{
                        dot << r[i] << " -> ";
                    }
                }
            }
            
            
            dot << "        label= \"Listado de imagenes En Orden\"" << endl;
            dot << "    }" << endl;
            dot << "}" << endl;
            dot.close();
            
            system("dot -Tpng ./ABB/orden.txt -o orden.png");
            system("orden.png");
            
        }
        
        void graficarPreOrden(){
            //CREO UNA CARPETA PARA GUARDAR LOS ARCHIVOS
            _mkdir("ABB");
            
            string path = "./ABB/preOrden.txt";
            
            //ARCHIVO DOT
            ofstream dot;
            dot.open(path);
            dot << "digraph InOrden{" << endl;
            dot << "    rankdir=LR;" << endl;
            dot << "    subgraph cluster_0{" << endl;
            dot << "        style = filled;" << endl;
            dot << "        color = lightgrey;" << endl;
            dot << "        node[style=filled, color=white] " << endl;
            dot << "        ";
            
            NodoABB* aux = raiz;
            if(raiz == NULL){
                dot << "        nodo[ label=\"<i>|vacio|<d>\" ]" << endl;
            }else{
                string* r = new string[cantidadNodos];
                for(int i = 0; i < cantidadNodos; i++ ){
                    r[i] = "";
                }
                
                preOrden(aux, r, cantidadNodos);
                
                for(int i = 0; i < cantidadNodos; i++ ){
                    if(i == cantidadNodos - 1){
                        dot << r[i] << endl;
                    }else{
                        dot << r[i] << " -> ";
                    }
                }
            }
            
            
            dot << "        label= \"Listado de imagenes En Pre-Orden\"" << endl;
            dot << "    }" << endl;
            dot << "}" << endl;
            dot.close();
            
            system("dot -Tpng ./ABB/preOrden.txt -o preOrden.png");
            system("preOrden.png");
            
        }
        
        void graficarPostOrden(){
            //CREO UNA CARPETA PARA GUARDAR LOS ARCHIVOS
            _mkdir("ABB");
            
            string path = "./ABB/postOrden.txt";
            
            //ARCHIVO DOT
            ofstream dot;
            dot.open(path);
            dot << "digraph InOrden{" << endl;
            dot << "    rankdir=LR;" << endl;
            dot << "    subgraph cluster_0{" << endl;
            dot << "        style = filled;" << endl;
            dot << "        color = lightgrey;" << endl;
            dot << "        node[style=filled, color=white] " << endl;
            dot << "        ";
            
            NodoABB* aux = raiz;
            if(raiz == NULL){
                dot << "        nodo[ label=\"<i>|vacio|<d>\" ]" << endl;
            }else{
                string* r = new string[cantidadNodos];
                for(int i = 0; i < cantidadNodos; i++ ){
                    r[i] = "";
                }
                
                postOrden(aux, r, cantidadNodos);
                
                for(int i = 0; i < cantidadNodos; i++ ){
                    if(i == cantidadNodos - 1){
                        dot << r[i] << endl;
                    }else{
                        dot << r[i] << " -> ";
                    }
                }
            }
            dot << "        label= \"Listado de imagenes En Post-Orden\"" << endl;
            dot << "    }" << endl;
            dot << "}" << endl;
            dot.close();
            
            system("dot -Tpng ./ABB/postOrden.txt -o postOrden.png");
            system("postOrden.png");
        }
        
        void graficarABB(){
            //CREO UNA CARPETA PARA GUARDAR LOS ARCHIVOS
            _mkdir("ABB");
            
            string path = "./ABB/abb.txt";
            
            //ARCHIVO DOT
            ofstream dot;
            dot.open(path);
            dot << "digraph abb{" << endl;
            dot << "    rankdir=TB;" << endl;
            dot << "    node [shape = record];" << endl;
            dot << "    graph [ranksep=\"1\"];" << endl << endl;
            
            Cola* aux = new Cola();
            
            NodoABB* a = raiz;
            if(raiz == NULL){
                dot << "        nodo[ label=\"<i>|vacio|<d>\" ]" << endl;
            }else{
                aux->push(a);
                
                while(aux->size != 0){
                    NodoABB* nodo = aux->pop();
                    dot << "    nodo_" << nodo->getValor() << "[ label=\"<i>|"<< nodo->getValor()  << "\\n";
                    dot << "------------------------------- \\n";
                    dot << "Width: " << nodo->getImagen()->getWidth() << "px - Height: " << nodo->getImagen()->getHeight() <<"\\n\\n";
                    dot << "Pixel-W: " << nodo->getImagen()->getPixelWidth() << "px - Pixel-H: " << nodo->getImagen()->getPixelHeight();
                    dot << "px |<d>\" ]" << endl;
                    
                    if(nodo == NULL){
                        continue;
                    }else{
                        if(existeHijoIzquierdo(nodo)){
                            dot << "    nodo_" << nodo->getIzquierda()->getValor() << "[ label=\"<i>|"<< nodo->getIzquierda()->getValor()  <<"\\n";
                            dot << "------------------------------- \\n";
                            dot << "Width: " << nodo->getImagen()->getWidth() << "px - Height: " << nodo->getImagen()->getHeight() <<"\\n\\n";
                            dot << "Pixel-W: " << nodo->getImagen()->getPixelWidth() << "px - Pixel-H: " << nodo->getImagen()->getPixelHeight();
                            dot << "px |<d>\" ]" << endl;
                            dot << "    nodo_" << nodo->getValor() << ":i-> nodo_" << nodo->getIzquierda()->getValor()  << endl;
                            aux->push(nodo->getIzquierda());
                        }
                        
                        if(existeHijoDerecho(nodo)){
                            dot << "    nodo_" << nodo->getDerecha()->getValor() << "[ label=\"<i>|"<< nodo->getDerecha()->getValor()  <<"\\n";
                            dot << "------------------------------- \\n";
                            dot << "Width: " << nodo->getImagen()->getWidth() << "px - Height: " << nodo->getImagen()->getHeight() <<"\\n\\n";
                            dot << "Pixel-W: " << nodo->getImagen()->getPixelWidth() << "px - Pixel-H: " << nodo->getImagen()->getPixelHeight();
                            dot << "px |<d>\" ]" << endl;
                            dot << "    nodo_" << nodo->getValor() << ":d-> nodo_" << nodo->getDerecha()->getValor()  << endl;
                            aux->push(nodo->getDerecha());
                        }
                        
                    }
                    dot << endl << endl;
                }
            }
            
            dot << "}" << endl;
            dot.close();
            system("dot -Tpng ./ABB/abb.txt -o abb.png");
            system("abb.png");
        }
        
        int size(){
            return cantidadNodos;
        }
        
        string* getOpcionesEnOrden(){
            NodoABB* aux = raiz;
            
            string* r = new string[cantidadNodos];
            for(int i = 0; i < cantidadNodos; i++ ){
                r[i] = "";
            }
            
            enOrden(aux, r, cantidadNodos);
            
            for(int i = 0; i < cantidadNodos; i++){
                cout << to_string(i + 1) << ". " << r[i] << endl;
            }
            
            return  r;
            
        }
        
        
        CuboOrtogonal* getCubo(string nombre){
            
            if(raiz != NULL){
                
                NodoABB* aux = raiz;
                
                while(aux != NULL){
                    
                    if(nombre.compare(aux->getValor()) == -1){
                        aux = aux->getIzquierda();
                    }else if(nombre.compare(aux->getValor()) == 1){
                        aux = aux->getDerecha();
                    }else{
                        return aux->getImagen();
                    }
                
                }
                
            }
            
            cout << "No existe esa imagen" << endl;
            return NULL;
            
        }
        
        
    
    
    
};



#endif //MATRIZORTOGONAL_ABB_H
