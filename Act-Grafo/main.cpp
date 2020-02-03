//Oscar Martinez Armas
#include <iostream>

#include "Grafo.h"

using namespace std;

int main() {
    Grafo g;
    g.inicializa();

    fstream salida1, salida2;
    fstream entrada1, entrada2;

    int CLSID;
    entrada1.open("Grafo_Mapa.txt", ios_base::in);
    entrada2.open("Grafo_Edge.txt", ios_base::in);

    entrada1 >> CLSID;

    if(CLSID == CLSID_GRAPH) {
        g.cargar(entrada1);

        g.imprimir();
        }
    entrada1.close();

    cout << endl << endl;

    g.cargarC(entrada2);
    g.imprimir();
    cout << "Se completo la carga de carreteras" << endl;
    system("pause");
    entrada2.close();

    int opc, aux;
    double auxD;

    string nombre, origen, destino;

    do {
        system("cls");

        cout << "Bienvenido a la agencia GLAM" << endl << endl;

        cout << " 1.- Agregar Ciudad" << endl; /// Vertice
        cout << " 2.- Agregar Carretera" << endl; /// Arista
        cout << " 3.- Eliminar Ciudad" << endl; ///vertice
        cout << " 4.- Eliminar Carretera" << endl; /// Arista
        cout << " 5.- Lista de Adyacencia" << endl;
        cout << " 6.- Tamanio del mapa" << endl;
        cout << " 0.- Salir" << endl << endl;

        cout << "Elige una opcion: ";
        cin >> opc;
        switch(opc) {
            case 1:
                system("cls");
                cin.ignore();

                cout << "Ingrese el nombre de la ciudad: ";
                getline(cin, nombre);

                if(!g.isEmpty()) {
                    if(g.getVertice(nombre) == nullptr) {
                        Vertice* nuevo = new Vertice;
                        nuevo->setNombre(nombre);

                        cout << "Ingrese la calidad de la comida en " << nombre << ": ";
                        cin >> aux;
                        nuevo->setComida(aux);
                        cin.ignore();

                        cout << "Ingrese la calidad de los museos en " << nombre << ": ";
                        cin >> aux;
                        nuevo->setMuseos(aux);
                        cin.ignore();

                        cout << "Ingrese la calidad de los lugares historicos en " << nombre << ": ";
                        cin >> aux;
                        nuevo->setL_Historicos(aux);
                        cin.ignore();

                        cout << "Ingrese la calidad de las tradiciones en " << nombre << ": ";
                        cin >> aux;
                        nuevo->setTradiciones(aux);
                        cin.ignore();

                        cout << "Ingrese la cantidad del hospedaje en " << nombre << ": ";
                        cin >> aux;
                        nuevo->setHospedaje(aux);
                        cin.ignore();

                        g.insertarVertice2(nuevo);
                        }
                    else {
                        cout << "Ciudad ya existente" << endl;
                        system("pause");
                        break;
                        }
                    }
                else {
                    Vertice* nuevo = new Vertice;
                    nuevo->setNombre(nombre);

                    cout << "Ingrese la calidad de la comida en " << nombre << ": ";
                    cin >> aux;
                    nuevo->setComida(aux);
                    cin.ignore();

                    cout << "Ingrese la calidad de los museos en " << nombre << ": ";
                    cin >> aux;
                    nuevo->setMuseos(aux);
                    cin.ignore();

                    cout << "Ingrese la calidad de los lugares historicos en " << nombre << ": ";
                    cin >> aux;
                    nuevo->setL_Historicos(aux);
                    cin.ignore();

                    cout << "Ingrese la calidad de las tradiciones en " << nombre << ": ";
                    cin >> aux;
                    nuevo->setTradiciones(aux);
                    cin.ignore();

                    cout << "Ingrese la cantidad del hospedaje en " << nombre << ": ";
                    cin >> aux;
                    nuevo->setHospedaje(aux);
                    cin.ignore();


                    g.insertarVertice2(nuevo);
                    }

                cout << "Ciudad " << nombre << " agregada con exito" << endl;

                system("pause");
                break;
            case 2:
                system("cls");
                cin.ignore();

                if(g.isEmpty()) {
                    cout << "Mapa vacio" << endl;
                    system("pause");
                    break;
                    }
                else {
                    cout << "Ingrese el nombre de la ciudad origen: ";
                    getline(cin, origen);

                    cout << "Ingrese el nombre de la ciudad destino: ";
                    getline(cin, destino);

                    if(g.getVertice(origen) == nullptr or g.getVertice(destino) == nullptr) {
                        cout << "Alguna de las ciudades no exite, favor de comprobar" << endl;
                        system("pause");
                        break;
                        }
                    else {
                        Arista* nueva = new Arista;
                        Arista* nueva2 = new Arista;

                        cout << "Ingrese los Kilometros: ";
                        cin >> auxD;

                        nueva->setKM(auxD);
                        nueva2->setKM(auxD);
                        cin.ignore();

                        cout << "Ingrese el gas a utilizar: ";
                        cin >> auxD;
                        nueva->setGas(auxD);
                        nueva2->setGas(auxD);
                        cin.ignore();

                        cout << "Ingrese la seguridad de la carretera: ";
                        cin >> auxD;
                        nueva->setSeguridad(auxD);
                        nueva2->setSeguridad(auxD);
                        cin.ignore();

                        cout << "Ingrese el tiempo: ";
                        cin >> auxD;
                        nueva->setTiempo(auxD);
                        nueva2->setTiempo(auxD);
                        cin.ignore();

                        cout << "Ingrese la peligrosidad: ";
                        cin >> auxD;
                        nueva->setPeligrosidad(auxD);
                        nueva2->setPeligrosidad(auxD);
                        cin.ignore();


                        g.insertarArista2(g.getVertice(origen), g.getVertice(destino), nueva);
                        g.insertarArista2(g.getVertice(destino), g.getVertice(origen), nueva2);
                        cout << "Carretera agregada con exito" << endl;
                        }
                    }
                system("pause");
                break;
            case 3:
                system("cls");

                cin.ignore();

                if(g.isEmpty()) {
                    cout << "Mapa vacio" << endl;
                    system("pause");
                    break;
                    }
                else {
                    cout << "Ingrese el ombre de la ciudad a eliminar: ";
                    getline(cin, nombre);

                    if(g.getVertice(nombre) == nullptr) {
                        cout << "Ciudad invalida" << endl;
                        system("pause");
                        break;
                        }
                    else {
                        g.eliminarVertice(g.getVertice(nombre));
                        cout << "Ciudad eliminada exitosamente" << endl;
                        }
                    }

                system("pause");
                break;
            case 4:
                system("cls");

                cin.ignore();

                if(g.isEmpty()) {
                    cout << "Mapa vacio" << endl;
                    system("pause");
                    break;
                    }
                else {
                    cout << "Ingrese la ciudad origen: ";
                    getline(cin, origen);

                    cout << "Ingrese la ciudad destino: ";
                    getline(cin, destino);

                    if(g.getVertice(origen) == nullptr or g.getVertice(destino) == nullptr) {
                        cout << "Ciudades no conectadas" << endl;
                        system("pause");
                        break;
                        }
                    else {
                        g.eliminarArista(g.getVertice(origen), g.getVertice(destino));
                        g.eliminarArista(g.getVertice(destino), g.getVertice(origen));
                        cout << "Carretera eliminada con exito" << endl;
                        }
                    }
                system("pause");
                break;
            case 5:
                system("cls");
                cin.ignore();

                if(g.isEmpty()) {
                    cout << "Mapa vacio" << endl;
                    system("pause");
                    break;
                    }

                g.listaAdyacencia();

                system("pause");
                break;
            case 6:
                system("cls");
                cin.ignore();

                if(g.isEmpty()) {
                    cout << "Mapa vacio" << endl;
                    system("pause");
                    break;
                    }
                else {
                    if(g.getSize() == 1) {

                        cout << "Tamanio del mapa: " <<  g.getSize() << " ciudad" << endl;
                        }
                    else {


                        cout << "Tamanio del mapa: " <<  g.getSize() << " ciudades" << endl;
                        }
                    }
                system("pause");
                break;
            case 0:
                cout << "Gracias por visitarnos" << endl;
                salida1.open("Grafo_Mapa.txt", ios_base::out);
                g.guardar(salida1);
                salida1.close();

                salida2.open("Grafo_Edge.txt", ios_base::out);
                g.guardarEdge(salida2);
                salida2.close();
                break;
            default:
                break;
            }
        }
    while(opc != 0);
    return 0;
    }
