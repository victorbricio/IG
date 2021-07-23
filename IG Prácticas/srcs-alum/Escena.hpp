#ifndef ESCENA_HPP
#define ESCENA_HPP

#include "matrizg.hpp"
#include "matrices-tr.hpp"
#include "NodoGrafoEscena.hpp"
#include "NodoGrafoEscenaParam.hpp"
#include "Parametro.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"
#include "tuplasg.hpp"

class Escena : public NodoGrafoEscena{
public:
  Escena();
};

class Peones : public NodoGrafoEscena{
public:
  Peones();
};

class CocaCola : public NodoGrafoEscena{
public:
  CocaCola();
};

#endif
