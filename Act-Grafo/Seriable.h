#ifndef SERIABLE_H_INCLUDED
#define SERIABLE_H_INCLUDED

#include <fstream>

using namespace std;

class CSeriable{
public:
virtual int getCLSID() = 0;
virtual void guardar(fstream& out) = 0;
virtual void cargar(fstream& in) = 0;

virtual void imprimir() = 0;

};

CSeriable* Seriablefactory(int CLSID);

#endif // SERIABLE_H_INCLUDED
