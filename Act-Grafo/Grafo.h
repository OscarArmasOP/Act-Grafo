#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

#include "Seriable.h"

#define CLSID_EDGE 159357
#define CLSID_VERTEX 852456
#define CLSID_GRAPH 159123

using namespace std;

class Arista;

class Vertice : public CSeriable{
    private:
        Vertice* sig; ///Siguiente vertice
        Arista* ady; /// Arista adyacente
        std::string nombre; /// Identificador
        int total, comida, museos, l_Historicos, tradiciones, hospedaje;
    public:
        void setTotal();
        void setComida(const int&);
        void setMuseos(const int&);
        void setL_Historicos(const int&);
        void setTradiciones(const int&);
        void setHospedaje(const int&);
        void setNombre(std::string&);

        int getTotal();
        int getComida();
        int getMuseos();
        int getL_Historicos();
        int getTradiciones();
        int getHospedaje();
        std::string getNombre();

        virtual int getCLSID();
        virtual void guardar(fstream& out);
        virtual void cargar(fstream& in);

        virtual void imprimir();

        friend class Grafo; ///EL grafo puedo manejar lo privado
    };

class Arista : public CSeriable{
    private:
        Arista* sig; ///Siguiente arista
        Vertice* ady; ///Vertice adyacente
        double kilometros, gas, peligrosidad, seguridad, tiempo, total; /// Peso
    public:
        double getKM();
        void setKM(const double&);

        double getGas();
        void setGas(const double&);

        double getPeligrosidad();
        void setPeligrosidad(const double&);

        double getSeguridad();
        void setSeguridad(const double&);

        double getTiempo();
        void setTiempo(const double&);

        double getTotal();
        void setTotal();

        virtual int getCLSID();
        virtual void guardar(fstream& out);
        virtual void cargar(fstream& in);

        virtual void imprimir();

        friend class Grafo; ///El grafo puedo manejar lo privado

    };

class Grafo : public CSeriable{
    private:
        Vertice* h;
    public:
        void inicializa();

        bool isEmpty();
        bool existVertex(std::string auxVer);
        bool existAri(std::string& origen, std::string& destino);

        int getSize();
        int getAri();

        Vertice* getVertice(std::string nombre);

        void insertarArista(Vertice* origen, Vertice* destino, double km, double gas, double pl, double sg, double time);
        void insertarArista2(Vertice* origen, Vertice* destino, Arista* nueva);

        void insertarVertice(std::string nombre, int cm, int ms, int lh, int td, int hp);
        void insertarVertice2(Vertice* nuevo);

        void listaAdyacencia();
        void eliminarArista(Vertice* origen, Vertice* destino);
        void anular();
        void eliminarVertice(Vertice* vertex);

        virtual int getCLSID();
        virtual void guardar(fstream& out);
        virtual void cargar(fstream& in);

        virtual void imprimir();

        void guardarEdge(fstream& out);
        void cargarC(fstream& in);
    };

#endif // GRAFO_H_INCLUDED
