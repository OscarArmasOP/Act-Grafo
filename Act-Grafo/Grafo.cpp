#include "Grafo.h"
#include <iomanip>

using namespace std;

void Grafo::inicializa() {
    h = nullptr;
    }

bool Grafo::isEmpty() {
    return h == nullptr;
    }

int Grafo::getSize() {
    int contador = 0;
    Vertice* aux = h;

    while(aux != nullptr) {
        contador++;
        aux = aux->sig;
        }
    return contador;
    }

int Grafo::getAri() {
    int contador = 0;
    Vertice* vertAux;
    Arista* arisAux;

    vertAux = h;

    while(vertAux != nullptr) { ///Recorrer todos los vertices
        arisAux = vertAux->ady;

        while(arisAux != nullptr) { /// Reocrrer todas las aristas de ese vertice
            contador++;
            arisAux = arisAux->sig;
            }
        vertAux = vertAux->sig;
        }
    return contador;
    }


Vertice* Grafo::getVertice(string nombre) {
    Vertice* aux = h;

    while(aux != nullptr) {
        if(aux->nombre == nombre) {
            return aux;
            }

        aux = aux->sig;
        }
    return nullptr;
    }

bool Grafo::existVertex(std::string auxVer) {
    Vertice* aux = h;

    while(aux != nullptr) {
        if(aux->nombre == auxVer) {
            return true;
            }

        aux = aux->sig;
        }
    return false;
    }

bool Grafo::existAri(std::string& origen, std::string& destino) {
    Vertice* vertAux;
    Arista* arisAux;

    vertAux = h;

    while(vertAux != nullptr) { ///Recorrer todos los vertices
        arisAux = vertAux->ady;

        while(arisAux != nullptr) { /// Reocrrer todas las aristas de ese vertice
            if(origen == vertAux->getNombre() and destino == arisAux->ady->getNombre()) {
                return true;
                }
            arisAux = arisAux->sig;
            }
        vertAux = vertAux->sig;
        }
    return false;
    }

void Grafo::insertarArista(Vertice* origen, Vertice* destino, double km, double gas, double pl, double sg, double time) {
    Arista* nueva = new Arista;
    nueva->setKM(km);
    nueva->setGas(gas);
    nueva->setPeligrosidad(pl);
    nueva->setSeguridad(sg);
    nueva->setTiempo(time);
    nueva->ady = nullptr;
    nueva->sig = nullptr;

    Arista* aux = origen->ady;

    if(aux == nullptr) {
        origen->ady = nueva;
        nueva->ady = destino;
        }
    else {
        while(aux->sig != nullptr) {
            aux = aux->sig;
            }
        aux->sig = nueva;
        nueva->ady = destino;
        }
    }

void Grafo::insertarVertice(string nombre, int cm, int ms, int lh, int td, int hp) {
    Vertice* nuevo = new Vertice;

    nuevo->nombre = nombre;
    nuevo->setComida(cm);
    nuevo->setMuseos(ms);
    nuevo->setL_Historicos(lh);
    nuevo->setTradiciones(td);
    nuevo->setHospedaje(hp);
    nuevo->sig = nullptr;
    nuevo->ady = nullptr;

    if(isEmpty()) {
        h = nuevo;
        }
    else {
        Vertice* aux = h;

        while(aux->sig != nullptr) {
            aux = aux->sig;
            }
        aux->sig = nuevo;
        }
    }

void Grafo::listaAdyacencia() {
    Vertice* vertAux;
    Arista* arisAux;

    vertAux = h;

    while(vertAux != nullptr) { ///Recorrer todos los vertices

        cout << vertAux->nombre << "->";
        arisAux = vertAux->ady;

        while(arisAux != nullptr) { /// Reocrrer todas las aristas de ese vertice
            cout << arisAux->ady->nombre << "->";
            arisAux = arisAux->sig;
            }
        vertAux = vertAux->sig;
        cout << endl;
        }
    }

void Grafo::eliminarArista(Vertice* origen, Vertice* destino) {
    Arista *actual, *anterior;
    int band = 0;

    actual = origen->ady;

    if(actual == nullptr) {
        cout << "El vertice Origen no tiene vertices";
        }
    else if(actual->ady == destino) { /// Primer arista
        origen->ady =actual->sig;
        delete (&actual);
        }
    else { ///Cualquier Arista
        while(actual != nullptr) {
            if(actual->ady == destino) {
                band = 1;
                anterior->sig = actual->sig;
                delete (&actual);
                break;
                }

            anterior = actual;
            actual = actual->sig;
            }
        if(band == 0) {
            cout << "Esos vertices no estan conectados";
            }
        }
    }

void Grafo::anular() {
    Vertice* aux;

    while(h != nullptr) {
        aux = h;
        h = h->sig;
        delete (&aux);
        }
    }

void Grafo::eliminarVertice(Vertice* vertex) {
    Vertice *actual, *anterior;
    Arista* aux;

    actual = h;

    while(actual != nullptr) { /// Se eliminan las conexiones de otros vertices con el que queremos eliminar
        aux = actual->ady;

        while(aux != nullptr) { /// Recorrer aristas del vertice
            if(aux->ady == vertex) {
                eliminarArista(actual, aux->ady);
                break;
                }
            aux = aux->sig;
            }

        actual = actual->sig;
        }
    /// Aqui termina el recorrido para eliminar las conexiones de otros vertices con el que queremos eliminar

    actual = h;
    if(h == vertex) { /// Si el vertice a eliminar es el primero
        h = h->sig;
        delete (&actual);
        }
    else { ///Cualquier vertice
        while(actual != vertex) {
            anterior = actual;
            actual = actual->sig;
            } /// Sebusca el vertice a eliminar

        anterior->sig = actual->sig; ///Se religan los vertices
        delete (&actual);
        }
    }

void Vertice::setNombre(std::string& name) {
    nombre = name;
    }

void Vertice::setTotal() {
total = this->getComida();
    total += this->getMuseos();
    total += this->getL_Historicos();
    total += this->getTradiciones();
    total += this->getHospedaje();
    }

void Vertice::setComida(const int& com) {
    comida = com;
    }

void Vertice::setMuseos(const int& mus) {
    museos = mus;
    }

void Vertice::setL_Historicos(const int& lh) {
    l_Historicos = lh;
    }

void Vertice::setTradiciones(const int& trd) {
    tradiciones = trd;
    }

void Vertice::setHospedaje(const int& hos) {
    hospedaje = hos;
    }

int Vertice::getTotal() {
    return total;
    }

int Vertice::getComida() {
    return comida;
    }

int Vertice::getMuseos() {
    return museos;
    }

int Vertice::getL_Historicos() {
    return l_Historicos;
    }

int Vertice::getTradiciones() {
    return tradiciones;
    }

int Vertice::getHospedaje() {
    return hospedaje;
    }

int Vertice::getCLSID() {
    return CLSID_VERTEX;
    }

string Vertice::getNombre() {
    return nombre;
    }

void Vertice::guardar(fstream& out) {
    out << getCLSID() << endl;
    out << this->getNombre() << endl;
    out << getComida() << endl;
    out << getMuseos() << endl;
    out << getL_Historicos() << endl;
    out << getTradiciones() << endl;
    out << getHospedaje() << endl;
    }

void Vertice::cargar(fstream& in) {
    int aux;
    string sAux;

    in >> sAux;
    setNombre(sAux);

    in >> aux;
    setComida(aux);

    in >> aux;
    setMuseos(aux);

    in >> aux;
    setL_Historicos(aux);

    in >> aux;
    setTradiciones(aux);

    in >> aux;
    setHospedaje(aux);
    }

void Vertice::imprimir() {
    cout << getComida() << setw(10) << getMuseos() << setw(10) << getL_Historicos() << setw(10)
         << getTradiciones() << setw(10) << getHospedaje()<< endl;
    }

double Arista::getKM() {
    return kilometros;
    }

void Arista::setKM(const double& km) {
    kilometros = km;
    }

double Arista::getGas() {
    return gas;
    }

void Arista::setGas(const double& gs) {
    gas = gs;
    }

double Arista::getPeligrosidad() {
    return peligrosidad;
    }

void Arista::setPeligrosidad(const double& pl) {
    peligrosidad = pl;
    }

double Arista::getSeguridad() {
    return seguridad;
    }

void Arista::setSeguridad(const double& sg) {
    seguridad = sg;
    }

double Arista::getTiempo() {
    return tiempo;
    }

void Arista::setTiempo(const double& time) {
    tiempo = time;
    }

double Arista::getTotal() {
    return total;
    }

void Arista::setTotal() {
    total = getKM();
    total+= getGas();
    total+= getSeguridad();
    total+= getTiempo();
    }

int Arista::getCLSID() {
    return CLSID_EDGE;
    }

void Arista::guardar(fstream& out) {
    out << getCLSID() << endl;
    out << getKM() << endl;
    out << getGas() << endl;
    out << getPeligrosidad() << endl;
    out << getSeguridad() << endl;
    out <<  getTiempo() << endl;
    }

void Arista::cargar(fstream& in) {
    double aux;
    in >> aux;
    setKM(aux);

    in >> aux;
    setGas(aux);

    in >> aux;
    setPeligrosidad(aux);

    in >> aux;
    setSeguridad(aux);

    in >> aux;
    setTiempo(aux);
    }

void Arista::imprimir() {

    cout << getKM() << setw(10) << getGas() << setw(10) << getPeligrosidad() << setw(10)
         << getSeguridad() << setw(10) << getTiempo()<< endl;
    }

void Grafo::insertarVertice2(Vertice* nuevo) {


    nuevo->sig = nullptr;
    nuevo->ady = nullptr;

    if(isEmpty()) {
        h = nuevo;
        }
    else {
        Vertice* aux = h;

        while(aux->sig != nullptr) {
            aux = aux->sig;
            }
        aux->sig = nuevo;
        }
    }

void Grafo::insertarArista2(Vertice* origen, Vertice* destino, Arista* nueva) {
    nueva->ady = nullptr;
    nueva->sig = nullptr;

    Arista* aux = origen->ady;

    if(aux == nullptr) {
        origen->ady = nueva;
        nueva->ady = destino;
        }
    else {
        while(aux->sig != nullptr) {
            aux = aux->sig;
            }
        aux->sig = nueva;
        nueva->ady = destino;
        }
    }

int Grafo::getCLSID() {
    return CLSID_GRAPH;
    }

void Grafo::guardar(fstream& out) {
    out << CLSID_GRAPH << endl;
    out << this->getSize() << endl;

    Vertice* vertAux;

    vertAux = h;

    while(vertAux != nullptr) { ///Recorrer todos los vertices

        vertAux->guardar(out);

        vertAux = vertAux->sig;
        }
    }

void Grafo::cargar(fstream& in) {
    int myInt, CLSID(0);
    string myStr;

    in >> myInt;

    for(int i = 0; i < myInt; i++) {
        in >> CLSID;

        if(CLSID == CLSID_VERTEX) {
            Vertice* nuevo = new Vertice;
            nuevo->cargar(in);
            if(!this->existVertex(nuevo->getNombre())) {
                this->insertarVertice2(nuevo);
                }
            }
        }
    cout << "Se completo el proceso de carga de ciudades" << endl;
    }

void Grafo::guardarEdge(fstream& out) {
    Vertice* vertAux;
    Arista* arisAux;

    vertAux = h;

    out << this->getAri() << endl;

    while(vertAux != nullptr) { ///Recorrer todos los vertices

        arisAux = vertAux->ady;

        while(arisAux != nullptr) { /// Reocrrer todas las aristas de ese vertice
            out << vertAux->getNombre() << endl;
            out << arisAux->ady->getNombre() << endl;
            arisAux->guardar(out);
            arisAux = arisAux->sig;
            }
        vertAux = vertAux->sig;
        }
    }

void Grafo::cargarC(fstream& in) {
    string myStr, destino;
    int myInt, aux;

    in >> aux;

    for(int i = 0; i < aux; i++) {
        in >> myStr;
        in >> destino;

        Vertice *myVertex1, *myVertex2;
        myVertex1 = this->getVertice(myStr);
        myVertex2 = this->getVertice(destino);

        in >> myInt;

        if(myInt == CLSID_EDGE) {
            Arista* nueva1 = new Arista;
            nueva1->cargar(in);
            this->insertarArista2(myVertex1, myVertex2, nueva1);

            }
        }
    }

void Grafo::imprimir() {
    Vertice* vertAux;
    Arista* arisAux;

    vertAux = h;

    while(vertAux != nullptr) { ///Recorrer todos los vertices

        cout << vertAux->nombre << "->";
        arisAux = vertAux->ady;

        while(arisAux != nullptr) { /// Reocrrer todas las aristas de ese vertice
            cout << arisAux->ady->nombre << "->";
            arisAux = arisAux->sig;
            }
        vertAux = vertAux->sig;
        cout << endl;
        }
    }
