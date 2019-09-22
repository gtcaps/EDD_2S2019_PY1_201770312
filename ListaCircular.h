//
// Created by aybso on 14/09/2019.
//

#ifndef MATRIZORTOGONAL_LISTACIRCULAR_H
#define MATRIZORTOGONAL_LISTACIRCULAR_H

#include <cstring>
#include "CuboOrtogonal.h"
using namespace std;

class NodoCircular{
    
    private:
        string filtro;
        CuboOrtogonal* imagen;
        NodoCircular* siguiente, * anterior;
    
    public:
        NodoCircular(string filtro, CuboOrtogonal* imagen){
            this->filtro = filtro;
            this->imagen = imagen;
            siguiente = NULL;
            anterior = NULL;
        }
        
        void setImagen(CuboOrtogonal* imagen){
            this->imagen = imagen;
        }
        
        void setFiltro(string id){
            this->filtro = id;
        }
        
        void setSiguiente(NodoCircular* siguiente){
            this->siguiente = siguiente;
        }
        
        void setAnterior(NodoCircular* anterior){
            this->anterior = anterior;
        }
        
        string getFiltro(){
            return this->filtro;
        }
        
        CuboOrtogonal* getCImagen(){
            return this->imagen;
        }
        
        NodoCircular* getSiguiente(){
            return this->siguiente;
        }
        
        NodoCircular* getAnterior(){
            return this->anterior;
        }
};

class ListaCircular{
    
    private:
        NodoCircular* cabeza;
        int length;
        
    public:
        ListaCircular(){
            this->cabeza = NULL;
            this->length = 0;
        }
        
        CuboOrtogonal* getCopiaImagenOriginal(){
            return cabeza->getCImagen()->getCopiaCubo();
        }
        
        int getLength(){
            return length;
        }
        
        void agregar(CuboOrtogonal* imagen){
            if(cabeza == NULL){
                length++;
                cabeza = new NodoCircular("original",imagen);
                cabeza->setSiguiente(cabeza);
                cabeza->setAnterior(cabeza);
            }else{
                length++;
                NodoCircular* ultimo = cabeza->getAnterior();
                NodoCircular* nuevo = new NodoCircular("original", imagen);
                nuevo->setAnterior(ultimo);
                ultimo->setSiguiente(nuevo);
                nuevo->setSiguiente(cabeza);
                cabeza->setAnterior(nuevo);
            }
        }
        
        void agregar(string filtro, CuboOrtogonal* imagen){
            if(cabeza == NULL){
                agregar(imagen);
            }else{
                
                if(filtro == "negativo"){
                    imagen->filtroNegativo();
                }else if(filtro == "grises"){
                    imagen->filtroEscalaGrises();
                }else if(filtro == "espejox"){
                    imagen->filtroEspejoX();
                }else if(filtro == "espejoy"){
                    imagen->filtroEspejoY();
                }else if(filtro == "collage"){
                    int x = 0, y = 0;
                    do{
                        cout << endl << "Repeticiones en x: ";
                        cin >> x;
                    }while(x == 0 || x > 16);
    
                    do{
                        cout << endl << "Repeticiones en y: ";
                        cin >> y;
                    }while(y == 0 || y > 16);
                    
                    imagen->filtroCollage(x, y);
                }else if(filtro == "mosaico"){
                    imagen->filtroMosaico();
                }else if(filtro == "doble"){
                    imagen->filtroDobleEspejo();
                }else{
                    string nombre = imagen->getNombre() + "_" + filtro;
                    imagen->setNombre(nombre);
                }
                
                
                length++;
                NodoCircular* ultimo = cabeza->getAnterior();
                NodoCircular* nuevo = new NodoCircular(filtro, imagen);
                nuevo->setAnterior(ultimo);
                ultimo->setSiguiente(nuevo);
                nuevo->setSiguiente(cabeza);
                cabeza->setAnterior(nuevo);
            }
        }
        
        void imprimir(){
            if(cabeza != NULL){
                int cont = length;
                NodoCircular* aux = cabeza;
                while(cont > 0){
                    cout << aux->getCImagen()->getNombre() << endl;
                    cont--;
                    aux = aux->getSiguiente();
                }
            }else{
                cout << endl << "La lista de filtros esta vacia" << endl;
            }
        }
        
        void vaciarLista(){
            cabeza = NULL;
            length = 0;
        }
        
        void graficar(){
    
            string path = "./graficaFiltros.txt";
    
            //ARCHIVO DOT
            ofstream dot;
            dot.open(path);
            dot << "digraph filas{" << endl;
            dot << "    rankdir=TB;" << endl;
            dot << "    node [shape = record];" << endl;
            dot << "    graph [ranksep=\"1\"];" << endl << endl;
            
            
            dot << "    label=\"Lista Circular de Filtros\";" << endl;
            
            NodoCircular* aux = cabeza;
            int cont = 1;
            while(cont <= this->length){
                dot << "    nodo"<<cont <<"[label=\""<< aux->getCImagen()->getNombre() <<"\"];" << endl;
                cont++;
                aux = aux->getSiguiente();
            }
    
            dot << endl << endl;
            
            cont = 1;
            while (cont <= this->length){
                if(cont == length){
                    dot << "    nodo"<<cont << "->nodo"<< 1 << endl;
                    dot << "    nodo"<< 1 << "->nodo"<< cont << endl;
                }else{
                    dot << "    nodo"<<cont << "->nodo"<< (cont + 1) << endl;
                    dot << "    nodo"<<(cont + 1) << "->nodo"<< cont << endl;
                }
                cont++;
            }
            
            if(this->length == 0){
                dot << "    nodo"<<cont <<"[label=\""<< "Lista Vacia" <<"\"];" << endl;
            }
            
    
            dot << "}" << endl;
            dot.close();
            system("circo -Tpng graficaFiltros.txt -o graficaFiltros.png");
            system("graficaFiltros.png");
        
        }
        
        NodoCircular* getCabeza(){
            return cabeza;
        }
        
        
        void generarImagen(int id){
            if(length != 0){
                
                NodoCircular* aux = cabeza;
                
                for(int i = 1; i <= length; i++ ){
                    if(i == id){
                        break;
                    }
                    aux = aux->getSiguiente();
                }
                
                if(id > length){
                    cout << endl << "No encontramos ese id" << endl << endl;
                }else{
                    string filtroAplicado = aux->getFiltro();
                    
                    
                    string filtroMos = "mosaico";
                    string filtroColl = "collage";
                    
                    cout << endl << "Exportando imagen " << aux->getFiltro() << endl;
                    
                    if(strstr(filtroAplicado.c_str(),filtroMos.c_str())){
                        CuboOrtogonal* c = getCopiaImagenOriginal();
                        c->generateMatrix();
                        MatrizOrtogonal* m = c->getCabeza()->getMatriz();
                        aux->getCImagen()->generarMosaico(m);
                    }else if(strstr(filtroAplicado.c_str(),filtroColl.c_str())){
                        aux->getCImagen()->generarCollage();
                    }else{
                        aux->getCImagen()->generarImagen();
                    }
    
                    cout << endl << "Imagen Exportada:  " << aux->getFiltro() << endl << endl;
                    
                }
                
            }
        }
        
        
};


#endif //MATRIZORTOGONAL_LISTACIRCULAR_H
