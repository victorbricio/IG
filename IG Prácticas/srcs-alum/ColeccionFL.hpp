#ifndef COLECCIONFL_HPP
#define COLECCIONFL_HPP

#include <vector>
#include "FuenteLuz.hpp"

using namespace std;

class ColeccionFL{
public:
  vector<FuenteLuz *> fuentes;     //vector de las fuentes de luz
  void activar();                  //activa todas las fuentes de luz
  void desactivar();               //desactiva todas las fuentes de luz
};


class ColeccionFuentesP4 : public ColeccionFL{
public:
  ColeccionFuentesP4();
};

#endif
