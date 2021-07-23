#ifndef MATERIALESTANDAR_HPP
#define MATERIALESTANDAR_HPP

#include "Material.hpp"
#include "Textura.hpp"
#include "aux.hpp"
#include "tuplasg.hpp"


class MaterialEstandar : public Material{
public:
  Textura * textura;                 // puntero a textura (NULL si no hay)
  Tupla4f color[4];                  // 0=M E , 1=M A , 2=M D , 3=M S
  float exponente;                   // exponente (e)

  virtual void activar();
};

class MaterialLata : public MaterialEstandar{
public:
  MaterialLata () ;
};

class MaterialTapasLata : public MaterialEstandar{
public:
  MaterialTapasLata () ;
};

class MaterialPeonMadera : public MaterialEstandar{
public:
  MaterialPeonMadera () ;
};

class MaterialPeonBlanco : public MaterialEstandar{
public:
  MaterialPeonBlanco () ;
};

class MaterialPeonNegro : public MaterialEstandar{
public:
  MaterialPeonNegro () ;
};

class MaterialSol : public MaterialEstandar{
public:
  MaterialSol () ;
};

class MaterialTierra : public MaterialEstandar{
public:
  MaterialTierra () ;
};

class MaterialMarte : public MaterialEstandar{
public:
  MaterialMarte () ;
};

class MaterialLuna : public MaterialEstandar{
public:
  MaterialLuna () ;
};

class MaterialFobos : public MaterialEstandar{
public:
  MaterialFobos () ;
};

class MaterialDeimos : public MaterialEstandar{
public:
  MaterialDeimos () ;
};

#endif
