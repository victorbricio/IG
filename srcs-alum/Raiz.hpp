#ifndef RAIZ_HPP
#define RAIZ_HPP

#include "NodoGrafoEscenaParam.hpp"
#include "Parametro.hpp"
#include "matrices-tr.hpp"

class Raiz : public NodoGrafoEscenaParam{
public:
  Raiz();
};

class Astro : public NodoGrafoEscena{
public:
  Astro(int p);
};

class Sistema : public NodoGrafoEscena{
public:
  Sistema(float t, float e, int subsistemas, bool marte, bool fobos);
};

#endif
