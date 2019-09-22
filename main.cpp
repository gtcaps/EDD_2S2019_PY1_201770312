#include <iostream>
#include "MatrizOrtogonal.h"
#include "CuboOrtogonal.h"
#include <fstream>
#include "CargarImagen.h"
#include "ABB.h"
#include <math.h>
#include "ListaCircular.h"

using namespace std;

ListaCircular* listaFiltros = new ListaCircular();
ABB* listaImagenes = new ABB();

void menuPrincipial();
void cargarImagen();
void seleccionarImagen();
void aplicarFiltro();
void edicionManual();
void exportarImagen();
void reportes();
void limpiarBuffer();

int main() {
    
    menuPrincipial();
    
    /*CargarImagen* i = new CargarImagen("realmadrid", "realmadrid");
    CuboOrtogonal* c = i->getImagen();
    
    ListaCircular* l = new ListaCircular();
    l->agregar(c);
    l->agregar("negativo",c->getCopiaCubo());
    l->agregar("grises",c->getCopiaCubo());
    l->agregar("espejox",c->getCopiaCubo());
    l->agregar("espejoy",c->getCopiaCubo());
    l->graficar();*/
    
    //CargarImagen* img = new CargarImagen("ave", "ave");
    //CuboOrtogonal* kubo = img->getImagen();
    //kubo->reporteCapas();
    //kubo->generarImagen();
    //kubo->filtroNegativo();
    //kubo->filtroEscalaGrises();
    //kubo->filtroMosaico();
    
    /*
    cout << "--->" << cubo << endl;
    CuboOrtogonal* cubo2 = cubo->getCopiaCubo();
    cout << " ---> " <<  cubo2 << endl;
    cubo2->generarImagen();
    */
    
    //cubo->generarImagen();
    //cubo->filtroNegativo();
    //cubo->filtroEscalaGrises();
    //cubo->filtroEspejoY();
    //cubo->filtroEspejoX();
    //cubo->filtroDobleEspejo();
    //cubo->reporteCapas();
    //cubo->filtroCollage(3,3);
    //cubo->filtroMosaico();
    
    
    //CargarImagen* img3 = new CargarImagen("mario","mario");
    //CuboOrtogonal* mario = img3->getImagen();
    //mario->filtroNegativo();
    //mario->generarImagen();
    //mario->filtroEscalaGrises();
    //mario->filtroEspejoX();c
    //mario->filtroEspejoY();
    //mario->filtroDobleEspejo();
    //mario->reporteCapas();
    //mario->filtroCollage(3, 3);
    //mario->filtroMosaico();
    //mario->filtroEscalaGrises();
    //mario->filtroMosaico();
    
    
    
    /*ABB* arbolImagenes = new ABB();
    arbolImagenes->add(new CargarImagen("realmadrid", "realmadrid"));
    arbolImagenes->add(new CargarImagen("ghost", "ghost"));
    arbolImagenes->add(new CargarImagen("deadpool", "deadpool"));
    arbolImagenes->add(new CargarImagen("flappy", "flappy"));
    arbolImagenes->add(new CargarImagen("mushroom", "mushroom"));
    arbolImagenes->add(new CargarImagen("toad", "toad"));
    arbolImagenes->add(new CargarImagen("hulk", "hulk"));
    arbolImagenes->add(new CargarImagen("ironman", "ironman"));
    arbolImagenes->add(new CargarImagen("spiderman", "spiderman"));
    arbolImagenes->add(new CargarImagen("ave", "ave"));
    //arbolImagenes->graficarABB();
    
    CuboOrtogonal* i = arbolImagenes->getCubo("ghost");
    i->imprimir("ls");*/
    
    //arbolImagenes->graficarEnOrden();
    //arbolImagenes->graficarPreOrden();
    //arbolImagenes->graficarPostOrden();
    //arbolImagenes->getOpcionesEnOrden();
    
    /*
    ABB* arbolImagenes = new ABB();
    arbolImagenes->add(new CargarImagen("mario", "mario"));
    CuboOrtogonal* c =  arbolImagenes->getCubo("mario");
    cout << "---->" << c->getNombre() << endl;
    
    
    ListaCircular* l = new ListaCircular();
    l->agregar(c);
    l->agregar("negativo", c->getCopiaCubo());
    l->imprimir();
    */
    
    return 0;
}

void menuPrincipial(){
    int opcPrincipal = 0;
    
    do{
        cout << "----------------------------------------" << endl;
        cout << "             PHOTGEN  ++                " << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Cargar Imagen" << endl;
        cout << "2. Seleccionar Imagen" << endl;
        cout << "3. Aplicar Filtro" << endl;
        cout << "4. Edicion Manual" << endl;
        cout << "5. Exportar Imagen" << endl;
        cout << "6. Reportes" << endl;
        cout << "7. Salir" << endl;
        cout << "----------------------------------------" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Ingresa una opcion: ";
        
        cin >> opcPrincipal;
        limpiarBuffer();
        
        cout << "----------------------------------------" <<  endl << endl << endl << endl;
        
        
        if(opcPrincipal == 1){
            cargarImagen();
        }else if(opcPrincipal == 2){
            seleccionarImagen();
        }else if(opcPrincipal == 3){
            aplicarFiltro();
        }else if(opcPrincipal == 4){
            edicionManual();
        }else if(opcPrincipal == 5){
            exportarImagen();
        }else if(opcPrincipal == 6){
            reportes();
        }else if(opcPrincipal == 7){
            break;
        }else{
            opcPrincipal = 0;
        }
        
    }while(opcPrincipal != 0);
    
}

void cargarImagen(){
    
    string nombreCarpeta = "", nombreArchivo = "";
    
    cout << "----------------------------------------" << endl;
    cout << "            CARGA DE IMAGENES           " << endl;
    cout << "----------------------------------------" << endl;
    
    do{
        cout << "Ingresa el nombre de la carpeta: ";
        getline(cin, nombreCarpeta);
    }while(nombreCarpeta == "");
    
    cout << "----------------------------------------" << endl;
    
    do{
        cout << "Ingresa el nombre del archivo: ";
        getline(cin, nombreArchivo);
    }while(nombreArchivo == "");
    
    
    listaImagenes->add(new CargarImagen(nombreCarpeta, nombreArchivo));
    cout << endl << endl;
    
}


void seleccionarImagen(){
    
    cout << "----------------------------------------" << endl;
    cout << "           SELECCIONAR IMAGEN           " << endl;
    cout << "----------------------------------------" << endl;
    
    if(listaImagenes->size() == 0){
        cout << "No hay imagenes cargadas aun. "  << endl << endl << endl ;
        system("pause");
    }else{
        string* opciones = listaImagenes->getOpcionesEnOrden();
        cout << "----------------------------------------" << endl;
    
        int opcImg = 0;
        do{
            cout << "Seleccione una imagen: ";
            cin >> opcImg;
            limpiarBuffer();
            
            if(opcImg > 0 && opcImg <= listaImagenes->size()){
                cout << "Seleccionaste " << opciones[opcImg - 1] << endl;
                listaFiltros->vaciarLista();
                listaFiltros->agregar(listaImagenes->getCubo(opciones[opcImg - 1]));
            }
            
        }while(opcImg <= 0 || opcImg > listaImagenes->size());
        
        
        
        cout << endl << endl << endl;
    }
    
}


void aplicarFiltro(){
    
    cout << "----------------------------------------" << endl;
    cout << "             APLICAR FILTROS            " << endl;
    cout << "----------------------------------------" << endl;
    
    if(listaFiltros->getLength() == 0){
        cout << "No ha seleccionado una imagen aun. "  << endl << endl << endl ;
        system("pause");
    }else{
    
        cout << "1. Negativo" << endl;
        cout << "2. Escala de Grises" << endl;
        cout << "3. Espejo X" << endl;
        cout << "4. Espejo Y" << endl;
        cout << "5. Doble Espejo" << endl;
        cout << "6. Collage" << endl;
        cout << "7. Mosaico" << endl;
        cout << "8. Regresar" << endl;
        cout << "----------------------------------------" << endl;
        
        int opcFiltro = 0;
        
        do{
            
            cout << "Ingresa el filtro: ";
            cin >> opcFiltro;
            limpiarBuffer();
            
            if(opcFiltro == 1){
    
                cout << "----------------------------------------" << endl;
                cout << "1. Filtro a Imagen Completa" << endl;
                cout << "2. Filtro a Capa Especifica" << endl;
    
                CuboOrtogonal* img = listaFiltros->getCopiaImagenOriginal();
                int negOpc = 0;
                
                do{
                    cout << "--->Seleccione una opcion: " ;
                    cin >> negOpc;
                    limpiarBuffer();
                    
                    if(negOpc == 1){
                        listaFiltros->agregar("negativo",img);
                        system("pause");
                    }else if(negOpc == 2){
                        NodoZ* aux = img->getCabeza()->getSiguiente();
                        
                        while(aux != NULL){
                            cout << "----------------------------------------" << endl;
                            cout << aux->getZ()  <<". Capa " << aux->getZ()  << endl;
                            aux = aux->getSiguiente();
                        }
    
                        
                        int capa = 0;
                        
                        do{
                            cout << "--->Seleccione una capa: " ;
                            cin >> capa;
                            limpiarBuffer();
                            
                            if(img->existeZ(capa) != true){
                                capa = 0;
                            }else{
                                NodoZ* modCapa = img->getNodeZ(capa);
                                modCapa->getMatriz()->filtroNegativo();
                                string nombreFiltro = "negativo_" + to_string(capa);
                                listaFiltros->agregar(nombreFiltro, img);
                                cout << endl << "Filtro Negativo Aplicado" << endl << endl;
                                system("pause");
                            }
                            
                        }while(capa == 0);
                        
                        
                    }else{
                        negOpc = 0;
                    }
                    
                }while(negOpc == 0);
            }
            
            if(opcFiltro == 2){
    
                cout << "----------------------------------------" << endl;
                cout << "1. Filtro a Imagen Completa" << endl;
                cout << "2. Filtro a Capa Especifica" << endl;
    
                CuboOrtogonal* img2 = listaFiltros->getCopiaImagenOriginal();
                int negOpc2 = 0;
    
                do{
                    cout << "--->Seleccione una opcion: " ;
                    cin >> negOpc2;
                    limpiarBuffer();
        
                    if(negOpc2 == 1){
                        listaFiltros->agregar("grises",img2);
                        cout << endl << "Filtro Escala de Grises Aplicado" << endl << endl;
                        system("pause");
                    }else if(negOpc2 == 2){
                        NodoZ* aux = img2->getCabeza()->getSiguiente();
            
                        while(aux != NULL){
                            cout << "----------------------------------------" << endl;
                            cout << aux->getZ()  <<". Capa " << aux->getZ()  << endl;
                            aux = aux->getSiguiente();
                        }
            
            
                        int capa = 0;
            
                        do{
                            cout << "--->Seleccione una capa: " ;
                            cin >> capa;
                            limpiarBuffer();
                
                            if(img2->existeZ(capa) != true){
                                capa = 0;
                            }else{
                                NodoZ* modCapa = img2->getNodeZ(capa);
                                modCapa->getMatriz()->filtroEscalaGrises();
                                string nombreFiltro = "grises_" + to_string(capa);
                                listaFiltros->agregar(nombreFiltro, img2);
                                cout << endl << "Filtro Escala de Grises Aplicado" << endl << endl;
                                system("pause");
                            }
                
                        }while(capa == 0);
            
            
                    }else{
                        negOpc2 = 0;
                    }
        
                }while(negOpc2 == 0);
                
                //img2->generarImagen();
            }
    
    
            if(opcFiltro == 3){
        
                CuboOrtogonal* img = listaFiltros->getCopiaImagenOriginal();
                listaFiltros->agregar("espejox",img);
                cout << endl << "Filtro Espejo en X Aplicado Correctamente " << endl << endl;
    
                system("pause");
                
                //img->generarImagen();
                
            }
    
    
            if(opcFiltro == 4){
        
                CuboOrtogonal* img = listaFiltros->getCopiaImagenOriginal();
                listaFiltros->agregar("espejoy",img);
                cout << endl << "Filtro Espejo en Y Aplicado Correctamente " << endl << endl;
    
                system("pause");
                
                //img->generarImagen();
        
            }
    
            if(opcFiltro == 5){
        
                CuboOrtogonal* img = listaFiltros->getCopiaImagenOriginal();
                listaFiltros->agregar("doble",img);
                cout << endl << "Filtro Doble Espejo Aplicado Correctamente " << endl << endl;
    
                system("pause");
                
                //img->generarImagen();
        
            }
    
            //COLLAGE
            if(opcFiltro == 6){
        
                CuboOrtogonal* img = listaFiltros->getCopiaImagenOriginal();
                listaFiltros->agregar("collage",img);
                cout << endl << "Filtro Collage Aplicado Correctamente " << endl << endl;
    
                system("pause");
                
                //img->generarCollage();
        
            }
            
            //MOSAICO
            if(opcFiltro == 7){
        
                CuboOrtogonal* img = listaFiltros->getCopiaImagenOriginal();
                listaFiltros->agregar("mosaico",img);
                cout << endl << "Filtro Mosaico Aplicado Correctamente " << endl << endl;
                
                system("pause");
                
            }
            
            //SALIR DE LOS FILTROS
            if(opcFiltro == 8){
                break;
            }
            
            
        }while(opcFiltro <= 0 || opcFiltro > 7);
        
        cout << endl << endl << endl;
    }
    
}


void exportarImagen(){
    cout << "----------------------------------------" << endl;
    cout << "           EXPORTAR IMAGENES            " << endl;
    cout << "----------------------------------------" << endl;
    
    if(listaFiltros->getLength() == 0){
        cout << "No ha seleccionado una imagen aun. "  << endl << endl << endl ;
        system("pause");
    }else{
        NodoCircular* imagenes = listaFiltros->getCabeza();
        int size = 1;
        
        while(size <= listaFiltros->getLength()){
            cout << size << ". " << imagenes->getFiltro() << endl;
            imagenes = imagenes->getSiguiente();
            size++;
        }
    
        cout << size << ". Salir" << endl;
        cout << "----------------------------------------" << endl;
        
        int opc = 0;
        do{
            cout << "Seleccione la imagen a exportar: " << endl;
            cin >> opc;
            
            if(opc > 0 && opc <= (listaFiltros->getLength() + 1)){
                if(opc == size){
                    break;
                }else{
                    listaFiltros->generarImagen(opc);
                    system("pause");
                }
            }else{
                opc = 0;
            }
            
        }while(opc == 0);
    }
    
    cout << endl << endl;
    
}

void edicionManual(){

}

void reportes(){
    cout << "----------------------------------------" << endl;
    cout << "           REPORTES GRAPHVIZ            " << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Reporte Imagenes Importadas" << endl;
    cout << "2. Reporte Capas de Imagenes Importadas" << endl;
    cout << "3. Reporte Matriz Linealizada de Imagenes Importadas" << endl;
    cout << "4. Reporte Recorridos Imagenes Importadas (Traversal)" << endl;
    cout << "5. Reporte de Filtros de Imagenes Importadas" << endl;
    cout << "6. Salir" << endl;
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;
    
    int opc = 0;
    
    do{
        cout << "Seleccione un reporte: ";
        cin >> opc;
        
        if(opc == 1){
            listaImagenes->graficarABB();
        }else if(opc == 2){
    
            if(listaImagenes->size() == 0){
                cout << "No hay imagenes cargadas aun. "  << endl << endl << endl ;
                system("pause");
            }else{
                cout << "----------------------------------------" << endl;
                string* opciones = listaImagenes->getOpcionesEnOrden();
                cout << "----------------------------------------" << endl;
        
                int opcImg = 0;
                do{
                    cout << "Seleccione una imagen: ";
                    cin >> opcImg;
                    limpiarBuffer();
            
                    if(opcImg > 0 && opcImg <= listaImagenes->size()){
                        cout << "----------------------------------------" << endl;
                        cout << "Seleccionaste " << opciones[opcImg - 1] << endl;
                        cout << "----------------------------------------" << endl;
                        CuboOrtogonal* imagen = listaImagenes->getCubo(opciones[opcImg - 1]);
                        imagen->generateMatrix();
                        NodoZ* aux = imagen->getCabeza();
                        
                        while(aux != NULL){
                            if(aux->getZ() == 0){
                                cout << aux->getZ() << ". Cubo Completo" << endl;
                            }else{
                                cout << aux->getZ() << ". Capa " << aux->getZ() << endl;
                            }
                            aux = aux->getSiguiente();
                        }
    
                        int opcGrap = -1;
                        do {
                            cout << "Seleccione la capa a graficar: ";
                            cin >> opcGrap;
                            limpiarBuffer();
                            
                            if(imagen->existeZ(opcGrap) == true){
                                MatrizOrtogonal* m = imagen->getNodeZ(opcGrap)->getMatriz();
                                m->graficar(imagen->getNombre(), opcGrap);
                                break;
                            }else{
                                opcGrap = -1;
                            }
                            
                        }while(opcGrap == -1);
                        
                    }else{
                        opcImg == 0;
                    }
            
                }while(opcImg < 0 || opcImg > listaImagenes->size());
        
        
        
                cout << endl << endl << endl;
            }
    
        }else if(opc == 3){
    
        }else if(opc == 4){
    
            cout << "----------------------------------------" << endl;
            cout << "1. Reporte en Orden" << endl;
            cout << "2. Reporte en Pre-Orden" << endl;
            cout << "3. Reporte en Post-Orden" << endl;
            cout << "4. Salir" << endl;
            
            int opcR = 0;
            
            do {
                cout << "Seleccione un reporte: ";
                cin >> opcR;
                limpiarBuffer();
                
                if(opcR == 1){
                   listaImagenes->graficarEnOrden();
                }else if(opcR == 2){
                    listaImagenes->graficarPreOrden();
                }else if(opcR == 3){
                    listaImagenes->graficarPostOrden();
                }else if(opcR == 4){
                    break;
                }else{
                    opcR = 0;
                }
                
            }while(opcR == 0);
            
            
        }else if(opc == 5){
    
        }else if(opc == 6){
            break;
        }else{
            opc = 0;
        }
        
    }while(opc == 0);
    
    
}



void limpiarBuffer(){
    while ((getchar()) != '\n');
}