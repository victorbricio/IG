#ifndef NODOGRAFOESCENAPARAM_HPP
#define NODOGRAFOESCENAPARAM_HPP

#include "NodoGrafoEscena.hpp"
#include "Parametro.hpp"
#include <vector>

class NodoGrafoEscenaParam : public NodoGrafoEscena {
protected:
  std::vector<Parametro> parametros;

public:
  int numParametros();

  Parametro * leerPtrParametro (unsigned i);

  void siguienteCuadro();
};

#endif
