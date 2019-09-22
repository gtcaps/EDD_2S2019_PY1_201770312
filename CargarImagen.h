//
// Created by aybso on 1/09/2019.
//

#ifndef MATRIZORTOGONAL_CARGARIMAGEN_H
#define MATRIZORTOGONAL_CARGARIMAGEN_H

#include <fstream>
#include "CuboOrtogonal.h"
#include <string>


void cargarCapa(int capa, string nombreCarpeta, string nombreArchivo, CuboOrtogonal* cubo){
    ifstream archivo;
    
    string path = "../csv/";
    string path_archivo = path + nombreCarpeta + "/" + nombreArchivo + ".csv";
    
    archivo.open(path_archivo, ios::in);
    
    if(archivo.fail()){
        cout << "Error al tratar de abrir el archivo, verifique si existe" << endl;
    }else{
        
        char caracter;
        string linea = "";
        int x = 0, y = 1;
        
        while(!archivo.eof()){
            archivo.get(caracter);
            
            if(caracter == '\n'){
                if(linea == ""){
                    continue;
                }
                
                x++;
                if(linea != "x"){
                    cubo->agregar(linea, x, y, capa);
                }
                
                linea = "";
                y++;
                x = 0;
            }else{
                if(caracter == ','){
                    x++;
                    if(linea != "x"){
                        cubo->agregar(linea, x, y, capa);
                    }
                    linea = "";
                }else{
                    linea += tolower(caracter);
                }
            }
        }
    }
    
    archivo.close();
    
}

void cargarConfiguracion(int capa, string nombreCarpeta, string nombreArchivo, CuboOrtogonal* cubo){
    ifstream archivo;
    
    string path = "../csv/";
    string path_archivo = path + nombreCarpeta + "/" + nombreArchivo + ".csv";
    archivo.open(path_archivo, ios::in);
    
    if(archivo.fail()){
        cout << "Error al tratar de abrir el archivo, verifique si existe" << endl;
    }else{
        
        int cont = 0;
        string linea = "";
        int width, height, pixel_width, pixel_height;
        
        while(!archivo.eof()){
            getline(archivo, linea);
            
            if(cont == 0 || linea == "" || linea == " "){
                cont++;
                continue;
            }
            
            size_t posComa = linea.find(",");
            string nombreDimension = linea.substr(0, posComa);
            string valorDimension = linea.substr(posComa + 1);
            
            if(nombreDimension == "image_width"){
                width = stoi(valorDimension);
            }else if(nombreDimension == "image_height"){
                height = stoi(valorDimension);
            }else if(nombreDimension == "pixel_width"){
                pixel_width = stoi(valorDimension);
            }else if(nombreDimension == "pixel_height"){
                pixel_height = stoi(valorDimension);
            }
        }
        cubo->setDimensiones(width, height, pixel_height, pixel_width);
        
        for(int y = 1; y <= height; y++){
            for(int x = 1; x <= width; x++ ){
                cubo->agregar("x", x, y, 0);
            }
        }
    }
    
    archivo.close();
    
}


class CargarImagen{
    
    private:
        ifstream archivo;
        string path = "../csv/";
        string nombreCarpeta = "";
        string nombreArchivo = "";
        string path_archivo = "";
        CuboOrtogonal* cubo;
        
    public:
        CargarImagen(string nombreCarpeta_, string nombreArchivo_){
            nombreCarpeta = nombreCarpeta_;
            nombreArchivo = nombreArchivo_;
            path_archivo = path + nombreCarpeta_ + "/" + nombreArchivo_ + ".csv";
            
            archivo.open(path_archivo, ios::in);
            
            
            if(archivo.fail()){
                cout << endl << "Error al tratar de abrir " << nombreArchivo_ << ".csv" << endl << endl;
                cubo = new CuboOrtogonal("vacio");
            }else{
                cout << endl << "Cargando: csv/" << nombreCarpeta_ << "/" << nombreArchivo_ <<".csv  ... " << endl;
                try{
    
                    string linea = "";
                    bool ignoreFirst = false;
                    cubo =  new CuboOrtogonal(nombreArchivo_);
                    
                    while(!archivo.eof()){
        
                        //SE OBTIENE UNA LINEA DEL ARCHIVO Y SE GUARDA EN LA VARIABLE STRING linea
                        getline(archivo, linea);
        
                        //IGNORAR LA PRIMERA LINEA QUE TIENE LOS ENCABEZADOS, Y SI UNA LINEA ESTA VACIA
                        if(!ignoreFirst || linea == ""){
                            ignoreFirst = true;
                            continue;
                        }
                        
                        //OBTENGO LA POSICION DE LA COMA Y DEL PUNTO DE LA EXTENSION
                        size_t posComa = linea.find(",");
                        size_t posExt = linea.find(".");
                        
                        //OBTENGO LA POSICION DE LA CAPA
                        cout << "------" << linea.substr(0, posComa) << endl;
                        int capaZ = stoi(linea.substr(0, posComa));
                        
                        //OBTENGO EL NOMBRE DEL ARCHIVO QUE SE VA A CARGAR
                        string archivoCarga = linea.substr(posComa + 1, posExt - 2);
                        
                        //SE CARGA EL ARCHIVO DE CONFIGURACION EN LA CAPA 0
                        if(capaZ == 0){
                            cargarConfiguracion(capaZ, nombreCarpeta_, archivoCarga, cubo);
                            continue;
                        }
                        
                        //SE  CARGAN LAS CAPAS AL CUBO
                        cargarCapa(capaZ, nombreCarpeta_, archivoCarga, cubo);
        
                    }
                    
                    cout << endl << "Carga Completa: csv/" << nombreCarpeta_ << "/" << nombreArchivo_ <<".csv  ... " << endl << endl;
                    
                }catch(...){
                    cout << endl << "El archivo de entrada tiene un error, reviselo y vuelvalo a abrir" << endl;
                }
                
               archivo.close();
               
            }
        }
        
        
        CuboOrtogonal* getImagen(){
            return cubo;
        }
        
        
        
};






#endif //MATRIZORTOGONAL_CARGARIMAGEN_H
