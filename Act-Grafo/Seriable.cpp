#include "Seriable.h"
#include "Grafo.h"

using namespace std;

CSeriable* Seriablefactory(int CLSID) {

    CSeriable *pSerializable = 0;

    switch(CLSID) {
        case CLSID_EDGE:
            pSerializable = new Arista;
            break;
        case CLSID_VERTEX:
            pSerializable = new Vertice;
            break;
        }

    return pSerializable;

    }
