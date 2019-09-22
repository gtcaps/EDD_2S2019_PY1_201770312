//
// Created by aybso on 27/08/2019.
//

#ifndef MATRIZORTOGONAL_LISTADOBLELINEAL_H
#define MATRIZORTOGONAL_LISTADOBLELINEAL_H

#include <iostream>
#include <string>

using  namespace std;


class NodoLineal{
    
    private:
        string red, blue, green;
        string opacity_color;
        int pos;
        NodoLineal* siguiente, * anterior;
        
    public:
        NodoLineal(){
            red = "255";
            blue = "255";
            green = "255";
            opacity_color = "255,255,255,0.5";
            pos = 0;
            siguiente = NULL;
            anterior = NULL;
        }
        
        NodoLineal(int pos, string red, string blue, string green){
            this->red = red;
            this->green= green;
            this->blue = blue;
            this->pos = pos;
            opacity_color = "255,255,255,0.5";
            siguiente = NULL;
            anterior = NULL;
        }
        
        void setRed(string red){this->red = red;}
        void setBlue(string blue){this->blue = blue;}
        void setGreen(string green){this->green = green;}
        void setColors(string red, string green, string blue){
            this->red = red;
            this->blue = blue;
            this->green = green;
        };
        void setOpacityColor(string col){this->opacity_color = col;}
        void setPosicion(int pos){this->pos = pos;}
        void setSiguiente(NodoLineal* siguiente){this->siguiente = siguiente;}
        void setAnterior(NodoLineal* anterior){this->anterior = anterior;}
        
        string getRed(){return red;}
        string getBlue(){return blue;}
        string getGreen(){return green;}
        int getPosicion(){return pos;}
        NodoLineal* getSiguiente(){return siguiente;}
        NodoLineal* getAnterior(){return anterior;}
        string getColor(){
            string color = red + "," + green + "," + blue ;
            return  color;
        }
        string getOpacityColor(){
            return this->opacity_color;
        };
    
};


class ListaDobleLineal{
    
    private:
        NodoLineal* cabeza, *cola;
        int size;
        
    public:
        ListaDobleLineal(){
            cabeza = NULL;
            cola = NULL;
            size = 0;
        }
        
        void add(int length , string red, string green, string blue){
            if(cabeza == NULL){
                length++;
                cabeza = cola = new NodoLineal(length, red, blue, green);
                size++;
            }else{
                length++;
                NodoLineal* nuevoNodo = new NodoLineal(length, red, blue, green);
                nuevoNodo->setAnterior(cola);
                cola->setSiguiente(nuevoNodo);
                cola = nuevoNodo;
                size++;
            }
        }
        
        void add(int length , string red, string green, string blue, string opacity){
            if(cabeza == NULL){
                length++;
                cabeza = cola = new NodoLineal(length, red, blue, green);
                cabeza->setOpacityColor(opacity);
                size++;
            }else{
                length++;
                NodoLineal* nuevoNodo = new NodoLineal(length, red, blue, green);
                nuevoNodo->setOpacityColor(opacity);
                nuevoNodo->setAnterior(cola);
                cola->setSiguiente(nuevoNodo);
                cola = nuevoNodo;
                size++;
            }
        }
        
        void print() {
            if(cabeza == NULL) {
                cout << "La lista esta vacia" << endl;
            } else {
                NodoLineal *aux = cabeza;
                while (aux != NULL) {
                    cout << "[ " << aux->getColor() << " ] POS( " << aux->getPosicion() << " ) ------> " << endl;
                    aux = aux->getSiguiente();
                }
            }
    
        }
        
        NodoLineal* getCabeza(){return cabeza;}
        
        int getSize(){return size;}
        
};



#endif //MATRIZORTOGONAL_LISTADOBLELINEAL_H
